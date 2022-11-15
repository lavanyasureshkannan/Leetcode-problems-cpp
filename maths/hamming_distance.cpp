class Solution {
public:
    int countSetBits(int x)
    {
        int result=0;
        while(x>0)
        {
            x &= x-1;
            result++;
        }
        return result;
    }
    int hammingDistance(int x, int y) 
    {
        int z=x^y;
        return countSetBits(z);
    }
};
