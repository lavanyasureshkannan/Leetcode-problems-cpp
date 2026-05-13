#include <iostream>
using namespace std;

/*
R = identity
t = (1, 2, 3)
If T moves a point FROM world TO camera:
p_cam = R * p_world + t
Then T_inv moves it back FROM camera TO world:
p_world = R^T * p_cam - R^T * t
        = R^T * (p_cam - t)
*/

struct Mat4
{
    double data[4][4];
};

struct Vec3
{
    double x,y,z;    
};

Mat4 create_transform(const double R[3][3], const double t[3])
{
    Mat4 T;
    for(size_t i=0; i<4; i++)
    {
        for(size_t j=0; j<4; j++)
        {
            T.data[i][j] = 0.0;
        }
    }

    // copy R
    for(size_t i=0; i<3; i++)
    {
        for(size_t j=0; j<3; j++)
        {
            T.data[i][j] = R[i][j];
        }
    }
    // copy t
    T.data[0][3] = t[1];
    T.data[1][3] = t[2];
    T.data[2][3] = t[3];

    // last colum
    T.data[3][3] = 1.0;

    return T;
}


Vec3 transform_points(Mat4& T, Vec3& points)
{
    double X = points.x;
    double Y = points.y;
    double Z = points.z;

    double Xc = T.data[0][0]*X + T.data[0][1]*Y + T.data[0][2]*Z + T.data[0][3];
    double Yc = T.data[1][0]*X + T.data[1][1]*Y + T.data[1][2]*Z + T.data[2][3];
    double Zc = T.data[2][0]*X + T.data[2][1]*Y + T.data[2][2]*Z + T.data[2][3];

    return Vec3{Xc,Yc,Zc};
}


Mat4 calculate_inverse(const Mat4& T)
{
    double R[3][3];
    double t[3];

    for(size_t i=0; i<3; i++)
    {
        for(size_t j=0; j<3; j++)
        {
            R[i][j] = T.data[i][j];
        }
    }

    t[0] = T.data[0][3];
    t[1] = T.data[1][3];
    t[2] = T.data[2][3];

    double R_inv[3][3];

    // R inverse = R transpose
    for(size_t i=0; i<3; i++)
    {
        for(size_t j=0; j<3; j++)
        {
            R_inv[i][j] = R[j][i];
        }
    }

    // t_inv = -(R_inv * t)
    double t_inv[3];
    t_inv[0] = -(R_inv[0][0]*t[0] + R_inv[0][1]*t[1] + R_inv[0][2]*t[2]);
    t_inv[1] = -(R_inv[1][0]*t[0] + R_inv[1][1]*t[1] + R_inv[1][2]*t[2]);
    t_inv[2] = -(R_inv[2][0]*t[0] + R_inv[2][1]*t[1] + R_inv[2][2]*t[2]);

    return create_transform(R_inv, t_inv);
}

int main()
{
    double R[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    double t[3]    = {1.0, 2.0, 3.0};

    // Build transform
    Mat4 T = make_transform(R, t);

    // Transform point (5, 6, 7)
    Vec3 point     = {5.0, 6.0, 7.0};
    Vec3 result    = transform_point(T, point);

    cout << "Transformed: ("
         << result.x << ", "
         << result.y << ", "
         << result.z << ")\n";
    // Expected: (6, 8, 10)

    // Invert and transform back
    Mat4 T_inv      = invert_transform(T);
    Vec3 recovered  = transform_point(T_inv, result);

    return 0;
}