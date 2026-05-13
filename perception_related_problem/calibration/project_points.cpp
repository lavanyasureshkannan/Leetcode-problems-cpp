#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Vec3
{
    double X, Y, Z;
    Vec3(double x, double y, double z)
    {
        X = x;
        Y = y;
        Z = z;
    }
};

struct Vec2
{
    double U, V;
    Vec2(double u, double v)
    {
        U = u;
        V = v;
    }
};

struct CameraIntrinsics
{
    double fx, fy;
    double cx, cy;
};

struct Reprojection_result
{
    double Mean_reprojection_error;
    int num_of_skipped_points;
};

struct Mat3
{
    double R[3][3];

    // safe default init
    Mat3()
    {
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                R[i][j] = 0.0;
    }

    // init from vector
    Mat3(const vector<vector<double>>& m)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                R[i][j] = m[i][j];
            }
        }
    }
};

Vec2 project_point(
    const Vec3& pt_world,
    const Mat3& R,
    const Vec3& t,
    const CameraIntrinsics& K
)
{
    // Step 1: Transform to camera frame
    double Xc = R.R[0][0]*pt_world.X + R.R[0][1]*pt_world.Y + R.R[0][2]*pt_world.Z + t.X;
    double Yc = R.R[1][0]*pt_world.X + R.R[1][1]*pt_world.Y + R.R[1][2]*pt_world.Z + t.Y;
    double Zc = R.R[2][0]*pt_world.X + R.R[2][1]*pt_world.Y + R.R[2][2]*pt_world.Z + t.Z;

    // Step 2: validity check
    if (Zc <= 0.0)
    {
        return Vec2(-1, -1);  // invalid projection
    }

    // Step 3: projection
    double u = K.fx * (Xc / Zc) + K.cx;
    double v = K.fy * (Yc / Zc) + K.cy;

    return Vec2(u, v);
}

double compute_reprojection_error(
    const std::vector<Vec3>& points_3d,
    const std::vector<Vec2>& observed_2d,
    const Mat3& R,
    const Vec3& t,
    const CameraIntrinsics& K)
{    // Input validation
    if (points_3d.empty()) {
        throw std::invalid_argument("points_3d cannot be empty");
    }
    if (points_3d.size() != observed_2d.size()) {
        throw std::invalid_argument("Size mismatch between 3D and 2D points");
    }

    double total_error = 0.0;
    int    valid_count = 0;

    for (size_t i = 0; i < points_3d.size(); ++i) {

        // Project 3D world point into camera image
        Vec2 projected;
        if (!project_point(points_3d[i], R, t, K, projected)) {
            continue;  // behind camera — skip
        }

        // Pixel distance between projected and observed
        double dx = projected.u - observed_2d[i].u;
        double dy = projected.v - observed_2d[i].v;
        total_error += std::sqrt(dx*dx + dy*dy);
        valid_count++;
    }

    // Avoid divide by zero if all points behind camera
    if (valid_count == 0) return 0.0;

    return total_error / valid_count;
}


int main()
{
    // Example usage

    CameraIntrinsics K = {800, 800, 640, 360};
    vector<vector<double>> r = {
        {1,0,0},
        {0,1,0},
        {0,0,1}};

    Mat3 R(r);

    Vec3 t(0.1, 0.2, 0.3);
    Vec3 pt(1, 2, 5);

    Vec2 out = project_point(pt, R, t, K);

    cout << out.U << " " << out.V << endl;

    return 0;
}