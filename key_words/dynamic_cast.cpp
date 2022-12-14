/*
DYNAMIC CASTING:
- It is used to find the correct down cast.
  (When you want to change the class type from base class type to derived class type or vice versa we use dynamic casting.
  all the derived classes can be assigned to base pointer but when we do that vice versa we face issue. To avoid that we use dynamic casting.)
- It works wehn inheritance and polymorphism comes into play.
- we need atleast one virtual function
- if the cast type fails and new type is a pointer type, then it returns a null pointer of that type.

*/
#include<iostream>
using namespace std;

class myclass
{
    public:
    virtual void display()
    {
        cout << "inside base class" << endl;
    } 
};

class derived_class : public myclass
{
    public:
    void display()
    {
        cout << "inside derived class" << endl;
    }
};

class sub_class : public myclass
{
    public:
    void display()
    {
        cout << "Inside sub class" << endl; 
    }
};

int main()
{
    derived_class d1;
    myclass* base_ptr = dynamic_cast<myclass*>(&d1);
    derived_class* der_ptr = dynamic_cast<derived_class*> (base_ptr);

    return 0;

}