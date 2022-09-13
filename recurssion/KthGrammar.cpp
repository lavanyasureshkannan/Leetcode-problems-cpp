#include<iostream>
using namespace std;


class Solution
{
    public:
    int kthGrammar(int n, int k)
    {
        /*
            PARENT ALGORITHM
            1. base case where N = 1
            2. Find the parent of the given k -> recurrsive call (N-1, K/2)                                                             (prev row, parent)
            3. check if k is even or odd
            4. if parent == 1 and k == odd return 1 else return 0
            5. if parent == 0 and k == odd return 0 else return 1 
        */
        if(n == 1) return 0; // first row
        int parent = kthGrammar(n-1, k/2  + k % 2); // handle both odd and even k
        bool isKodd = (k%2 == 1); 
        if (parent == 1)
        {
            if (isKodd) return 1; 
            else return 0;
        }
        else 
        {
            if(isKodd) return 0;
            else return 1;
        }

    }
};

// TC: O(N logK) -> N levels and its performing log K operations
// SC: O(N)

int main()
{
    return 0;
}
