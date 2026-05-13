#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// ============================================================
// DATA TYPES
// ============================================================

enum class Status { NOMINAL, DRIFTING, FLAGGED };

struct Observation {
    string vehicle_id;
    double reprojection_error;
    double timestamp;
};

struct VehicleHealth {
    Status status;
    double latest_error;
    int    consecutive_count;
};

struct FleetSummary {
    int total;
    int nominal;
    int drifting;
    int flagged;
    vector<string> flagged_vehicles;
};

// ============================================================
// CALIBRATION MONITOR
// ============================================================

class CalibrationMonitor {
public:

    // Config
    CalibrationMonitor(double threshold  = 1.0,
                       double baseline   = 0.5,
                       int    window     = 3)
        : threshold_(threshold)
        , baseline_(baseline)
        , window_(window) {}

    // Accept new observation
    void update(const Observation& obs) {

        // Get or create vehicle state
        auto& health = fleet_[obs.vehicle_id];

        // Already flagged — don't update
        if (health.status == Status::FLAGGED) return;

        health.latest_error = obs.reprojection_error;

        // Check drift
        if (obs.reprojection_error > threshold_) {
            health.consecutive_count++;

            if (health.consecutive_count >= window_) {
                health.status = Status::FLAGGED;
            } else {
                health.status = Status::DRIFTING;
            }
        } else {
            // Good observation — reset
            health.consecutive_count = 0;
            health.status = Status::NOMINAL;
        }
    }

    // Get single vehicle status
    Status get_status(const string& vehicle_id) const {
        auto it = fleet_.find(vehicle_id);
        if (it == fleet_.end()) return Status::NOMINAL;
        return it->second.status;
    }

    // Fleet health summary
    FleetSummary summary() const {
        FleetSummary fs;
        fs.total    = fleet_.size();
        fs.nominal  = 0;
        fs.drifting = 0;
        fs.flagged  = 0;

        for (const auto& kv : fleet_) {
            switch (kv.second.status) {
                case Status::NOMINAL:  fs.nominal++;  break;
                case Status::DRIFTING: fs.drifting++; break;
                case Status::FLAGGED:
                    fs.flagged++;
                    fs.flagged_vehicles.push_back(kv.first);
                    break;
            }
        }
        return fs;
    }

    // Is drift systemic across fleet?
    bool is_systemic(double pct = 0.7) const {
        if (fleet_.empty()) return false;
        int drifting = 0;
        for (const auto& kv : fleet_) {
            if (kv.second.status != Status::NOMINAL)
                drifting++;
        }
        return (double)drifting / fleet_.size() >= pct;
    }

private:
    double threshold_;
    double baseline_;
    int    window_;
    unordered_map<string, VehicleHealth> fleet_;
};

// ============================================================
// MAIN
// ============================================================

int main()
{
    CalibrationMonitor monitor(1.0, 0.5, 3);

    // V001 — 3 consecutive drifts → FLAGGED
    monitor.update({"V001", 1.2, 1});
    monitor.update({"V001", 1.3, 2});
    monitor.update({"V001", 1.1, 3});

    // V002 — drift then nominal → resets to NOMINAL
    monitor.update({"V002", 1.5, 1});
    monitor.update({"V002", 0.3, 2});

    // V003 — all nominal
    monitor.update({"V003", 0.4, 1});
    monitor.update({"V003", 0.3, 2});

    // Print fleet summary
    auto fs = monitor.summary();
    cout << "Total:    " << fs.total    << endl;
    cout << "Nominal:  " << fs.nominal  << endl;
    cout << "Drifting: " << fs.drifting << endl;
    cout << "Flagged:  " << fs.flagged  << endl;
    cout << "Flagged vehicles: ";
    for (auto& v : fs.flagged_vehicles) cout << v << " ";
    cout << endl;

    cout << "Systemic: " << (monitor.is_systemic() ? "YES" : "NO") << endl;

    return 0;
}