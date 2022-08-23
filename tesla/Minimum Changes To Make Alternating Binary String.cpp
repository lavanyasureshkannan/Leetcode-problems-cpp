class Solution 
{
public:
int minOperations(string s)
{
    int startwith_0 = 0;
    int startwith_1 = 0;

    for(int i=0; i<s.length(); i++)
    {
        // take mod its gonna give you either 0 or 1
        // the ascii conversion will give you the same value
        if((s[i] - '0') != (i%2)) startwith_0++;
        else startwith_1++;    
    }
    return min(startwith_0, startwith_1);

} 
};

//TC: O(N)
//SC: O(1) 