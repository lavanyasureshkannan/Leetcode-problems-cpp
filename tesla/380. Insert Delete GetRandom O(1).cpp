#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;



// Hashmap provides Insert and Delete in average constant time, although has problems with GetRandom.
// Array List has indexes and could provide Insert and GetRandom in average constant time, though has problems with Delete.

class RandomizedSet
{
    public:
    vector<int> a;
    unordered_map<int,int> mp;
    RandomizedSet()
    {
        // constructor
    }

    bool insert(int val)
    {
        // add both the values in map and array
        if(mp.find(val) != mp.end()) return false; // value exists in the map
        mp[val] = a.size(); // if not add the value manually in the length of array index
        a.push_back(val); // pushing back the value in the array
        return true;
    }

    bool remove (int val)
    {
        // if the value exists in the map then we remove it
        if(mp.find(val) != mp.end())
        {
            // get the index from your map and get the last value and move it to that index
            a[mp[val]] = a.back();
            // assign the last element to your vector
            mp[a.back()] = mp[val];
            // remove from the array and map
            a.pop_back();
            mp.erase(val);
            return true;

        }
        return false;
    }

    int getRandom()
    {
        return a[rand()%a.size()];
    }
};

//TC : GetRandom is always O(1). Insert and Delete both have O(1) average time complexity, and O(N) in the worst-case scenario when the operation exceeds the capacity of currently allocated array/hashmap and invokes space reallocation.
// SC: O(N), to store N elements.