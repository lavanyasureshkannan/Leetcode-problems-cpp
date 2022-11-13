#include<iostream>
using namespace std;

/*  UNION:
    1. Just like struct and class union is also user defined data type
    2. In union, all the members share the biggest memory location
    3. This is used to achieve polymorphism in c++

    use case:
    1. when we need one value out of many that time we will use union (square class)
    2. 
*/

// the size of the union will be 4 and all the other variables point to that memory address
union myUnion
{
    int a; // 4 bytes
    short c; // 2 bytes
    char b; // 1 byte
};


// both the 
union square
{
    int height;
    int width;
};

int getArea(int w, int h)
{
    return w*h;
}

int main()
{
    square s1;
    s1.height = 10; // we are setting only height since width is also pointing to the same memory, the values will be same
    cout << getArea(s1.height, s1.width) << endl;
    return 0;
}