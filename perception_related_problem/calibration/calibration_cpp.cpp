/**
 * UBER AV LABS — DEPTH IN SPECIALIZATION CODING PREP
 * C++11/14 — Calibration Problems
 * 
 * Five problems covering:
 * 1. Core math    — reprojection error, projection
 * 2. Data structs — quality gate, drift detector, ring buffer
 * 3. OOP design   — class hierarchy, RAII, interfaces
 */

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <algorithm>
#include <numeric>
#include <cassert>

// ============================================================
// MATH UTILITIES
// Simple 3D vector and 3x3 matrix — no external libs needed
// In real life: Eigen. In interview: implement cleanly.
// ============================================================

struct Vec3 {
    double x, y, z;
    Vec3(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
};

struct Vec2 {
    double u, v;
    Vec2(double u = 0, double v = 0) : u(u), v(v) {}
};

// 3x3 matrix stored row-major
struct Mat3 {
    double data[3][3];
    Mat3() { for (auto& row : data) for (auto& e : row) e = 0.0; }

    // Matrix-vector multiply
    Vec3 operator*(const Vec3& v) const {
        return Vec3(
            data[0][0]*v.x + data[0][1]*v.y + data[0][2]*v.z,
            data[1][0]*v.x + data[1][1]*v.y + data[1][2]*v.z,
            data[2][0]*v.x + data[2][1]*v.y + data[2][2]*v.z
        );
    }

    static Mat3 identity() {
        Mat3 m;
        m.data[0][0] = m.data[1][1] = m.data[2][2] = 1.0;
        return m;
    }
};

// Camera intrinsic matrix K
struct CameraIntrinsics {
    double fx, fy;   // focal lengths in pixels
    double cx, cy;   // principal point
};

// ============================================================
// PROBLEM 1: CORE MATH
// Reprojection error computation
// Most likely first question — know this cold
// ============================================================

struct ReprojectionResult {
    double mean_error;
    std::vector<double> per_point_errors;
    int skipped_points;  // points behind camera
};

/**
 * Project a single 3D world point into camera image.
 *
 * Steps:
 *   1. Transform: world → camera frame using R, t
 *   2. Check: point must be in front of camera (Z > 0)
 *   3. Project: 3D → 2D using pinhole model
 *
 * Pinhole model:
 *   u = fx * (X/Z) + cx
 *   v = fy * (Y/Z) + cy
 */
bool project_point(const Vec3& pt_world,
                   const Mat3& R,
                   const Vec3& t,
                   const CameraIntrinsics& K,
                   Vec2& out_pixel) {

    // Step 1: Transform to camera frame
    Vec3 pt_cam = R * pt_world;
    pt_cam.x += t.x;
    pt_cam.y += t.y;
    pt_cam.z += t.z;

    // Step 2: Point must be in front of camera
    if (pt_cam.z <= 0.0) {
        return false;  // behind camera — skip
    }

    // Step 3: Pinhole projection
    out_pixel.u = K.fx * (pt_cam.x / pt_cam.z) + K.cx;
    out_pixel.v = K.fy * (pt_cam.y / pt_cam.z) + K.cy;

    return true;
}

/**
 * Compute reprojection error across N point correspondences.
 *
 * Reprojection error = pixel distance between:
 *   - Where we observed the point (detected pixel)
 *   - Where our calibration says it should be (projected pixel)
 *
 * Good calibration: mean error < 0.5 pixels
 * Acceptable:       mean error < 1.0 pixels
 * Needs recalib:    mean error > 1.5 pixels
 */
ReprojectionResult compute_reprojection_error(
    const std::vector<Vec3>& points_3d,
    const std::vector<Vec2>& points_2d,
    const Mat3& R,
    const Vec3& t,
    const CameraIntrinsics& K) {

    // Input validation — talk about this in interview
    if (points_3d.empty()) {
        throw std::invalid_argument("points_3d cannot be empty");
    }
    if (points_3d.size() != points_2d.size()) {
        throw std::invalid_argument(
            "3D and 2D point counts must match: got " +
            std::to_string(points_3d.size()) + " vs " +
            std::to_string(points_2d.size())
        );
    }

    ReprojectionResult result;
    result.skipped_points = 0;

    for (size_t i = 0; i < points_3d.size(); ++i) {
        Vec2 projected;
        if (!project_point(points_3d[i], R, t, K, projected)) {
            result.skipped_points++;
            continue;  // behind camera
        }

        // Euclidean pixel distance
        double du = projected.u - points_2d[i].u;
        double dv = projected.v - points_2d[i].v;
        double error = std::sqrt(du*du + dv*dv);

        result.per_point_errors.push_back(error);
    }

    if (result.per_point_errors.empty()) {
        result.mean_error = 0.0;
        return result;
    }

    result.mean_error = std::accumulate(
        result.per_point_errors.begin(),
        result.per_point_errors.end(), 0.0
    ) / result.per_point_errors.size();

    return result;
}

// ============================================================
// PROBLEM 2: DATA STRUCTURES
// Quality gate — filter sensor frames before calibration use
// Two-stage: hard filter (fast) then signal filter (thorough)
// ============================================================

enum class Weather { CLEAR, RAIN, SNOW, FOG };
enum class FrameQuality { GOLD, DEGRADED, REJECTED };

struct SensorFrame {
    std::string vehicle_id;
    double      timestamp;
    double      camera_brightness;     // 0–255
    double      lidar_point_density;   // points per m²
    double      vehicle_speed_mph;
    Weather     weather;
    double      landmark_confidence;   // 0.0–1.0
    bool        sensor_dropout;
};

struct QualityConfig {
    double  min_brightness        = 60.0;
    double  max_brightness        = 240.0;
    double  min_lidar_density     = 10.0;
    double  max_speed_mph         = 40.0;
    double  min_landmark_conf     = 0.90;
    bool    allow_sensor_dropout  = false;
};

struct FilterResult {
    FrameQuality quality;
    std::string  rejection_reason;  // empty if passed
};

/**
 * Two-stage quality gate.
 *
 * Stage 1 — Hard filter (fast, cheap):
 *   Reject obviously bad frames first.
 *   Binary checks, no computation needed.
 *
 * Stage 2 — Signal quality (thorough):
 *   Check if frame has useful calibration signal.
 *   Landmark visibility, point cloud density.
 *
 * Why two stages?
 *   Stage 1 rejects ~70% of frames instantly.
 *   Stage 2 only runs on remaining 30%.
 *   Saves compute at fleet scale.
 */
class QualityGate {
public:
    explicit QualityGate(const QualityConfig& config)
        : config_(config) {}

