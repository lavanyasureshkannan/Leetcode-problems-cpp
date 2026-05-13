#include <iostream>
using namespace std;

class base
{
public:
    virtual void display() = 0;   // pure virtual function
    virtual ~base()               // virtual destructor
    {
        cout << "base destructor" << endl;
    }
};

class derived : public base
{
public:
    void display() override
    {
        cout << "Derived class display" << endl;
    }

    ~derived() {
        cout << "derived destructor" << endl;
    }
};

int main()
{
    base* ptr = new derived();
    ptr->display();

    delete ptr;  // important! ensures proper cleanup
    return 0;
}
