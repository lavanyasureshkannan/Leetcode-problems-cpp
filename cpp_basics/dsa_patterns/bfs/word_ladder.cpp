#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

/*
nput: beginWord = "hit", endWord = "cog", 
    wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
*/

int word_ladder(string beginword, string endword, vector<string>& wordlist)
{
    unordered_set<string> dictionary(wordlist.begin(), wordlist.end());
    if(!dictionary.count(endword)) return 0;
    
    queue<string> q;
    q.push(beginword);
    if(dictionary.count(beginword))
    {
        dictionary.erase(beginword);
    }

    int steps = 1;
    while(!q.empty())
    {
        int q_size = q.size();
        for(int i=0; i<q_size; i++)
        {
            string curr_word = q.front();
            q.pop();
            if(curr_word == endword) return steps;
            for(int s=0; s<curr_word.size(); s++)
            {
                char curr_char = curr_word[s];
                for(char c = 'a'; c<= 'z'; c++)
                {
                    if(c == curr_char) continue;
                    curr_word[s] = c;
                    if(dictionary.count(curr_word))
                    {
                        q.push(curr_word);
                        dictionary.erase(curr_word);
                    }
                }
                curr_word[s] = curr_char;
            }
        }
        steps ++;
    }

    return 0;
}

int main()
{
    string begin_Word = "hit";
    string endword = "cog";
    vector<string>wordlist = {"hot","dot","dog","lot","log","cog"};
    cout << word_ladder(begin_Word, endword, wordlist) << endl;
    return 0;
}
