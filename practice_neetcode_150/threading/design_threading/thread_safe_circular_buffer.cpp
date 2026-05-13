#include <iostream>
#include <deque>
#include <mutex>
#include <condition_variable>
#include <thread>

/*
    Design a circular buffer
*/

template<typename... Args>
void Log(Args... args)
{
    (std::cout << ... << args) << std::endl;
}


template<typename T>
class Circular_Buffer
{
    public:
    explicit Circular_Buffer(size_t cap) : capacity(cap) {};

    void Enqueue(T val)
    {
        std::unique_lock<std::mutex> uql(mtx);
        cv.wait(uql,[this] ()
        {
            return dq.size() < capacity;
        });
        
        Log("Produced val: ", val);
        dq.push_back(std::move(val));
        cv.notify_one();
    }

    T dequeue()
    {
        std::unique_lock<std::mutex> uql(mtx);
        cv.wait(uql, [this] ()
        {
            return !dq.empty();
        });
    
        T old_element = std::move(dq.front());
        dq.pop_front();
        cv.notify_one();
        return old_element;
    }
    
    private:
    std::deque<T> dq;
    const size_t capacity;
    std::mutex mtx;
    std::condition_variable cv;
};

void producer(Circular_Buffer<int>&cb1)
{
    for(size_t i=0; i<20; i++)
    {
        cb1.Enqueue(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer(Circular_Buffer<int>&cb1)
{
    for(size_t i=0; i<20; i++)
    {
        int val = cb1.dequeue();
        Log("Consumed val: ", val);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}


int main()
{
    Circular_Buffer<int> cb(5);
    std::thread t1(producer, std::ref(cb));
    std::thread t2(consumer, std::ref(cb));

    t1.join();
    t2.join();
    return 0;
}