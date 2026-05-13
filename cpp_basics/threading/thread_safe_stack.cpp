#include <iostream>
#include <stack>
#include <deque>
#include <mutex>
#include <thread>
#include <condition_variable>

using namespace std;

template<typename T>

class Bounded_stack
{
    private:
    deque <T> st;
    size_t capacity;
    mutex mtx;
    condition_variable cv;

    public:
    explicit Bounded_stack(size_t cap)
    {
        capacity = cap;
    }

    bool isEmpty() const {return st.empty();}

    bool isFull() const {return st.size() == capacity;}

    size_t stack_size() const {return st.size();}

    void push(const T& val)
    {
        lock_guard<mutex> lg(mtx);
        if(isFull())
        {
            st.pop_front();
        }
        st.push_back(val);
        cout << "The element pushed inside the stack is: " << val << endl;
        cv.notify_all();
    }

    void pop()
    {
        unique_lock<mutex>lg(mtx);
        while(isEmpty())
        {
            cout << "stack is empty. Cannot pop any elements" << endl;
            cv.wait(lg); // release the lock while waiting
            
        }
        // if(isEmpty())
        // {
        //     throw runtime_error ("stack is empty. Cannot pop any elements");
        //     cv.wait(lg);
        // }
        T top_element = st.back();
        st.pop_back();
        cout << "The element popped from the stack is: " << top_element << endl;
    }
    T peek_element()
    {
        lock_guard<mutex>lg(mtx);
        if(isEmpty())
        {
            throw runtime_error ("stack is empty. Cannot pop any elements");
        }
        T top_element = st.back();
        cout << "The curr top element is: " << top_element << endl;
        return top_element;
    }

    void producer_func()
    {
        for(int i=1; i<=5; i++)
        {
            push(i * 10);
            this_thread::sleep_for(chrono::microseconds(500));
        }
        
    }

    void consumer_func()
    {
        for(int i=1; i<=5; i++)
        {
            pop();
            this_thread::sleep_for(chrono::microseconds(500));
        }
        
    }
};

int main()
{
    Bounded_stack<int> st1(3);
    thread producer(&Bounded_stack<int>::producer_func, &st1);
    thread consumer(&Bounded_stack<int>::consumer_func, &st1);

    producer.join();
    consumer.join();
    // st1.push(20);
    // st1.push(40);
    // st1.push(60);

    // st1.pop();
    // st1.peek_element();
    return 0;
}