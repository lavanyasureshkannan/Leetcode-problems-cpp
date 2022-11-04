#include<iostream>
using namespace std;

class base_class
{
    public:
    base_class()
    {
        cout << " BASE CONSTRUCTOR" << endl;
    }
    virtual ~base_class()
    {
        cout << " BASE DESTRUCTOR" << endl;
    }

};


class derived_class : public base_class
{
    public:
    derived_class()
    {
        cout << " DERIVED CONSTRUCTOR" << endl;
    }
    ~derived_class()
    {
        cout << " DERIVED DESTRUCTOR" << endl;
    }

};

int main()
{
    // base_class* base1 = new base_class();
    // delete base1;
// 
    // cout << "-------------------------" << endl;
// 
    // derived_class* derived1 = new derived_class();
    // delete derived1;
    base_class* ptr = new derived_class();
    delete ptr;

   

    return 0;
}