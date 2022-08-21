#include<iostream>
using namespace std;

// count and say

/*
    1. base case => n = 0;
    2. have a while and keep running till n = 0;
    3. have a result = "1" -> keep updating the result inside the for loop
    4. keep checking the next number and update the count 
*/


string countAndSay(int n)
{
    // base case
    if(n == 0) return "";
    string result = "1";
    while(--n)
    {
        string curr = "";
        for(int i=0; i<result.size(); i++)
        {
            int count = 1;
            // check for basic condition and if the next number is similar
            while(i+1 < result.size() && result[i] == result[i+1])
            {
                //if yes then increment the count
                count ++;
                i++;
            }
            // convert the count into string
            curr += to_string(count) + result[i];
        }
        result = curr;
    }
    return result;
}


// TC: O(N)
// SC: O(1) -> linear