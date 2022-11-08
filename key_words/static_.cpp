#include<iostream>
using namespace std;

/*
    STATIC VARIABLE
    1. When you declare a variable as static then the memory for that variable is allocated throughout the lifetime of the program.
    2. Static variable is common for all the objects you create from that particular class
    3. Static functions inside the class can access only static varibles.
    4. Non-static member functions can access both.
    5. The static variables or functions declared outside the class or struct will have a scope for that particular translation unit and cannot be accessed everywhere unlike the global variable.
*/


class base
{
    public:
    
    int x;
    static int y;

    static void display()
    {
        cout << y << endl;
    }

};

// create a memory for the static variable
// this y will be common for all the b1,b2,b3 and so on 
int base :: y = 60;


static int add(int a, int b)
{
    return a+b;
}

int main()
{
    base b1;
    b1.x = 10;
    base::display();


    base b2;
    b2.x = 20;

    //cout << b1.x << " " << b2.x << endl; 
    //cout << b1.y << " " << b2.y << endl;

    
    return 0;
}