    FilterResult process(const SensorFrame& frame) const {
        // Stage 1: Hard filter
        auto hard = hard_filter(frame);
        if (hard.quality != FrameQuality::GOLD) {
            return hard;  // return REJECTED or DEGRADED immediately
        }

        // Stage 2: Signal quality (only for GOLD candidates)
        return signal_filter(frame);
    }

    // Process a batch — returns (gold, degraded, rejected)
    struct BatchResult {
        std::vector<SensorFrame> gold;
        std::vector<SensorFrame> degraded;
        std::vector<SensorFrame> rejected;
        std::unordered_map<std::string, int> rejection_counts;
    };

    BatchResult process_batch(const std::vector<SensorFrame>& frames) const {
        BatchResult result;
        for (const auto& frame : frames) {
            auto fr = process(frame);
            if (fr.quality == FrameQuality::GOLD) {
                result.gold.push_back(frame);
            } else if (fr.quality == FrameQuality::DEGRADED) {
                result.degraded.push_back(frame);
            } else {
                result.rejected.push_back(frame);
                result.rejection_counts[fr.rejection_reason]++;
            }
        }
        return result;
    }

private:
    QualityConfig config_;

    FilterResult hard_filter(const SensorFrame& frame) const {
        if (frame.sensor_dropout && !config_.allow_sensor_dropout) {
            return {FrameQuality::REJECTED, "sensor_dropout"};
        }
        if (frame.weather != Weather::CLEAR) {
            // DEGRADED not REJECTED — rain data useful for ODD analysis
            // Don't use for calibration updates but keep for condition characterization
            return {FrameQuality::DEGRADED, "adverse_weather"};
        }
        if (frame.vehicle_speed_mph > config_.max_speed_mph) {
            return {FrameQuality::REJECTED, "speed_too_high"};
        }
        if (frame.camera_brightness < config_.min_brightness ||
            frame.camera_brightness > config_.max_brightness) {
            return {FrameQuality::REJECTED, "bad_brightness"};
        }
        return {FrameQuality::GOLD, ""};
    }

