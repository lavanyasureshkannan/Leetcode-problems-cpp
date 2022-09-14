#include<iostream>
#include<map>
using namespace std;

/*
Maps are associative containers that store elements in a mapped fashion.
Each element has a key value and a mapped value. No two mapped values can have the same key values.
*/


int main()
{
    map<int, int> mp;
    mp.insert(pair<int,int> (1,50));
    mp.insert(pair<int,int> (2,100));
    mp.insert(pair<int,int> (3,150));
    mp.insert(pair<int,int> (4,200));

    map<int,int> :: iterator itr;
    for(itr= mp.begin(); itr != mp.end(); itr++)
    {
        cout << '\t' << itr->first << '\t' << itr->second << '\n'; 
    }
    cout << endl;

    // remove elements 
    mp.erase(mp.begin(), mp.find(3)); // will remove elements which are less that key = 3
    for(itr= mp.begin(); itr != mp.end(); itr++)
    {
        cout << '\t' << itr->first << '\t' << itr->second << '\n'; 
    }
    return 0;
}