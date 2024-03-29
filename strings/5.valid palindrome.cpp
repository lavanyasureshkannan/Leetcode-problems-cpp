125. Valid Palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.length();
        // create a string
        string st;
        // check for the valid characters
        for (int i=0;i<size;i++){
            if(s[i]>='A'&& s[i]<='Z'){
                st+=tolower(s[i]); // tolower is to convert into lower case
            }
            if(s[i]>='a' && s[i]<='z'){
                st+=s[i];
            }
            if(s[i]>='0' && s[i] <='9'){
                st+=s[i];
            }
        }
        // use two pointer technique
        int left =0;
        int right = st.length() - 1;
        while(left<right){
            if(st[left]!=st[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
        
