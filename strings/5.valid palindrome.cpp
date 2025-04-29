125. Valid Palindrome

class Solution {
public:
bool valid_paranthesis(string s)
{
    string st = " ";
    for(char c : s)
    {
        if(isalnum(c))
        {
            st += tolower(c);
        }
    }

    int left = 0;
    int right = st.size() - 1;
    while(left < right)
    {
        if(st[left] != st[right])
        {
            return false;
        }
        
        left++;
        right--;
        
    }
    return true;
}


};
        
