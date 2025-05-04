#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
*/

int wordladder(string beginword, string endword, vector<string>& wordlist)
{
    unordered_set<string> word_set(wordlist.begin(), wordlist.end());
}

int main()
{
    string beginWord = "hit";
    string sendWord = "cog";
    vector<string>wordList = {"hot","dot","dog","lot","log","cog"};
    
    // for(auto s : word_set)
    // {
    //     cout << s << " ";
    // }
    return 0;
}