#include<iostream>
#include<unordered_map>
using namespace std;

class MyHashMap
{
    public:
    unordered_map<int, int> mp;
    MyHashMap()
    {

    }

    void put(int key, int value)
    {
        mp[key] = value;
    }

    int get(int key)
    {
        if(mp.find(key) == mp.end()) return -1;
        else return mp[key];
    }

    void remove(int key)
    {
        mp.erase(key);
    }
};


int main()
{
    return 0;
}