#include <iostream>
#include <deque>
#include <thread>
#include <condition_variable>
#include <mutex>
using namespace std;


template <typename T>
class ThreadSafeBuffer
{
    private:
    size_t capacity;
    deque <T> dq;
    mutex mtx;
    condition_variable cv;

    public:
    explicit ThreadSafeBuffer(size_t cap)
    {
        capacity = cap;
    }

    bool isFull() const {return dq.size() == capacity;}

    bool isEmpty() const {return dq.empty();}

    size_t buffer_size() const {return dq.size();}

    void push(T val)
    {
        lock_guard <mutex> lg(mtx);
        if(isFull())
        {
            cout << "BUffer is full. Rewriting the oldest element" << endl;
            dq.pop_front();
        }
        dq.push_back(val);
        cout << "Value pushed inside the buffer: " << val << endl;
        cv.notify_all();
    }

    T pop()
    {
        unique_lock<mutex> lg(mtx);
        while(isEmpty())
        {
            cout << "Buffer is empty. Cannot pop any elements" << endl;
            cv.wait(lg);
        }
        T front_element = dq.front();
        dq.pop_front();
        cout << "Value popped from the buffer is: " << front_element << endl;
        return front_element;
    }

    void producer_func()
    {
        for(int i=1; i<=12; i++)
        {
            push(i * 10);
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }
    void consumer_func()
    {
        for(int i=1; i<=12; i++)
        {
            pop();
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }
};

int main()
{
    ThreadSafeBuffer<int>buffer1(3);
    thread producer(&ThreadSafeBuffer<int>::producer_func, &buffer1);
    thread consumer(&ThreadSafeBuffer<int>::consumer_func, &buffer1);
    producer.join();
    consumer.join();
    return 0;
}