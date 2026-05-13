#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Vec3 { double x, y, z; };
struct Vec2 { double u, v; };

struct CameraIntrinsics { double fx, fy, cx, cy; };

struct ValidationResult 
{
    bool        passed;
    double      mean_error;
    std::string failure_reason;
};

ValidationResult validate_calibration_result(
    const std::vector<Vec3>& points_3d,
    const std::vector<Vec2>& observed_2d,
    const double R[3][3],
    const double t[3],
    const CameraIntrinsics& K,
    double threshold)
{   

    double total_error = 0.0;
    for(size_t i=0; i<points_3d.size(); i++)
    {
        double X = points_3d[i].x;
        double Y = points_3d[i].y;
        double Z = points_3d[i].z;

        double Xc = R[0][0]*X + R[0][1]*Y + R[0][2]*Z + t[0]; 
        double Yc = R[1][0]*X + R[1][1]*Y + R[1][2]*Z + t[1];
        double Zc = R[2][0]*X + R[2][1]*Y + R[2][2]*Z + t[2];

        if(Zc <= 0) continue;

        double u = K.fx * (Xc / Zc) + K.cx;
        double v = K.fy * (Yc / Zc) + K.cy;

        double dx = u - observed_2d[i].u;
        double dy = v - observed_2d[i].v;

        double curr_error = sqrt((dx*dx) + (dy*dy));
        total_error += curr_error;
    }
    ValidationResult results;
    results.mean_error = total_error / observed_2d.size();
    if(results.mean_error < threshold) 
    {
        results.passed = true;
        results.failure_reason = "";   
    } 
    else
    {
        results.passed = false;
        results.failure_reason = "reprojection error to high";
    }
    return results;
}

int main()
{
    // Camera intrinsics — focal length 1000px, principal point 640x360
    CameraIntrinsics K;
    K.fx = 1000.0;
    K.fy = 1000.0;
    K.cx = 640.0;
    K.cy = 360.0;

    // Identity rotation — camera aligned with world frame
    double R[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    // Camera is 5 meters in front of the rig
    double t[3] = {0.0, 0.0, 5.0};

    // 3D rig points (known from calibration rig geometry)
    std::vector<Vec3> points_3d = {
        {0.0,  0.0,  0.0},   // center
        {0.1,  0.0,  0.0},   // 10cm right
        {0.0,  0.1,  0.0},   // 10cm up
        {-0.1, 0.0,  0.0},   // 10cm left
        {0.0, -0.1,  0.0}    // 10cm down
    };

    // Observed 2D corners in image
    // With identity R, t=(0,0,5) and fx=fy=1000:
    // point (0,0,0) projects to (640, 360) — principal point
    // point (0.1,0,0) projects to (640 + 1000*0.1/5, 360) = (660, 360)
    std::vector<Vec2> observed_2d = {
        {640.0, 360.0},   // perfect
        {660.0, 360.0},   // perfect
        {640.0, 380.0},   // perfect
        {620.0, 360.0},   // perfect
        {640.0, 340.0}    // perfect
    };

    // Test 1: Perfect calibration — should PASS
    auto result1 = validate_calibration_result(
        points_3d, observed_2d, R, t, K, 0.5);

    std::cout << "Test 1 (perfect calibration):\n";
    std::cout << "  Passed: "     << (result1.passed ? "YES" : "NO") << "\n";
    std::cout << "  Mean error: " << result1.mean_error << " pixels\n";
    std::cout << "  Reason: "     << result1.failure_reason << "\n\n";

    // Test 2: Bad calibration — shift observed points by 2 pixels
    std::vector<Vec2> bad_observed = {
        {642.0, 362.0},   // 2px off
        {662.0, 362.0},   // 2px off
        {642.0, 382.0},   // 2px off
        {622.0, 362.0},   // 2px off
        {642.0, 342.0}    // 2px off
    };

    auto result2 = validate_calibration_result(
        points_3d, bad_observed, R, t, K, 0.5);

    std::cout << "Test 2 (bad calibration — 2px offset):\n";
    std::cout << "  Passed: "     << (result2.passed ? "YES" : "NO") << "\n";
    std::cout << "  Mean error: " << result2.mean_error << " pixels\n";
    std::cout << "  Reason: "     << result2.failure_reason << "\n\n";

    // Test 3: Point behind camera — should handle gracefully
    std::vector<Vec3> bad_points = {
        {0.0, 0.0,  0.0},
        {0.0, 0.0, -1.0}   // behind camera — Z negative
    };
    std::vector<Vec2> bad_obs2 = {
        {640.0, 360.0},
        {640.0, 360.0}
    };

    auto result3 = validate_calibration_result(
        bad_points, bad_obs2, R, t, K, 0.5);

    std::cout << "Test 3 (point behind camera):\n";
    std::cout << "  Passed: "     << (result3.passed ? "YES" : "NO") << "\n";
    std::cout << "  Mean error: " << result3.mean_error << " pixels\n\n";

    return 0;
}
