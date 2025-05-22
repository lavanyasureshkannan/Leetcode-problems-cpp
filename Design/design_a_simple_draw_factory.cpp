#include <iostream>
#include <memory>
using namespace std;

// 1. create a simple class
class shape
{
    public:
    virtual void draw() = 0; // making it abstract class
    ~shape() = default; // virtual destructor
};

// 2. create  a subclass from shape
class circle : public shape
{
    public:
    void draw()
    {
        cout << "Draw a Circle" << endl;
    }
};

class square : public shape
{
    public:
    void draw()
    {
        cout << "Draw a square" << endl;
    }
};

// 3. create a factory class
class shapefactory
{
    public:
    // static shape* create_shape(const string& shape_name)
    // {
    //     if(shape_name == "circle") return new circle();
    //     else if (shape_name == "square") return new square();
    //     else return nullptr;
    // }

    static unique_ptr<shape> create_shape(const string& shape_name)
    {
        if(shape_name == "circle") return make_unique<circle>();
        else if(shape_name == "square") return make_unique<square>();
        else return nullptr;
    }
};

int main()
{
    // shape* s1 = shapefactory::create_shape("circle");
    // s1->draw();
    // shape* s2 = shapefactory::create_shape("square");
    // s2->draw();

    // delete s1;
    // delete s2;

    unique_ptr<shape> s1 = shapefactory::create_shape("circle");
    s1->draw();
    unique_ptr<shape> s2 = shapefactory::create_shape("square");
    s2->draw();
    return 0;
}

