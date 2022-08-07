#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


// class Solution {
// public:
//     int calculate(string s) {
        
//     }
// };

class Solution
{
    public:
    int calculate(string s)
    {
        // check if the string is empty or not
        int size = s.size();
        if(size == 0) return 0;
        
        // initialize the variables
        stack<int> stack;
        int curr_num = 0;
        char operation = '+';
        
        // iterate through the string
        for(int i=0; i< size; i++){
            char curr_char = s[i];
            // convert the string to int
            if(isdigit(curr_char)) 
            {
                curr_num = (curr_num * 10) + (curr_char - '0');
            }
            // check if the digit is not integer or white space
            if(!isdigit(curr_char) && !iswspace(curr_char) || i == size -1)
            {
                if(operation == '-')
                {
                    stack.push(-curr_num);
                }
                else if(operation == '+')
                {
                    stack.push(curr_num);
                }
                else if(operation == '*')
                {
                    int stack_top = stack.top();
                    stack.pop();
                    // multiply the curr number with the top of the stak element and push it back
                    stack. push (stack_top * curr_num);
                }
                else if (operation == '/')
                {
                    int stack_top = stack.top();
                    stack.pop();
                    // divide the curr number with the top of the stack element and push it back
                    stack.push (stack_top / curr_num);
                }
                // update the current number and operation
                curr_num = 0;
                operation = curr_char;
            }
        }
        //finally add all the elements in stack
        int result  = 0;
        while(stack.size() != 0)
        {
            result = result + stack.top();
            stack.pop();
        }
        return result;    
    }
};

// TC: O(N) where n is the length of the string ss. We iterate over the string ss at most twice.
// SC: O(N) where n is the length of the string