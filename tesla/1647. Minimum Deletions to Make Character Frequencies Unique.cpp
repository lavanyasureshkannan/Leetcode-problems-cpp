#include<iostream>
#include<queue>
using namespace std;


/*
Priority Queue-> to keep track of the frequencies
*/
class Solution
{
    public:
    int minDeletions(string s)
    {
        // We store the frequency for a character c at index c - 'a'
        vector<int> freq(26, 0);
        for(char c : s)
        {
            freq[c-'a']++;
        }
        // create and add elements to the priority queue
        priority_queue<int> pq;
        for(int i=0; i<26; i++)
        {
            if(freq[i] > 0)
            {
                pq.push(freq[i]);
            }
        }

        int count = 0;
        while(pq.size() > 1)
        {
            int top = pq.top();
            pq.pop();

            // if the top two elements in thr priorityqueue are same 
            if(top == pq.top())
            {
            // decrement the popped value and push it to the queue
                if(top-1 > 0) 
                {
                    pq.push(top - 1);
                }
                count++;
            }
        }
        return count;

    }
};

// TC: O(N + M^2logM) -> N - number of strings,  M - distinct char
// SC: O(K) -> k is the indices in the list freq and max size of the heap can be K

int main()
{
    return 0;
}