    FilterResult signal_filter(const SensorFrame& frame) const {
        if (frame.lidar_point_density < config_.min_lidar_density) {
            return {FrameQuality::REJECTED, "low_lidar_density"};
        }
        if (frame.landmark_confidence < config_.min_landmark_conf) {
            return {FrameQuality::REJECTED, "low_landmark_confidence"};
        }
        return {FrameQuality::GOLD, ""};
    }
};

// ============================================================
// PROBLEM 3: OOP DESIGN
// Calibration drift detector with ring buffer
// Shows: RAII, smart pointers, template, clean interfaces
// ============================================================

/**
 * Ring buffer — fixed-size, FIFO, overwrites oldest when full.
 * Used to keep a rolling window of good observations per vehicle.
 *
 * Why ring buffer?
 *   O(1) push, O(1) pop, fixed memory — critical for on-vehicle
 *   compute where memory is constrained.
 */
template<typename T>
class RingBuffer {
public:
    explicit RingBuffer(size_t capacity)
        : capacity_(capacity), buffer_(capacity), head_(0), size_(0) {}

    void push(const T& item) {
        buffer_[head_] = item;
        head_ = (head_ + 1) % capacity_;
        if (size_ < capacity_) size_++;
    }

    size_t size()     const { return size_; }
    size_t capacity() const { return capacity_; }
    bool   empty()    const { return size_ == 0; }
    bool   full()     const { return size_ == capacity_; }

    // Access i-th element (0 = oldest)
    const T& at(size_t i) const {
        if (i >= size_) throw std::out_of_range("RingBuffer index out of range");
        size_t idx = (head_ - size_ + i + capacity_) % capacity_;
        return buffer_[idx];
    }

    // Compute mean of a member variable
    template<typename MemberFn>
    double mean(MemberFn fn) const {
        if (empty()) return 0.0;
        double sum = 0.0;
        for (size_t i = 0; i < size_; i++) sum += fn(at(i));
        return sum / size_;
    }

private:
    size_t        capacity_;
    std::vector<T> buffer_;
    size_t        head_;
    size_t        size_;
};

struct CalibrationObservation {
    std::string vehicle_id;
    double      timestamp;
    double      reprojection_error;
    std::string city;
    bool        is_clean;  // passed quality gate
};

enum class DriftStatus {
    NOMINAL,    // within baseline tolerance
    DRIFTING,   // above threshold but not sustained
    FLAGGED,    // sustained drift — needs recalibration
    SEVERE      // extreme drift — block vehicle
};

struct VehicleCalibrationState {
    DriftStatus status           = DriftStatus::NOMINAL;
    int         consecutive_count = 0;
    double      current_error    = 0.0;
    double      baseline_error   = 0.0;
};

/**
 * Fleet-wide calibration drift detector.
 *
 * Design decisions:
 *   - Per-vehicle state in unordered_map (O(1) lookup)
 *   - Ring buffer per vehicle (fixed memory, O(1) push)
 *   - Configurable thresholds (not hardcoded)
 *   - Systemic drift detection (rig vs. vehicle issue)
 *   - RAII: no manual memory management
 */
class DriftDetector {
public:
    struct Config {
        double baseline_error;
        double drift_threshold;
        double severe_threshold;
        int    sustained_window;
        size_t buffer_size;
        double systemic_pct;

        Config()
            : baseline_error(0.5)
            , drift_threshold(1.0)
            , severe_threshold(2.0)
            , sustained_window(5)
            , buffer_size(100)
            , systemic_pct(0.70) {}
    };

