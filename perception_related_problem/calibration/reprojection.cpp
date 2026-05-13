#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
    CALCULATHE REPROJECTION ERROR
    OBSERVED POINTS =  {100.0, 200.0}, {150.0, 250.0}, {300.0, 400.0}
    PROJECTED POINTS = {102.0, 198.0}, {148.0, 252.0}, {305.0, 395.0}
*/

double Mean_reprojection_error(vector<vector<double>>& observed_pts, vector<vector<double>>& projected_points)
{
    // edge case
    if(observed_pts.size() == 0 || observed_pts.size() != projected_points.size()) return -1;
    double total_error = 0.0;
    int n = observed_pts.size();
    for(size_t i=0; i<observed_pts.size(); i++)
    {
        double dx = observed_pts[i][0] - projected_points[i][0];
        double dy = observed_pts[i][1] - projected_points[i][0];
        double curr_error = sqrt((dx * dx) + (dy * dy));
        total_error += curr_error;
    }
    return (total_error/n);
}

/******************************************************************************************/
/*
    PROJECT THE GIVEN XYZ POINTS ON TO CAMERA IMAGE
    GIVEN : point = {1.0, 2.0, 5.0}  // (X, Y, Z)
            fx = 800, fy = 800
            cx = 640, cy = 360
    OUTPUT : U,V

    perpective projection
    u = fx * (X/Z) + cx
    v = fy * (Y/Z) + cy

    Pcam = Plidar * Rt + T
*/

vector<pair<double, double>> project_3d_points(vector<vector<double>>& points, 
                                              const double fx, const double fy,
                                              const double cx, const double cy,
                                              vector<vector<double>>& R,
                                              vector<double>& t)
{
    vector<pair<double,double>> result;
    for(size_t i=0; i<points.size(); i++)
    {
        if(points[i].size() != 3) continue;
        double X = points[i][0];
        double Y = points[i][1];
        double Z = points[i][2];

        // 1. Apply rotation and translation
        double Xc = R[0][0]*X + R[0][1]*Y + R[0][2]*Z + t[0];
        double Yc = R[1][0]*X + R[1][1]*Y + R[1][2]*Z + t[1];
        double Zc = R[2][0]*X + R[2][1]*Y + R[2][2]*Z + t[2];  

        // 2. Skip invalid detections
        if(Zc <= 0 ) continue;
        double u = fx * (Xc/Zc) + cx;
        double v = fy * (Yc/Zc) + cy;
        result.push_back({u,v});
    }
    return result;
}

int main ()
{
    // vector<vector<double>> observed_points = {{100.0, 200.0}, {150.0, 250.0}, {300.0, 400.0}};
    // vector<vector<double>> projected_points = {{102.0, 198.0}, {148.0, 252.0}, {305.0, 395.0}};
    // cout << Mean_reprojection_error(observed_points, projected_points) << endl;

    double fx = 800; double fy = 800; double cx = 640; double cy = 360;
    vector<vector<double>> points3D = {
    {1.0, 2.0, 5.0},    // normal point in front
    {0.5, -1.0, 3.0},   // below camera
    {-2.0, 1.5, 4.0},   // left side
    {0.0, 0.0, 2.0},    // straight ahead (center)
    {3.0, 2.0, 10.0},   // far away point
    {1.0, 1.0, -2.0},   // ❌ behind camera (invalid)
    {2.0, -0.5, 0.0}    // ❌ Z = 0 (invalid, division issue)
};
    vector<vector<double>> R = {{1, 0, 0},{0, 1, 0},{0, 0, 1}};
    vector<double> t = {0.1, 0.2, 0.3};
    vector<pair<double, double>> result = project_3d_points(points3D, fx, fy, cx, cy,R,t);
    for(size_t i=0; i<result.size(); i++)
    {
        cout << result[i].first << " " << result[i].second;
    }
    return 0;
}