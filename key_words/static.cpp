#include<iostream>
using namespace std;
// Static keyword has different meanings when used with different types. We can use static keyword with:

// Static Variables : Variables in a function, Variables in a class
// Static Members of Class : Class objects and Functions in a class

// static variable in function -> When a variable is declared as static, space for it gets allocated for the lifetime of the program
// Static variables in a class: As the variables declared as static are initialized only once as they are allocated space in separate static storage so, the static variables in a class are shared by the objects.
// static variables cannot be declared inside the constrcutor


//                      STATIC FUNCTION AND VARIABLES

void display()
{
    static int count = 0;
    cout << count << " ";
    count++;

}


//  a static variable inside a class should be initialized explicitly by the user using the class name and scope resolution operator outside the class as shown below:
class demo
{
    public:
    static int a;
    demo() 
    {

    };
};

// datatype classname :: static variable = 
int demo :: a = 2;



// STATIC CLASS
// Class objects as static: Just like variables, objects also when declared as static have a scope till the lifetime of program
class ls
{
    public:
    ls()
    {
        cout << " COnstructor is invoked" << endl;
    }
    ~ls()
    {
        cout << "Destructor is invoked " << endl;
    }
};

// Static functions in a class: static member functions are allowed to access only the static data members or other static member functions, 
// they can not access the non-static data members or member functions of the class.

class lsls
{
    public:
    static void display()
    {
        cout << "WELCOME" << endl;
    }
};


int main()
{
    // demo d1;
    // // cout << d1.a << endl
    // int x = 0;
    // if(x==0)
    // {
        // static ls l1;
    // }
    // cout << "End of the main function"<< endl;

    lsls :: display();
    return 0;
}