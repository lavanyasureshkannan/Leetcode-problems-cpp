#include<iostream>
#include<stack>
#include <string.h>
using namespace std;

int calculate(string s) 
{
    // base case
    if (s.size() == 0) 
    {
        return 0;
    }
    stack<int> st;
    char operation = '+'; 
    long curr_num = 0;
    int result = 0;
    
    for (int i = 0; i< s.size(); i++) 
    {
        char curr_char = s[i];
	    // Step 1. calculate the current number you meet. have a recursive call the func encounter a parenthese
        if (isdigit(curr_char)) 
        {
            curr_num = (curr_num * 10) + long(curr_char - '0');
        }
        else if (curr_char == '(') 
        {
            int j = i + 1; 
            int brackets = 1;
            while (brackets > 0) 
            {
                if (s[j] == '(')
                    brackets++;
                else if (s[j] ==')')
                    brackets--;
                j++;
            }
            
            int length = (j-1) - i ;
            curr_num = calculate(s.substr(i + 1, length));
            // pointer to the last calculated character
            i = j-1;  
        }
        
		// Step 2.  push the current number inside your stack based on the **last sign** you meet
        if (curr_char == '+' || curr_char == '-' || curr_char == '*' || curr_char == '/' || i == s.size() - 1) 
        {
            switch (operation) 
            {
                case '+':
                    st.push(curr_num);
                    break;
                case '-':
                    st.push(-curr_num);
                    break;
                case '*': 
                {
                    int top = st.top();
                    st.pop();
                    st.push(top * curr_num);
                    break;                        
                }
                case '/': 
                {
                    int top = st.top();
                    st.pop();
                    st.push(top / curr_num);
                    break;                        
                }
            }
            // assign new operator 
            operation = curr_char;
            // reset the current number  
            curr_num = 0; 
        }
    }
    
	// Step 3.  sum up all the numbers you have meet by poping elements from the stack
    int result = 0;
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}

int main()
{
    return 0;
}

// TC: O(N) -> length of the strings
// SC: O(N) -> stack