    explicit DriftDetector(const Config& config = Config())
        : config_(config) {}

    /**
     * Process one observation.
     * Returns the updated drift status for this vehicle.
     */
    DriftStatus process(const CalibrationObservation& obs) {
        // Only use clean data for calibration updates
        if (!obs.is_clean) return get_status(obs.vehicle_id);

        // Already severely flagged — don't update
        auto& state = vehicle_states_[obs.vehicle_id];
        if (state.status == DriftStatus::SEVERE) return DriftStatus::SEVERE;

        // Add to ring buffer
        auto& buf = get_or_create_buffer(obs.vehicle_id);
        buf.push(obs);

        // Update current error
        state.current_error = obs.reprojection_error;

        // Compute delta from baseline
        double delta = obs.reprojection_error - config_.baseline_error;

        // Severe check first
        if (delta > config_.severe_threshold) {
            state.status = DriftStatus::SEVERE;
            flagged_vehicles_.insert(obs.vehicle_id);
            return DriftStatus::SEVERE;
        }

        // Sustained drift check
        if (delta > config_.drift_threshold) {
            state.consecutive_count++;
            if (state.consecutive_count >= config_.sustained_window) {
                state.status = DriftStatus::FLAGGED;
                flagged_vehicles_.insert(obs.vehicle_id);
                return DriftStatus::FLAGGED;
            }
            state.status = DriftStatus::DRIFTING;
            return DriftStatus::DRIFTING;
        }

        // Within tolerance — reset
        state.consecutive_count = 0;
        state.status = DriftStatus::NOMINAL;
        return DriftStatus::NOMINAL;
    }

    /**
     * Detect systemic fleet-wide drift.
     * If > threshold % of vehicles are drifting — it's a rig problem,
     * not individual vehicle problems.
     */
    bool is_systemic_drift() const {
        int total    = static_cast<int>(vehicle_states_.size());
        int drifting = 0;
        for (const auto& kv : vehicle_states_) {
            if (kv.second.status == DriftStatus::DRIFTING ||
                kv.second.status == DriftStatus::FLAGGED) {
                drifting++;
            }
        }
        if (total == 0) return false;
        return (static_cast<double>(drifting) / total) >= config_.systemic_pct;
    }

    const std::unordered_set<std::string>& flagged_vehicles() const {
        return flagged_vehicles_;
    }

    DriftStatus get_status(const std::string& vehicle_id) const {
        auto it = vehicle_states_.find(vehicle_id);
        if (it == vehicle_states_.end()) return DriftStatus::NOMINAL;
        return it->second.status;
    }

    // Fleet health summary
    struct FleetStatus {
        int total_vehicles;
        int nominal_count;
        int drifting_count;
        int flagged_count;
        int severe_count;
        bool systemic_issue;
    };

    FleetStatus fleet_status() const {
        FleetStatus fs{};
        fs.total_vehicles = static_cast<int>(vehicle_states_.size());
        for (const auto& kv : vehicle_states_) {
            switch (kv.second.status) {
                case DriftStatus::NOMINAL:   fs.nominal_count++;   break;
                case DriftStatus::DRIFTING:  fs.drifting_count++;  break;
                case DriftStatus::FLAGGED:   fs.flagged_count++;   break;
                case DriftStatus::SEVERE:    fs.severe_count++;    break;
            }
        }
        fs.systemic_issue = is_systemic_drift();
        return fs;
    }

private:
    Config                                                    config_;
    std::unordered_map<std::string, VehicleCalibrationState>  vehicle_states_;
    std::unordered_map<std::string,
        RingBuffer<CalibrationObservation>>                    buffers_;
    std::unordered_set<std::string>                           flagged_vehicles_;

