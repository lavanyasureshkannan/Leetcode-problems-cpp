#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRU_Cache 
{
    private:
    
    size_t capacity;
    list<int> usage_order; // back = MRU, front = LRU
    unordered_map<int, pair<int, list<int>::iterator>> cache;

    public:
    
    explicit LRU_Cache(size_t cap) : capacity(cap) {}

    void put(int key, int value) 
    {
        // Key already exists
        if (cache.find(key) != cache.end()) 
        {
            usage_order.erase(cache[key].second); // remove old position
        } 
        // Cache is full
        else if (cache.size() == capacity) 
        {
            int lru_key = usage_order.front(); // least recently used key
            usage_order.pop_front();
            cache.erase(lru_key);
        }

        usage_order.push_back(key); // insert at end -> most recently used
        cache[key] = {value, --usage_order.end()};
    }

    int get(int key) 
    {
        if (cache.find(key) == cache.end())
            return -1;

        // Move this key to the back (most recently used)
        usage_order.erase(cache[key].second);
        usage_order.push_back(key);
        cache[key].second = --usage_order.end();

        return cache[key].first;
    }

    void display() 
    {
        cout << "Cache state (LRU -> MRU): ";
        for (auto k : usage_order)
            cout << k << " ";
        cout << endl;
    }
};

int main() {
    LRU_Cache lru(3);

    lru.put(1, 100);
    lru.put(2, 200);
    lru.put(3, 300);
    lru.display(); // 1 2 3

    lru.get(2); // 2 becomes most recently used
    lru.display(); // 1 3 2

    lru.put(4, 400); // evicts key 1
    lru.display(); // 3 2 4

    cout << "Get key 3: " << lru.get(3) << endl; // returns 300
    lru.display(); // 2 4 3

    return 0;
}
