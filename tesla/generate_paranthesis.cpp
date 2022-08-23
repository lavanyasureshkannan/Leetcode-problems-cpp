// all combination, permutations --> backtracking
// its gonna recurrsively call the same function and deliver all the possibilities
class Solution
{
    public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> new_arr;
        string curr;
        backtrack(new_arr, curr , 0 , 0 , n);
        return new_arr;
    }
    
    public:
    void backtrack(vector<string> &new_arr, string curr_str, int open, int close, int max)
    {
        // base condition
        if(curr_str.length() == max * 2)
        { 
           new_arr.push_back(curr_str);
           return;
        }
        // recurrsive call 
        if(open < max)
        {
            backtrack(new_arr, curr_str + "(", open + 1 , close, max);
        }
        
        if(close < open)
        {
            backtrack(new_arr, curr_str +")", open, close + 1, max);
        }
    }
};

// TC: O(4^n / sqrt(n)) -> n steps 
// SC: O(4^n)