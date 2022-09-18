#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+")
            {
                int number2 = st.top();
                st.pop();
                int number1 = st.top();
                st.pop();
                st.push(number1 + number2);
            }
            else if (tokens[i] == "-")
            {
                int number2 = st.top();
                st.pop();
                int number1 = st.top();
                st.pop();
                st.push(number1 - number2);
            }
            else if (tokens[i] == "*")
            {
                long number2 = st.top();
                st.pop();
                long number1 = st.top();
                st.pop();
                st.push(number1 * number2);
            }
            else if (tokens[i] == "/")
            {
                int number2 = st.top();
                st.pop();
                int number1 = st.top();
                st.pop();
                st.push(number1 / number2);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        int result = st.top();
        return result;
    }
};

// TC: O(N)
// SC: O(N)




int main()
{
    return 0;
}