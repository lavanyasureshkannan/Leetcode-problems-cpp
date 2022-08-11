#include<iostream>
#include<unordered_set>
using namespace std;

/*
    1. define a dfs recurrsive
    2. if there are duplicates return 0;
    3. initialize a string result = > initially " " => in the end return the size of the string
    4. iterate through the remainig array and update the max best value 
*/

class Solution 
{
public:
    int maxLength(vector<string>& arr) 
    {
        // building a dfs recurrsion with an (array,position, empty string)
        return dfs(arr, 0, " ");
    }


    int dfs(vector<int>& array, int j, string result)
    {
        // duplicate characters by initialising unordered set 
        unordered_set<char> result_set(result.begin(), result.end());
        // check if the size of the result and set is equal
        if(result.size() != result_set.size())
        {
            return 0;
        }
        // recurrse all the possibilities and find the best answer
        int maxi = result.size();
        // iterate and update the max
        for(int i=0; i<j ; i++)
        {
            maxi = max(maxi, dfs(array, i+1, res+arr[i]));
        }
        
        return maxi; 

    }
};