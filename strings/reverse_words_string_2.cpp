#include<iostream>
using namespace std;

class Solution
{
    public:
    string reverseWords(string s)
    {
        /*
        Input: s = "Let's take LeetCode contest"
        Output: "s'teL ekat edoCteeL tsetnoc"
        */
        
        // two pointer technique
        // left, right pointer => 0(first idx)
        // left will be initially at the start and right will increment till ' '
        // reverse the word
        // once you find a space left should = right + 1
        //  right = left 

        int left = 0;
        int right = 0;
        while(left < s.length())
        {
            while(right < s.length() && s[right] != ' ')
                right ++;
            reverse(s.begin() + left, s.begin()+right);
            left = right+1;
            right = left;
        }
        return s;
    }
    
};

// TC: O(N)
// SC: O(1) 




int main()
{
    return 0;
}
