#include<iostream>
using namespace std;

class Optimised_solution 
{
    public:
    int tribonacci(int n)
    {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;
        int a = 0;
        int b = 1;
        int c = 1;
        for(int i=3; i<=n; i++)
        {
            int curr = a+b+c;
            a = b;
            b = c;
            c = curr;
        }
        return c; 
    }
};

// TC: O(N)
// SC: O(1)

int main()
{
    return 0;
}