    RingBuffer<CalibrationObservation>&
    get_or_create_buffer(const std::string& vid) {
        auto it = buffers_.find(vid);
        if (it == buffers_.end()) {
            buffers_.emplace(vid, RingBuffer<CalibrationObservation>(config_.buffer_size));
        }
        return buffers_.at(vid);
    }
};

// ============================================================
// PROBLEM 4: DEBUGGING — fix broken calibration code
// They give you broken code. You find and fix bugs.
// ============================================================

/**
 * BUGGY VERSION — they might give you something like this.
 * Find ALL bugs before you start fixing.
 */
// double buggy_reprojection_error(
//     std::vector<std::array<double,3>> pts3d,   // Bug 1: should be const ref
//     std::vector<std::array<double,2>> pts2d,   // Bug 1: should be const ref
//     double K[3][3],
//     double R[3][3],
//     double t[3]) {
//
//     double total = 0;
//     for (int i = 0; i <= pts3d.size(); i++) {  // Bug 2: <= should be <
//         double x = R[0][0]*pts3d[i][0] + R[0][1]*pts3d[i][1] + R[0][2]*pts3d[i][2] + t[0];
//         double y = R[1][0]*pts3d[i][0] + R[1][1]*pts3d[i][1] + R[1][2]*pts3d[i][2] + t[1];
//         double z = R[2][0]*pts3d[i][0] + R[2][1]*pts3d[i][1] + R[2][2]*pts3d[i][2] + t[2];
//         // Bug 3: no check for z <= 0 (division by zero)
//         double u = K[0][0] * x / z + K[0][2];
//         double v = K[1][1] * y / z + K[1][2];
//         double du = u - pts2d[i][0];
//         double dv = v - pts2d[i][1];
//         total += du*du + dv*dv;  // Bug 4: missing sqrt (accumulating squared error)
//     }
//     return total / pts3d.size();  // Bug 5: can divide by zero if empty
// }

/**
 * FIXED VERSION — what you write after identifying all 5 bugs.
 * Narrate each fix as you make it.
 */
double fixed_reprojection_error(
    const std::vector<std::array<double,3>>& pts3d,  // Fix 1: const ref
    const std::vector<std::array<double,2>>& pts2d,  // Fix 1: const ref
    const double K[3][3],
    const double R[3][3],
    const double t[3]) {

    // Fix 5: handle empty input
    if (pts3d.empty() || pts3d.size() != pts2d.size()) return 0.0;

    double total = 0.0;
    int    valid = 0;

    for (size_t i = 0; i < pts3d.size(); ++i) {  // Fix 2: < not <=
        double x = R[0][0]*pts3d[i][0] + R[0][1]*pts3d[i][1] + R[0][2]*pts3d[i][2] + t[0];
        double y = R[1][0]*pts3d[i][0] + R[1][1]*pts3d[i][1] + R[1][2]*pts3d[i][2] + t[1];
        double z = R[2][0]*pts3d[i][0] + R[2][1]*pts3d[i][1] + R[2][2]*pts3d[i][2] + t[2];

        // Fix 3: check for point behind camera
        if (z <= 0.0) continue;

        double u = K[0][0] * x / z + K[0][2];
        double v = K[1][1] * y / z + K[1][2];
        double du = u - pts2d[i][0];
        double dv = v - pts2d[i][1];

        // Fix 4: sqrt for actual pixel distance
        total += std::sqrt(du*du + dv*dv);
        valid++;
    }

    // Fix 5: avoid divide by zero
    return valid > 0 ? total / valid : 0.0;
}

// ============================================================
// PROBLEM 5: CALIBRATION PIPELINE CLASS
// Full OOP design — clean interfaces, RAII, extensible
// ============================================================

/**
 * Abstract base: any calibration validator.
 * Open/closed principle: add new validators without changing pipeline.
 */
class CalibrationValidator {
public:
    virtual ~CalibrationValidator() = default;
    virtual bool validate(double reprojection_error,
                          double lidar_cam_agreement_cm) const = 0;
    virtual std::string name() const = 0;
};

class ReprojectionValidator : public CalibrationValidator {
public:
    explicit ReprojectionValidator(double threshold_px = 0.5)
        : threshold_(threshold_px) {}

    bool validate(double reprojection_error, double) const override {
        return reprojection_error < threshold_;
    }
    std::string name() const override { return "reprojection_error"; }

private:
    double threshold_;
};

class LidarCameraAgreementValidator : public CalibrationValidator {
public:
    explicit LidarCameraAgreementValidator(double threshold_cm = 2.0)
        : threshold_(threshold_cm) {}

