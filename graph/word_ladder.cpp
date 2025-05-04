#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

/*
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
*/

/*
    1. unordered set => to find the end word easily in o(1) wherease in vector it takes o(n)
    2. base case // no endword
    3. create a queue = {string, steps}
    4. keep popping the word
    5. iterate the word and try all possibilities
*/

int wordladder(string beginword, string endword, vector<string>& wordlist)
{
    //1. unordered set => to find the end word easily in o(1) wherease in vector it takes o(n)
    unordered_set<string> word_set(wordlist.begin(), wordlist.end());
    //2. base case 
    if(word_set.find(endword) == word_set.end()) return 0;
    //3. create a queue = {string, steps}
    queue<pair<string,int>> q;
    q.push({beginword, 1});
    //4. keep popping the word
    while(!q.empty())
    {
        auto [word, steps] = q.front();
        q.pop();

        if(word == endword)
        {
            return steps;
        }
        // 5. iterate the word and try all possibilities
        for(int i=0; i<word.size(); i++)
        {
            string temp = word;
            for(char c = 'a'; c < 'z'; i++)
            {
                temp[i] = c;
                if(word_set.find(temp) != word_set.end())
                {
                    q.push({temp, steps+1});
                }
            }
        }

    }
    return 0;
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