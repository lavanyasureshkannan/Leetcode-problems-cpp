#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void backtrack(string& digits, string curr, unordered_map<char, string>& phone_mp, int index, vector<string>& result)
{
    if(index == digits.size())
    {
        result.push_back(curr);
        return;
    }

    char dig = digits[index];  // dig = 2 
    string letter = phone_mp[dig];  // 2 -> abc

    // get all possibilities
    for(char l: letter)
    {
        curr.push_back(l);
        backtrack(digits, curr, phone_mp, index + 1, result);
        curr.pop_back();

    }

}


vector<string> lettercombination(string& digits)
{
    // base case
    if (digits.empty())
    {
        return {};
    }
    // create an unordered_map
    unordered_map<char, string> phone_mp = {{'2', "abc"},
                                            {'3', "def"},
                                            {'4', "ghi"},
                                            {'5', "jkl"},
                                            {'6', "mno"},
                                            {'7', "pqrs"},
                                            {'8', "tuv"},
                                            {'9', "wxyz"}};
    vector<string> result;
    string curr = "";
    backtrack(digits, curr, phone_mp, 0, result);
    return result;

}



int main()
{
    string d = "23";
    vector<string>comb = lettercombination(d);
    for(string c:comb)
    {
        cout << c << " ";
    }
    return 0;
}