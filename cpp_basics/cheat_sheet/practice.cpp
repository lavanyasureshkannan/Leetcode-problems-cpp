#include <iostream>
#include <vector>
using namespace std;


struct points2d
{
    double x;
    double y;
    points2d(double m_x=0.0, double m_y=0.0) : x(m_x), y(m_y) {}
};

template<typename T>
class Manager
{
    private:
    vector<T*> points;
    public:
    void push(T* val)
    {
        points.push_back(val);
    }
    T* pop(T* val)
    {
        T* pop_val = points[val];
        return pop_val;
    }
};

class 

int main()
{
    return 0;
}