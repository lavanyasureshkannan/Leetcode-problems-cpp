#include<iostream>
#include<vector>
using namespace std;

/*
    TYPEDEF
    Typedef keyword in C++ is used for aliasing existing data types, user-defined data types, and pointers to a more meaningful name. 
    Typedefs allow you to give descriptive names to standard data types, which can also help you self-document your code.

    Advantages:
    1. Reading the complicated ugly code in a most simplified way.

*/

typedef vector<int> v;
typedef unsigned long long int ulli;


int main()
{
    ulli a = 1000000000000;
    v vector1;
    vector1.push_back(10);
    vector1.push_back(20);
    vector1.push_back(30);
    vector1.push_back(40);
    for(int i=0; i<vector1.size(); i++)
    {
        cout << vector1[i] << " ";
    }
    cout << endl;
    cout << a << endl;
    return 0;
}

