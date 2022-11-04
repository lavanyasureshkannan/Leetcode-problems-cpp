#include<iostream>
using namespace std;
/*
Virtual functions are something that reduces dynamic dispatch -> refers to the action of finding the right function to call during the runtime
It consumes memory because of creating V-table and mapping the functions
It is called during Run-time polymorphism

*/


class base_class
{
    public:
    virtual void display()
    {
        cout << " This is the display from base class" << endl;
    }
};

class derived_class : public base_class
{
    public:
    void display() override
    {
        cout << "This is the display from derived class" << endl;
    }
};

int main()
{
    base_class b1;
    b1.display();

    derived_class d1;
    d1.display();

    base_class* ptr = &d1;
    ptr->display();


    return 0;

}