    bool validate(double, double lidar_cam_agreement_cm) const override {
        return lidar_cam_agreement_cm < threshold_;
    }
    std::string name() const override { return "lidar_camera_agreement"; }

private:
    double threshold_;
};

struct CalibrationResult {
    bool        passed;
    double      reprojection_error;
    double      lidar_cam_agreement_cm;
    std::string failure_reason;  // empty if passed
};

/**
 * Calibration pipeline — owns validators, runs them in sequence.
 *
 * Design decisions:
 *   - unique_ptr for validators: clear ownership, RAII
 *   - Chain of responsibility: validators run in order, stop on first failure
 *   - Open/closed: add validators without touching pipeline
 */
class CalibrationPipeline {
public:
    // Add a validator — pipeline takes ownership
    void add_validator(std::unique_ptr<CalibrationValidator> v) {
        validators_.push_back(std::move(v));
    }

    /**
     * Run calibration pipeline.
     * Validates in order — fails fast on first failure.
     */
    CalibrationResult run(double reprojection_error,
                          double lidar_cam_agreement_cm) const {

        CalibrationResult result;
        result.reprojection_error       = reprojection_error;
        result.lidar_cam_agreement_cm   = lidar_cam_agreement_cm;

        for (const auto& validator : validators_) {
            if (!validator->validate(reprojection_error,
                                      lidar_cam_agreement_cm)) {
                result.passed         = false;
                result.failure_reason = validator->name() + "_failed";
                return result;
            }
        }

        result.passed = true;
        return result;
    }

