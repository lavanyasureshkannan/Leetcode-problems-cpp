#include<iostream>
#include<unordered_set>
using namespace std;


class MyHashSet 
{
    public:
    unordered_set<int> st;
    MyHashSet() 
    {

    }
    
    void add(int key)
    {
        st.insert(key)
    }
    
    void remove(int key) 
    {
        st.erase(key)
    }
    
    bool contains(int key) 
    {
        if(st.find(key) == st.end()) return false;
        else return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */