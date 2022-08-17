#include<iostream>
#include<stack>
using namespace std;


/*
 // use stack 
 // iterate through the string
 // keep updating the sign and result
 // keep track of the paranthesis
*/


class Solution 
{
    public:
    int calculate(string s) 
    {
        stack<int> st;
        int result = 0;
        int sign = 1;
        
        int n = s.length();

        for(int i = 0; i < n; i++) 
        {    
            if(isdigit(s[i])) 
            {
                int curr_num = 0;
                // collect the digit and multiply it with current sign and add into the res
                while(i < n && isdigit(s[i])) 
                {
                    curr_num = curr_num * 10 + (s[i] - '0');
                    i ++;
                }
                i --;
                curr_num = sign * curr_num;
                result = result + curr_num;
                sign = 1;
            }
            else if(s[i] == '+') 
            {
                sign = 1;
            } 
            else if(s[i] == '-') 
            {
                sign = -1;
            } 
            // if current char is '(', then push the res & sign, and reinitialize res as 0, and sign as 1(positive)
            else if(s[i] == '(') 
            {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } 
            // if current char is ')', then multiply the res with sign(immediate top of the stack),
            //  and add the res(next top of the stack), and simultaneously pop the value from stack as well
            else if(s[i] == ')') 
            {
                result = result * st.top();
                st.pop();
                result = result + st.top();
                st.pop();
                sign = 1;
            }
        }
        
        return result;
    }
};
