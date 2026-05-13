#include <iostream>
#include <vector>
using namespace std;

/*
3D world point: (2.0, 1.0, 10.0)
R: identity
t: (0, 0, 0)
fx=1000, fy=1000, cx=640, cy=360
width=1280, height=720

Camera frame: (2.0, 1.0, 10.0)
x_n = 2.0/10.0 = 0.2
y_n = 1.0/10.0 = 0.1
u = 1000*0.2 + 640 = 840
v = 1000*0.1 + 360 = 460

output → pixel=(840, 460), valid=true
*/

struct Vec3
{
    double x,y,z;
};

struct Vec2
{
    double u,v;
};

struct CameraIntrinsics
{
    double fx,fy;
    double cx,cy;
};
// R*x + t

bool world_to_pixel(const Vec3& world_points, 
                    const CameraIntrinsics& k, 
                    double R[3][3],
                    double T[3], 
                    int img_width, int img_height,
                    Vec2& outpixel)
{
    double X = world_points.x;
    double Y = world_points.y;
    double Z = world_points.z;

    // rigid body transformation
    double Xc = R[0][0]*X + R[0][1]*Y + R[0][2]*Z + T[0];
    double Yc = R[1][0]*X + R[1][1]*Y + R[1][2]*Z + T[1];
    double Zc = R[2][0]*X + R[2][1]*Y + R[2][2]*Z + T[2];

    if(Zc <= 0) return false;
    
    double x_n = (Xc/Zc);
    double y_n = (Yc/Zc);

    double u = k.fx * x_n + k.cx;
    double v = k.fy * y_n + k.cy;
    
    if(u<0 || v<0 || u>=img_width || v>=img_height) return false;
    
    outpixel.u = u;
    outpixel.v = v;
}



int main()
{
    return 0;
}