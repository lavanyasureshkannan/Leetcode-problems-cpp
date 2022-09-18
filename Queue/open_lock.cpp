#include<iostream>
using namespace std;

class Solution 
{
    public:
    int openLock(vector<string>& deadends, string target) 
    {
        queue<string> q;
        unordered_set<string>hash(deadends.begin(),deadends.end());
        unordered_set<string>visited;
        if(hash.find("0000")!=hash.end())
            return -1;
        int level = 0;
        q.push("0000");
        visited.insert("0000");
        while(!q.empty())
        {
            int siz = q.size();
            for(int i =0; i<siz; i++)
            {
                string current_stage = q.front();
                q.pop();
                if(current_stage == target)
                    return level;
                for(int i =0;i<4;i++)
                {                    
                    char temp = current_stage[i];
                    //Moving clockwise first increase 0000 to 1000
                    current_stage[i]=temp == '9'?'0':temp+1;
                    if (hash.find(current_stage) == hash.end() && visited.find(current_stage)==visited.end())
                    {
                        q.push(current_stage);
                        visited.insert(current_stage);
                    }
                    //Moving anticlockwise first increase 0000 to 9000(0-10)
                    current_stage[i]=temp == '0'?'9':temp-1;
                    if (hash.find(current_stage) == hash.end() && visited.find(current_stage) == visited.end())
                    {
                        q.push(current_stage);
                        visited.insert(current_stage);
                    }
                    current_stage[i]=temp;    
                }
            }
            level++;
            
        }
        return -1;
    }
};

//TIME COMPLEXITY: O(N^2 * A^N +D)
//A - number of digits in alphabet
//N- number of digits in lock
//D deadends size

//SPACE COMPLEXITY O(A^N + D) queue and deadend



int main()
{
    return 0;
}