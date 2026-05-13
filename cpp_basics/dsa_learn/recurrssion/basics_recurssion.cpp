#include <iostream>
#include <algorithm>
using namespace std;

/*
1. print a string in reverse
*/

void reverse_string(string s)
{
    string result = "";
    for(int i=s.size(); i>=0; i--)
    {
        result += s[i];
    }
    cout << result << endl;
}

void reverse_two_pointer(string s)
{
    int left = 0;
    int right = s.size() -1;
    while(left < right)
    {
        swap(s[left], s[right]);
        left++;
        right--;
    }
    cout << s << endl;
}

/*
    NOW USING RECURSSION
    1. Every recurssion has Base case (when to STOP)
    2. Recurssive case (INFINITE LOOP)
*/

void reverse_recursion(string& s, int left, int right)
{
    // base case
    if(left >= right) return;
    // main function
    swap(s[left], s[right]);
    // recursive call
    reverse_recursion(s, left+1, right-1);
}


int main()
{
    string s = "STRING";
    //reverse_string(s);
    //reverse_two_pointer(s);
    reverse_recursion(s, 0, s.size()-1);
    cout << s << endl;
    return 0;
}