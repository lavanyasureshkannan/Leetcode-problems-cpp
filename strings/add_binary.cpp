#include<iostream>
using namespace std;

class Solution 
{
public:
    string addBinary(string a, string b) 
    {
        // 0 + 0 = 0
        // 0 + 1 = 1
        // 1 + 0 = 1
        // 1 + 1 = 10
        
        string result;
        int i = a.size() -1;
        int j = b.size() -1;
        int carry = 0;
        
        while(i >= 0 || j >=0 || carry){
            if(i>=0){
                carry += a[i] - '0';
                i--;
            }
            if(j>=0){
                carry +=b[j] - '0';
                j--;
            }
            result += (carry%2 + '0');
            carry = carry/2;
            
        }
        reverse(result.begin(),result.end());;
        return result;
        
    }
};