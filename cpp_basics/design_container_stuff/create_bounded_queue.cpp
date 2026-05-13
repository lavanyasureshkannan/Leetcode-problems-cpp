/*
    enqueue(T item): Adds item. If full, removes front before adding.
    dequeue() -> T: Removes and returns the front element.
    peek() -> T: (Optional) View the front without removing.
    isEmpty() -> bool
    size() -> int
*/

#include <iostream>
#include <queue>
using namespace std;


template<typename T> 
class bounded_queue
{
    private:
    int capacity;
    queue<T> q;

    public:
    bounded_queue(int cap)
    {
        capacity = cap;
    }
    void enqueue(const T& item)
    {
        if(q.size() == capacity)
        {
            q.pop(); // removes the oldest element
        }
        q.push(item);
    }
    T dequeue()
    {
        if(q.empty())
        {
            throw out_of_range("queue is empty");
        }
        T frontitem = q.front();
        q.pop();
        return frontitem;
    }
    bool isEmpty()
    {
        return q.empty();
    }
    int size_of_q()
    {
        return static_cast<int>(q .size());
    }

};

int main()
{
    bounded_queue<int> q_obj(4);
    q_obj.enqueue(10);
    q_obj.enqueue(15);
    q_obj.enqueue(25);
    q_obj.enqueue(35);

    cout << q_obj.size_of_q() << endl;
    while(!q_obj.isEmpty())
    {
        cout << q_obj.dequeue() << endl;
    }
    return 0;
}