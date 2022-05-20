#include <iostream>
#include <sstream>
using namespace std;

// convert a integer number to string
string convert_int_str(int num)
{
    string s = to_string(num);
    cout << s << endl;
    return s;
}

// convert a string to integer
int convert_str_int(string s)
{
    int num = stoi(s);
    cout<< num << endl;
    return num;
}

//convert a string to int using STRINGSTREAM
int convert_str_int_ss(string str1)
{
    stringstream ss(str1);
    int x = 0;
    ss >> x;
    cout << x << endl;
    return x;
}

// grab each integer from the string and convert char into int
int cvt_char_int(string st)
{
    int curr_num = 0;
    // iterate through the string
    for(int i = 0; i< st.size(); i++)
    {
        char curr_char = st[i];
        if(isdigit(curr_char))
        {
            curr_num = (curr_num * 10) + (curr_char - '0');
        }
    }
    cout << curr_num << endl; 
    return curr_num;
}


int main()
{
    convert_int_str(40);
    convert_str_int("50");
    cvt_char_int("150");
    convert_str_int_ss("123450");

    return 0;
}
