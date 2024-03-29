#include<iostream>
#include<vector>
#include<numeric>
#include<stack>
#include<queue>
#include<climits>
using namespace std;

// fast power approach
class Solution 
{
public:
    double myutil(double x, long n)
    {
        // base case 
        if(x == 0) return 0;
        if(n == 0) return 1;
        if(n == 1) return x; 

        //case1: handle negative powers --> if 2^-2 = 1/2^2;
        if(n < 0) return myutil(1/x,-n);
        double result = myutil(x * x, n/2);
        // if odd
        if(n%2) return result = result * x;
        return result;
    }
    double myPow(double x, int n)
    {
        return myutil(x,n);

    }
};

// TIME COMPLEXITY O(log n)
// SPACE COMPLEXITY O(log n)
