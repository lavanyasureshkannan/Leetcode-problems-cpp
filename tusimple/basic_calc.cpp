#include<iostream>
#include<stack>

int calculate(std::string s)
{
    int result = 0;
    std::stack<int> st;
    int sign = 1;
    int n = s.size();

    // itearte through the string
    for(size_t i = 0; i<n; i++)
    {
        if(isdigit(s[i]))
        {
            int curr_num = 0;
            while(i<n && isdigit(s[i]))
            {
                curr_num = (curr_num * 10) + (s[i] - '0');
                i++;
            }
            // multiply the sign
            curr_num = curr_num * sign;
            result = result + curr_num;
        }
        if(s[i] == '+')
        {
            sign = 1;
        }
        else if(s[i] == '-')
        {
            sign = -1;
        }
        else if(s[i] == '(')
        {
            st.push(result);
            st.push(sign);
            result = 0;
            sign = 1;
        }
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

int main()
{
    std:: cout << calculate("(1+5)-8+(3-2)") << std:: endl;
    return 0;
}

// TC: O(N)
// SC: O(N)
