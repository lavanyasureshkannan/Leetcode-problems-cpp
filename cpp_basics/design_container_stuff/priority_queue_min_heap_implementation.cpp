#include <iostream>
#include <queue>
using namespace std;

/*
MIN HEAP -> Max priority lowest element
*/

template<typename T>
class Priority_Queue
{
    private:
    size_t capacity;
    priority_queue<T, vector<T>, greater<T>> pq;

    public:
    explicit Priority_Queue(size_t cap)
    {
        capacity = cap;
    }

    bool isFull() {return pq.size() == capacity;}
    bool isEmpty() {return pq.empty();}
    size_t q_size() {return pq.size();}

    void Enqueue(const T& x)
    {
        if(isFull())
        {
            cout << "PQ is full and cannot push more element" << endl;
            return;
        }
        pq.push(x);
        cout << "Element Pushed: " << x << endl;
    }

    void dequeue()
    {
        if(isEmpty())
        {
            cout << "PQ is empty and No element to pop" << endl;
            return;
        }
        T top_element = pq.top();
        pq.pop();
        cout << "Element popped: " << top_element << endl;
    }

    T peek_element()
    {
        if(isEmpty())
        {
            cout << "PQ is empty and No element to pop" << endl;
            return T{};
        }
        T top_element = pq.top();
        return top_element;
    }

};
int main()
{
    Priority_Queue<int> pq1(4);
    pq1.Enqueue(10);
    pq1.Enqueue(8);
    pq1.Enqueue(12);
    pq1.Enqueue(15);

    cout << "Peek element: " << pq1.peek_element() << endl;
    cout << "curr size of the queue: " << pq1.q_size() << endl;

    pq1.dequeue();
    cout << "curr size of the queue: " << pq1.q_size() << endl;

    // while(!pq1.isEmpty())
    // {
    //     pq1.peek_element();
    //     pq1.dequeue();
    // }
    return 0;
}