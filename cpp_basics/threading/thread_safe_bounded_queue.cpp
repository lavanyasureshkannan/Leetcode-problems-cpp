#include <iostream>
#include <queue>
#include <thread>
#include <condition_variable>
#include <mutex>
using namespace std;


template <typename T>

class Bounded_queue
{
    private:
    queue<T> q;
    size_t capacity;
    mutex mtx;
    condition_variable cv;

    public:
    explicit Bounded_queue(size_t cap)
    {
        capacity = cap;
    }

    bool isFull() 
    {
        //lock_guard<mutex> lg(mtx); 
        return q.size() == capacity; 
    }

    bool isEmpty() 
    {
        //lock_guard<mutex> lg(mtx); 
        return q.empty(); 
    }

    size_t q_size() 
    {
        lock_guard<mutex> lg(mtx); 
        return q.size(); 
    }

    void Enqueue(const T& val)
    {
        lock_guard<mutex> lg(mtx);
        if(isFull())
        {
            cout << "Queue is Full. removing the old element" << endl;
            q.pop();
        }
        q.push(val);
        cout << "Pushed value to the queue: " << val << endl;
        cv.notify_all(); // notify when space is available
    }

    void dequeue()
    {
        unique_lock<mutex> lg(mtx);
        while(isEmpty())
        {
            cout << "Queue is Empty. Waiting for items..." << endl;
            cv.wait(lg);
        }
        T front_element = q.front();
        q.pop();
        cout << "ELement popped from the queue: " << front_element << endl;
    }

    T peek_element()
    {
        lock_guard<mutex> lg(mtx);
        if(isEmpty())
        {
            throw runtime_error("Queue is empty. No front element");
        }
        T front_element = q.front();
        cout << "Current front element is: " << front_element << endl;
        return front_element;
    }

    void producer_func()
    {
        for(int i=0; i<=5; i++)
        {
            Enqueue(i * 10);
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }

    void consumer_func()
    {
        for(int i=0; i<=5; i++)
        {
            dequeue();
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }

};


int main()
{
    Bounded_queue<int>bq1(3);
    thread producer(&Bounded_queue<int>::producer_func, &bq1);
    thread consumer(&Bounded_queue<int>::consumer_func, &bq1);

    producer.join();
    consumer.join();


    // bq1.Enqueue(2);
    // bq1.Enqueue(4);
    // bq1.Enqueue(6);
    // bq1.Enqueue(8);
    // cout << bq1.q_size() << endl;
    // bq1.peek_element();
    // bq1.dequeue();
    // cout << bq1.q_size() << endl;


    
    return 0;
}