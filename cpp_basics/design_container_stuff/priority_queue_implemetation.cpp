#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

/*
    MAX HEAP -> Max priority highest element.
*/

// PRIORITY QUEUE Implementation

template<typename T>
class Priority_Queue
{
    private:
    size_t capacity;
    priority_queue<T> pq;

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


// Priority Queue using vector array

class PQ_array
{
    private:
    vector<int> pq_arr;
    size_t capacity;

    public:
    PQ_array(size_t cap)
    {
        capacity = cap;
        pq_arr.reserve(cap);
    }

    bool isFull() {return pq_arr.size() == capacity;}
    bool isEmpty() {return pq_arr.empty();}
    size_t pq_size() {return pq_arr.size();}

    void enqueue(int x)
    {
        if(isFull())
        {
            cout << "PQ is full. No more elements can be pushed" << endl;
            return;
        }
        pq_arr.push_back(x);
        cout << "Element pushed: " << x << endl;
    }

    int peek_element()
    {
        int max_value = *max_element(pq_arr.begin(), pq_arr.end());
        return max_value;
    }

    void dequeue()
    {
        if(isEmpty())
        {
            cout << "PQ is empty. Cannot pop any elements" << endl;
            return;
        }
        auto it = max_element(pq_arr.begin(), pq_arr.end());
        cout << "Element removed: " << *it << endl;
        pq_arr.erase(it);
    }
};

int main()
{
    PQ_array pq2(4);
    pq2.enqueue(10);
    pq2.enqueue(8);
    pq2.enqueue(12);
    pq2.enqueue(15);

    cout << "Peak element : " << pq2.peek_element() << endl;
    pq2.dequeue();



}




// int main()
// {
//     Priority_Queue<int> pq1(4);
//     pq1.Enqueue(10);
//     pq1.Enqueue(8);
//     pq1.Enqueue(12);
//     pq1.Enqueue(15);

//     cout << "Peek element: " << pq1.peek_element() << endl;
//     cout << "curr size of the queue: " << pq1.q_size() << endl;

//     pq1.dequeue();
//     cout << "curr size of the queue: " << pq1.q_size() << endl;
//     // while(!pq1.isEmpty())
//     // {
//     //     pq1.peek_element();
//     //     pq1.dequeue();
//     // }
// }


// int main()
// {
//     priority_queue<int> max_pq; // max heap
//     max_pq.push(10);
//     max_pq.push(12);
//     max_pq.push(15);
//     max_pq.push(18);

//     max_pq.pop();
//     while(!max_pq.empty())
//     {
//         cout << max_pq.top() << " " << endl;
//         max_pq.pop();
//     }
//     return 0;
// }