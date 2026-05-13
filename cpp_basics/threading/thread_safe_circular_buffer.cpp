#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

template <typename T>
class Circular_Buffer
{
    private:
    size_t capacity;
    deque<T> dq;
    mutex mtx;
    condition_variable cv;

    public:
    explicit Circular_Buffer(size_t cap)
    {
        capacity = cap;
    }

    bool isEmpty() const { return dq.empty();}

    bool isFull() const { return dq.size() == capacity;}

    size_t cb_size() const {return dq.size();}

    void Enqueue(const T& val)
    {
        lock_guard<mutex> lg(mtx);
        if(isFull())
        {
            cout << "Removing the oldest elements" << endl;
            dq.pop_back();
        }
        dq.push_back(val);
        cout << "The element pushed is : " << val << endl;
        cv.notify_all();
    }

    void Dequeue()
    {
        unique_lock<mutex> lg(mtx);
        while (isEmpty())
        {
            cout << "CB is empty. Cannot pop any elements";
            cv.wait(lg);
        }
        
        // if(isEmpty())
        // {
        //     throw runtime_error ("Cannot pop any elements. Because cb is empty");
        // }
        T old_element = dq.front();
        dq.pop_front();
        cout << "Oldest Element popped is: " << old_element << endl;
    }

    T get_front()
    {
        lock_guard<mutex> lg(mtx);
        if(isEmpty())
        {
            throw runtime_error ("Cannot pop any elements. Because cb is empty");
        }
        T front_element = dq.front();
        cout << "Front element is: " << front_element << endl;
        return front_element;
    }

    T get_rear()
    {
        lock_guard<mutex> lg(mtx);
        if(isEmpty())
        {
            throw runtime_error ("Cannot pop any elements. Because cb is empty");
        }
        T rear_element = dq.back();
        cout << "Rear element is: " << rear_element << endl;
        return rear_element;
    }

    void producer_func()
    {
        for(int i=1; i<=5; i++)
        {
            Enqueue(i * 10);
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }
    void consumer_func()
    {
        for(int i=1; i<=5; i++)
        {
            Dequeue();
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }
};

int main()
{
    Circular_Buffer<int> cb1(3);
    thread producer(&Circular_Buffer<int>::producer_func, &cb1);
    thread consumer(&Circular_Buffer<int>::consumer_func, &cb1);
    producer.join();
    consumer.join();
    // cb1.Enqueue(10);
    // cb1.Enqueue(20);
    // cb1.Enqueue(30);
    // cb1.Enqueue(40);

    // cb1.Dequeue();
    // cb1.Dequeue();

    // cb1.get_front();
    // cb1.get_rear();

    return 0;
}