#include <iostream>
#include <string>
using namespace std;

int convert_String(string s)
{
    int result = 0;
    int sign = 1;
    int i = 0;
    int n = s.length();

    // 1. handle whitespace
    while(i < n && s[i] == ' ')
    {
        i++;
    }

    // 2. handle negative numbers
    if(i < n && (s[i] == '-'))
    {
        sign = -1;
        i++;
    }
    else if(i < n && (s[i] == '+'))
    {
        sign = 1;
        i++;
    }

    //3. handle numbers
    while(i < n && (s[i] >= '0' && s[i] <= '9'))
    {
        int digit = s[i] - '0';
        // handle overflow cases
        if(result > (INT_MAX - digit) / 10)
        {
            if(sign == 1)
            {
                return INT_MAX;
            }
            else
            {
                return INT_MIN;
            }
        } 
        result = (result * 10) + digit;
        i++;
    }

    return (sign * result);
}

int main()
{
    string s = "-132";
    cout << convert_String(s);
    //cout << INT_MAX;
    return 0;
}

















// int convert_String(string s)
// {
//     int result = 0;
//     int sign = 1;
//     int i = 0;
//     int n = s.length();
//     cout << n << endl;

//     // handle the whitespace
//     while(i < n && s[i] == ' ')
//     {
//         i++;
//     };
//     // sign handle
//     if(i<n && s[i] == '-')
//     {
//         sign = -1;
//         i++;
//     }
//     else if(i<n && s[i] == '+')
//     {
//         sign = 1;
//         i++;
//     }
//     // numbers
//     while(i<n && (s[i] >= '0' && s[i] <= '9'))
//     {
//         int digit = s[i] - '0';
//         // check for overflow before hand
//         if(result > (INT_MAX - digit) / 10)
//         {
//             if(sign == 1) 
//             {
//                 return INT_MAX;
//             }
//             else
//             {
//                 return INT_MIN;
//             }
//         }
//         result = result * 10 + digit;
//         i++;
//     }

//     return (sign * result);
// }
