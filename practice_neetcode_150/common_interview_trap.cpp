#include <iostream>
using namespace std;

int main()
{
    int x = 5;
     // int y = x++ + ++x;
    int temp = x++; // 6
    ++x; // 7
    int y = temp + x; //12
    cout << y << endl;
    return 0;
}