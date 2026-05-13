#include <iostream>
#include <stack>
using namespace std;

/*
Input: s = "([{}])" 
Output: true
*/

bool valid_paranthesis(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if((c == '[') || (c == '(') || (c == '{')) st.push(c);
        else
        {
            if(st.empty()) return false;
            char top = st.top();
            st.pop();
            if((c == ']') && (top !='[') ||
                (c == '}') && (top !='{') ||
                (c == ')') && (top !='(')) return false;
            }
    }
    return st.empty();
}

int main()
{
    string s = "([{}])" ;
    cout << valid_paranthesis(s) << endl;
    return 0;
}