    // Factory method: create standard pipeline
    static CalibrationPipeline make_standard_pipeline(
            double reproj_threshold = 0.5,
            double lidar_cam_threshold = 2.0) {

        CalibrationPipeline pipeline;
        pipeline.add_validator(
            std::make_unique<ReprojectionValidator>(reproj_threshold));
        pipeline.add_validator(
            std::make_unique<LidarCameraAgreementValidator>(lidar_cam_threshold));
        return pipeline;
    }

private:
    std::vector<std::unique_ptr<CalibrationValidator>> validators_;
};

// ============================================================
// TESTS — always write tests in the interview
// ============================================================

void test_reprojection_error() {
    std::cout << "\n=== Test: Reprojection Error ===\n";

    // Identity rotation, 5m forward translation
    Mat3 R = Mat3::identity();
    Vec3 t(0, 0, 5);

    // Focal length 1000px, principal point 640x360
    CameraIntrinsics K{1000, 1000, 640, 360};

    // Point at origin — should project to principal point
    std::vector<Vec3> pts3d = {Vec3(0, 0, 0)};
    std::vector<Vec2> pts2d = {Vec2(640, 360)};

    auto result = compute_reprojection_error(pts3d, pts2d, R, t, K);
    std::cout << "Mean error (expect ~0.0): " << result.mean_error << "\n";
    assert(result.mean_error < 0.001);

    // Test empty input throws
    try {
        compute_reprojection_error({}, {}, R, t, K);
        std::cout << "ERROR: should have thrown\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "Empty input correctly throws: " << e.what() << "\n";
    }

    std::cout << "PASS\n";
}

void test_quality_gate() {
    std::cout << "\n=== Test: Quality Gate ===\n";

    QualityConfig config;
    QualityGate gate(config);

    // Good frame — should pass
    SensorFrame good;
    good.vehicle_id          = "V001";
    good.timestamp           = 1000;
    good.camera_brightness   = 120;
    good.lidar_point_density = 20;
    good.vehicle_speed_mph   = 25;
    good.weather             = Weather::CLEAR;
    good.landmark_confidence = 0.95;
    good.sensor_dropout      = false;

    auto r1 = gate.process(good);
    std::cout << "Good frame (expect GOLD): "
              << (r1.quality == FrameQuality::GOLD ? "GOLD" : "FAIL") << "\n";
    assert(r1.quality == FrameQuality::GOLD);

    // Rain frame — should be degraded (not rejected — useful for ODD)
    SensorFrame rainy = good;
    rainy.weather = Weather::RAIN;
    auto r2 = gate.process(rainy);
    std::cout << "Rain frame (expect DEGRADED): "
              << (r2.quality == FrameQuality::DEGRADED ? "DEGRADED" : "FAIL") << "\n";
    assert(r2.quality == FrameQuality::DEGRADED);

    // Too fast — should be rejected
    SensorFrame fast = good;
    fast.vehicle_speed_mph = 65;
    auto r3 = gate.process(fast);
    std::cout << "Fast frame (expect REJECTED): "
              << (r3.quality == FrameQuality::REJECTED ? "REJECTED" : "FAIL") << "\n";
    assert(r3.quality == FrameQuality::REJECTED);

    std::cout << "PASS\n";
}

void test_drift_detector() {
    std::cout << "\n=== Test: Drift Detector ===\n";

    DriftDetector::Config config;
    config.drift_threshold  = 1.0;
    config.sustained_window = 3;

    DriftDetector detector(config);

    // V001: 3 consecutive drifts → FLAGGED
    for (int i = 0; i < 3; ++i) {
        CalibrationObservation obs;
        obs.vehicle_id         = "V001";
        obs.timestamp          = i * 10.0;
        obs.reprojection_error = 1.8;  // above threshold
        obs.is_clean           = true;
        detector.process(obs);
    }

    std::cout << "V001 after 3 drifts (expect FLAGGED): "
              << (detector.get_status("V001") == DriftStatus::FLAGGED
                  ? "FLAGGED" : "FAIL") << "\n";
    assert(detector.get_status("V001") == DriftStatus::FLAGGED);

    // V002: drift then nominal → resets
    {
        CalibrationObservation obs;
        obs.vehicle_id         = "V002";
        obs.timestamp          = 0;
        obs.reprojection_error = 1.8;
        obs.is_clean           = true;
        detector.process(obs);
    }
    {
        CalibrationObservation obs;
        obs.vehicle_id         = "V002";
        obs.timestamp          = 10;
        obs.reprojection_error = 0.3;  // nominal — should reset
        obs.is_clean           = true;
        detector.process(obs);
    }

    std::cout << "V002 after reset (expect NOMINAL): "
              << (detector.get_status("V002") == DriftStatus::NOMINAL
                  ? "NOMINAL" : "FAIL") << "\n";
    assert(detector.get_status("V002") == DriftStatus::NOMINAL);

    std::cout << "PASS\n";
}

void test_calibration_pipeline() {
    std::cout << "\n=== Test: Calibration Pipeline ===\n";

    auto pipeline = CalibrationPipeline::make_standard_pipeline(0.5, 2.0);

    // Perfect calibration
    auto r1 = pipeline.run(0.3, 1.5);
    std::cout << "Good calibration (expect PASS): "
              << (r1.passed ? "PASS" : "FAIL: " + r1.failure_reason) << "\n";
    assert(r1.passed);

    // Bad reprojection error
    auto r2 = pipeline.run(1.2, 1.5);
    std::cout << "Bad reprojection (expect FAIL): "
              << (!r2.passed ? "FAIL as expected: " + r2.failure_reason
                             : "ERROR: should have failed") << "\n";
    assert(!r2.passed);
    assert(r2.failure_reason == "reprojection_error_failed");

    // Bad lidar-camera agreement
    auto r3 = pipeline.run(0.3, 5.0);
    std::cout << "Bad lidar-cam (expect FAIL): "
              << (!r3.passed ? "FAIL as expected: " + r3.failure_reason
                             : "ERROR: should have failed") << "\n";
    assert(!r3.passed);
    assert(r3.failure_reason == "lidar_camera_agreement_failed");

    std::cout << "PASS\n";
}

int main() {
    std::cout << "=== Uber AV Labs — Calibration C++ Interview Prep ===\n";

    test_reprojection_error();
    test_quality_gate();
    test_drift_detector();
    test_calibration_pipeline();

    std::cout << "\n=== All tests passed ===\n";
    return 0;
}
