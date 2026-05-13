#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;


class LRU_Cache
{
    private:
    list<pair<int,int>>cache; // key, value
    unordered_map<int, list<pair<int, int>>::iterator> mp; // key and a pointer to the list 
                                                                // points to (1,10) inside list
    int capacity;

    public:
    LRU_Cache(int cap)
    {
        capacity = cap;
    }

    int get(int key)
    {
        if(mp.find(key) == mp.end()) return -1;
        // move accessed node to the front
        auto it  = mp[key];
        int value = it->second; // {key, value}

        cache.erase(it);
        cache.push_front({key,value});
        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int val)
    {
        // find if it is in the map and erase it 
        if(mp.find(key) != mp.end()) 
        {
            cache.erase(mp[key]);
        }
        else if(cache.size() == capacity)
        {
            // remove the least used 
            auto last_used = cache.back();
            mp.erase(last_used.first);
            cache.pop_back();
        }
        // insert the new val in the front
        cache.push_front({key,val});
        mp[key] = cache.begin();
    }
};

int main()
{
    LRU_Cache lru1(3);
    lru1.put(1,10);
    cout << lru1.get(1) << endl;
    lru1.put(2, 20);  
    lru1.put(3, 30);   
    cout << lru1.get(2) << endl;  
    cout << lru1.get(1) << endl;       
    return 0;
}