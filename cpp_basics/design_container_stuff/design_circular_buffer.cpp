#include <iostream>
#include <vector>
using namespace std;

class Circular_Buffer
{
    private:
    vector<int> buffer;
    int front; // read
    int back; // write
    int capacity;
    int size;

    public:
    Circular_Buffer(int _capacity)
    {
        capacity = _capacity;
        front = 0;
        back = 0;
        size = 0;
        buffer = vector<int>(capacity);
    }

    // check if the buffer is empty
    bool isEmpty()
    {
        return (size == 0);
    }
    // check if its full
    bool isFull()
    {
        return (size == capacity);
    }
    // get front
    int get_front()
    {
        if(buffer.empty())
        {
            throw out_of_range("circular buffer is empty");
        }
        return buffer[front];
    }
    // get back
    int get_back()
    {
        if(isEmpty())
        {
            throw out_of_range("Circular buffer is empty");
        }

        if(back == 0)
        {
            return buffer[capacity-1];
        }
        else
        {
            return buffer[back-1];
        }
    }
    //
    void add_element(int val)
    {
        if(isFull())
        {
            throw overflow_error("BUffer is full");
        }
        buffer[back] = val;
        back = (back+1) % capacity; 
        size ++;
    }

    void remove_element()
    {
        if(isEmpty())
        {
            throw underflow_error("Buffer is empty");
        }
        front = (front+1) % capacity;
        size --;
    }
};

int main()
{
    Circular_Buffer obj_cb1(5);
    obj_cb1.add_element(10);
    obj_cb1.add_element(20);
    obj_cb1.add_element(30);
    obj_cb1.add_element(40);
    obj_cb1.add_element(50);

    obj_cb1.remove_element();

}