#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
using namespace std;

struct Vec3 { double x, y, z; };
struct Vec2 { double u, v; };
struct CameraIntrinsics { double fx, fy, cx, cy; };

struct Correspondence {
    Vec3 point_3d;
    Vec2 point_2d;
};

struct RANSACResult {
    vector<int> inlier_indices;
    int         best_inlier_count;
};

// ============================================================
// HELPER: compute reprojection error for one correspondence
// ============================================================

double compute_error(
    const Correspondence& c,
    const double R[3][3],
    const double t[3],
    const CameraIntrinsics& K)
{
    double X = c.point_3d.x;
    double Y = c.point_3d.y;
    double Z = c.point_3d.z;

    // World → camera frame
    double Xc = R[0][0]*X + R[0][1]*Y + R[0][2]*Z + t[0];
    double Yc = R[1][0]*X + R[1][1]*Y + R[1][2]*Z + t[1];
    double Zc = R[2][0]*X + R[2][1]*Y + R[2][2]*Z + t[2];

    // Behind camera — infinite error
    if (Zc <= 0.0) return 1e9;

    // Project to pixel
    double u = K.fx * (Xc / Zc) + K.cx;
    double v = K.fy * (Yc / Zc) + K.cy;

    // Pixel distance from observed
    double du = u - c.point_2d.u;
    double dv = v - c.point_2d.v;
    return sqrt(du*du + dv*dv);
}

// ============================================================
// STEP 1: Simple inlier finding (no random sampling)
// Just check every point against threshold
// ============================================================

vector<int> find_inliers(
    const vector<Correspondence>& correspondences,
    const double R[3][3],
    const double t[3],
    const CameraIntrinsics& K,
    double threshold)
{
    vector<int> inliers;

    for (size_t i = 0; i < correspondences.size(); i++) {
        double error = compute_error(correspondences[i], R, t, K);
        if (error < threshold) {
            inliers.push_back(i);
        }
    }

    return inliers;
}

// ============================================================
// STEP 2: Full RANSAC
// Randomly sample subsets, find best inlier set
// ============================================================

RANSACResult ransac_inliers(
    const vector<Correspondence>& correspondences,
    const double R[3][3],
    const double t[3],
    const CameraIntrinsics& K,
    double threshold,
    int    iterations)
{
    RANSACResult best;
    best.best_inlier_count = 0;

    if (correspondences.empty()) return best;

    // Random number generator
    mt19937 rng(42);  // fixed seed for reproducibility
    uniform_int_distribution<int> dist(0, correspondences.size() - 1);

    for (int iter = 0; iter < iterations; iter++)
    {
        // Step 1: randomly pick one correspondence as hypothesis
        int sample_idx = dist(rng);

        // Step 2: count ALL points that are inliers
        // given current R, t (in real RANSAC you'd recompute R,t
        // from sample — here we use given R,t for simplicity)
        vector<int> current_inliers;

        for (size_t i = 0; i < correspondences.size(); i++) {
            double error = compute_error(correspondences[i], R, t, K);
            if (error < threshold) {
                current_inliers.push_back(i);
            }
        }

        // Step 3: keep best set
        if ((int)current_inliers.size() > best.best_inlier_count) {
            best.best_inlier_count = current_inliers.size();
            best.inlier_indices    = current_inliers;
        }
    }

    return best;
}

// ============================================================
// MAIN
// ============================================================

int main()
{
    CameraIntrinsics K = {1000, 1000, 640, 360};

    double R[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    double t[3]    = {0, 0, 0};

    // With R=identity, t=0, camera frame = world frame
    // Point (1,0,5): u = 1000*(1/5)+640 = 840, v = 360
    // Point (0,1,5): u = 640, v = 1000*(1/5)+360 = 560
    // Point (0,0,5): u = 640, v = 360
    // Point (1,1,5): OUTLIER — observed at (999,999) but projects to (840,560)

    vector<Correspondence> correspondences = {
        {{1.0, 0.0, 5.0}, {840.0, 360.0}},  // good
        {{0.0, 1.0, 5.0}, {640.0, 560.0}},  // good
        {{0.0, 0.0, 5.0}, {640.0, 360.0}},  // good
        {{1.0, 1.0, 5.0}, {999.0, 999.0}},  // OUTLIER
    };

    // Test 1: Simple inlier finding
    cout << "=== Simple Inlier Finding ===\n";
    auto inliers = find_inliers(correspondences, R, t, K, 2.0);
    cout << "Inliers found: " << inliers.size() << "\n";
    cout << "Inlier indices: ";
    for (int idx : inliers) cout << idx << " ";
    cout << "\n\n";

    // Test 2: RANSAC
    cout << "=== RANSAC ===\n";
    auto result = ransac_inliers(correspondences, R, t, K, 2.0, 100);
    cout << "Best inlier count: " << result.best_inlier_count << "\n";
    cout << "Inlier indices: ";
    for (int idx : result.inlier_indices) cout << idx << " ";
    cout << "\n\n";

    // Test 3: All outliers (extreme case)
    cout << "=== All Outliers ===\n";
    vector<Correspondence> all_bad = {
        {{1.0, 0.0, 5.0}, {999.0, 999.0}},
        {{0.0, 1.0, 5.0}, {111.0, 111.0}},
    };
    auto result2 = ransac_inliers(all_bad, R, t, K, 2.0, 100);
    cout << "Inliers (expect 0): " << result2.best_inlier_count << "\n";

    return 0;
}