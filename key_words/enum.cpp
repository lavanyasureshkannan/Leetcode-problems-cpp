#include<iostream>
using namespace std;


// enums are like a conatiners that holds min data values which by default has a starting index of 0
enum days {sunday,monday,tuesday,wednesday,thursday,friday,saturday};

int main()
{
    days d1;
    d1 = friday;
    cout << d1 << endl;
    // for(int i=sunday; i<saturday; i++)
    // {
    //     cout << i << endl;
    // }
    return 0;
}