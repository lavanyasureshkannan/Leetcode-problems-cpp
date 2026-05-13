#include <vector>
#include <cmath>
#include <string>

struct Vec3 { double x, y, z; };
struct Vec2 { double u, v; };
struct CameraIntrinsics { double fx, fy, cx, cy; };

// Projects 3D point into camera and computes reprojection error
// against observed 2D point. Returns true if error is acceptable.
bool validate_calibration(
    const std::vector<Vec3>& points_3d,
    const std::vector<Vec2>& observed_2d,
    const double R[3][3],
    const double t[3],
    const CameraIntrinsics& K,
    double threshold)
{
    double total_error = 0;

    for (int i = 0; i < points_3d.size(); i++)
    {
        double Xc = R[0][0]*points_3d[i].x + R[0][1]*points_3d[i].y + R[0][2]*points_3d[i].z + t[0];
        double Yc = R[1][0]*points_3d[i].x + R[1][1]*points_3d[i].y + R[1][2]*points_3d[i].z + t[1];
        double Zc = R[2][0]*points_3d[i].x + R[2][1]*points_3d[i].y + R[2][2]*points_3d[i].z + t[2];

        if(Zc <= 0) continue;

        double u = K.fx * (Xc / Zc) + K.cx;
        double v = K.fy * (Yc / Zc) + K.cy;

        double dx = u - observed_2d[i].u;
        double dy = v - observed_2d[i].v;

        double curr_error = sqrt(dx*dx + dy*dy);
        total_error += curr_error;
    }

    double mean_error = total_error / points_3d.size();
    return mean_error < threshold;
}