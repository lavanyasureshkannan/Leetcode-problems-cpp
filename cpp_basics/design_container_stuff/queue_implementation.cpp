#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
    Queue => First In First Out

    Enqueue => Insert elements in the end
    Dequeue => Delete elements from the end
    getFront => get the front element
    isEmpty => returns if the queue is empty
    isFull => returns true if it is fully occupied and no space.

*/

template<typename T>

class Queue
{
    private:

    size_t capacity;
    vector<T> arr;

    public:
    explicit Queue(size_t cap)
    {
        capacity = cap;
        arr.reserve(cap);
    }

    bool isEmpty() const {return arr.empty();}
    bool isFull() const {return arr.size() == capacity;}
    size_t q_size() const{return arr.size();}


    void Enqueue(const T& x)
    {
        if(isFull())
        {
            cout << "Queue is full. Cannot push anymore values" << endl;
            return;
        }
        // insert the elements in the queue
        arr.push_back(x);
        cout << "Value pushed: " << x << endl;
    }

    T getFront() const
    {
        if(isEmpty()) { cout << "Queue is empty. No element can be popped" << endl;}
        T front_element = arr.front();
        cout << "Get front element: " << front_element << endl;
        return front_element;
    }

    T Dequeue()
    {
        if(isEmpty()) { cout << "Queue is empty. No element can be popped" << endl;}
        T front_element = move(arr.front());
        arr.erase(arr.begin());
        cout << "dequeue element: " << front_element << endl;
        return front_element;
    }

};

template<typename T>
class Q_deque
{
    private:
    size_t capacity;
    deque<T> dq;

    public:
    explicit Q_deque(size_t cap)
    {
        capacity = cap;
    }

    bool isEmpty() const { return dq.empty();}
    bool isFull() const { return dq.size() == capacity;}
    size_t dq_size() const { return dq.size();}

    void Enqueue(const T& x)
    {
        if(isFull()) 
        {
            cout << "Deque is full and cannot push more elements" << endl;
            return;
        }
        cout << "Enqueue element: " << x << endl;
        dq.push_back(x);
    }

    T getfront() const
    {
        if(isEmpty()) 
        {
            cout << "Deque is empty, no element found " << endl;
        }
        T front_element = dq.front();
        cout << "Front element is: " << front_element << endl;
        return front_element;
    }

    T dequeue() 
    {
        if(isEmpty()) 
        {
            cout << "Deque is empty, no element found " << endl;
        }
        T front_element = move(dq.front());
        dq.pop_front();
        cout << "Front element is: " << front_element << endl;
        return front_element;
    }
};

int main()
{
    // Queue<int>q(3);
    // q.Enqueue(10);
    // q.Enqueue(20);
    // q.Enqueue(30);

    // q.Dequeue();

    // q.getFront();
    // while(!q.isEmpty())
    // {
    //     q.Dequeue();
    // }


    Q_deque<int> dq1(3);
    dq1.Enqueue(10);
    dq1.Enqueue(20);
    dq1.Enqueue(30);
    dq1.Enqueue(40);

    dq1.getfront();

    dq1.dequeue();
    cout << "................................." << endl;
    while(!dq1.isEmpty())
    {
        dq1.dequeue();
    }
    return 0;
}