#include<iostream>
#include<unordered_map>
using namespace std;
/*
LRU Cache
LRU -> Least Recently Used
Cache -> Its a memory which stores recently added datas.
The whole point of using cache is to speed up the requests for whatever the resources have been asked for.


lets say,
cache_capacity = 2

-------------
key |   |   |
-------------
val |   |   |
-------------


Doubly linked list -> for storing the relative order of elements
insert things node->next when we delete we can just pop it of from the tail

Hashmap -> for accessing the elements based on the key since you are dealing with get and put operations. 


*/

class LRUCache 
{
public:
    class node 
    {
      public:
        int key;
        int val;
        node* prev;
        node* next;
        
        // constrcutor
        node(int key,int val)
        {
            this->key = key;
            this->val = val;
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    

    int cap;
    unordered_map<int,node*> m;
    
    // constructor for your main class
    LRUCache(int capacity) 
    {
        cap = capacity;
        // connect your head and tail together for the cache
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node* nodeToadd)
    {
        node* temp = head->next;
        nodeToadd->next = temp;
        nodeToadd->prev = head;
        
        head->next = nodeToadd;
        temp->prev = nodeToadd;
    }
    
    void deleteNode(node* nodeTodelete)
    {
        node* delPrev = nodeTodelete->prev;
        node* delNext = nodeTodelete->next;
        
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    

    int get(int key) 
    {
        //If key is already present,then store it and modify it to most recently used and update the key in hasmap                   with new node that is head's next
        if(m.find(key) != m.end()){
            node* resnode = m[key];
            int res = resnode->val;
            m.erase(key);
            deleteNode(resnode);
            addNode(resnode);
            m[key] = head->next;
            return res;
        }
     
        return -1;
    }
    
    void put(int key, int value) 
    {
        // if the key is already present then remove the old one, so that the new can be put for the most recent node
        if(m.find(key) != m.end())
        {
            node* existingnode = m[key];
            // erase it from the map
            m.erase(key);
            // delete it from the linkedlist
            deleteNode(existingnode);
        }
        
        //If capacity is already full, then remove the least recent node, which is tail's prev
        if(m.size() == cap)
        {
            node* lru_node = tail->prev;
            m.erase(lru_node->key);
            deleteNode(lru_node);
        }
        
        //Adding new node to head's next, as the most recent node
        node* newNode = new node(key,value);
        addNode(newNode);
        m[key] = head->next;
    }
};

//TC: O(1) for both put and get
//SC: O(capacity)