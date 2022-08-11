

// all combination, permutations --> backtracking

/*
1. create a backtracking function
2. check if the paranthesis (number -> given) = max * 2 (ex: if n =3 then total paranthesis = 6)
3. recurrsively call the back tracking function. 
*/

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

// TC : This analysis is outside the scope of this article, but it turns out this is the n-th Catalan number - 4^n / n sqrt(n)
// SC: O(n) -> store the sequence