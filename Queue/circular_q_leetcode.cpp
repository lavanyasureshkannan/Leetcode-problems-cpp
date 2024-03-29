// create a class of queue
#include<iostream>
#include<vector>
using namespace std;

class MyCircularQueue 
{
    private:
    
    vector<int> cir_Q;
    int f;
    int r;
    int max_size;
    int len = 0;
    
    public:
    MyCircularQueue(int k) 
    {
        f = 0;
        r = 0;
        max_size = k;
        // initially assigning all the value to -1
        cir_Q.assign (k, -1);
    }
    
    bool enQueue(int value) 
    {
        if(isFull()) return false;
        len++;
        cir_Q[r] = value;
        r++;
        // keeping the rear in track
        r %= max_size;
        return true;
    }
    
    bool deQueue() 
    {
        if(isEmpty()) return false;
        len--;
        cir_Q[f] = -1;
        f = (f+1) % max_size;
        return true;
    }
    
    int Front() 
    {
        if(isEmpty()) return -1;
        return cir_Q[f];
    }
    
    int Rear() 
    {
        if(isEmpty()) return -1;
        int index = r - 1;
        if(index < 0)
        {
            index = index + max_size;
        }
        return cir_Q[index];
    }
    
    bool isEmpty() 
    {
        if(len == 0) return true;
        else return false;
    }
    
    bool isFull() 
    {
        if(len == max_size) return true;
        else return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */