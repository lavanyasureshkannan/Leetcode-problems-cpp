#include<iostream>
#include <vector>
using namespace std;

/*
1. if n = 4 check odd or even 
2. if even [-1,-3,1,3]
3. if odd [-1,-3,1,3,0]
*/

vector<int> sumzero(int n)
{
    vector<int> result;
    // even
    for(int i=0; i < n/2; i++)
    {
        result.push_back(n/2-i); // positive number
        result.push_back(-(n/2-i)); // negative number
    }
    // odd
    if(n%2 != 0)
    {
        result.push_back(0);
    }
    return result;
}

int main()
{
    sumzero(5);
    return 0;
}