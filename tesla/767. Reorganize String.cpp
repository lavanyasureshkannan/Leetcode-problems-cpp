#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

/*
    "aab" => "aba"
    1. To keep track of the character frequencies => unordered_map
    2. data structure to keep track of how often it occurs => priority_queue
*/

string reorganizeString(string s)
{
    string result = "";
    unordered_map<char, int> mp;
    priority_queue<pair<int, char>> pq;

    // iterate through the string and the characters and frequencies in the map
    for(int i=0; i<s.length(); i++)
    {
        mp[s[i]] ++
    }
    // push the prioritised elements in the queue
    for(auto it=mp.begin(); it!=mp.end(); it++)
    {
        pq.push({it->second, it->first});
    }

    while(pq.size() > 1)
    {
        // Now take two elements from the heap and do this till the map becomes size 1
        // why one : cause we are taking two top elements like pq.top is a then will pop and again pq.top is b and will add to answer
        // most frequently used
        auto top1 = pq.top();
        pq.pop();

        // second most frequently used
        auto top2 = pq.top();
        pq.pop();

        // add that to result
        result = result + top1.second;
        result = result + top2.second;

        // then you just decrement the frequecy
        top1.first --;
        top2.first --;

        // if it still more than 1 then just push_back the element to the pq
        if(top1.first >= 1) pq.push(top1);
        if(top2.first >= 1) pq.push(top2);
    }

    // if it the combo is not possible
    if(!pq.empty()) 
    {
        if(pq.top().first >= 2) return "";
        else result = result + pq.top().second; 
    }

    return result;
}


// TC: O(NlogN) -> adding elements in map and priority queue (logn)
// SC: O(n) -> map and priority queue