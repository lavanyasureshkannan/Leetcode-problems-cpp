#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>

/*
    Design a thread safe bounded queue
*/

template<typename... Args>
void Log(Args... args)
{
    (std::cout << ... << args) << std::endl;
}

template<typename T>

class Bounded_queue
{
    public:
    explicit Bounded_queue(size_t cap) : capacity(cap) {};

    void Enqueue(T val)
    {
        std::unique_lock<std::mutex> uql(mtx);
        cv.wait(uql, [this] () {
            return q.size() < capacity;
        });  // wait untill there is space available in the queue
        // sleeps when the condition is false and continues when the condition is true
        Log("Produced: ", val);
        q.push(std::move(val)); // no copy just move the val to queue. O(1)
        cv.notify_one();
    }

    T Dequeue()
    {
        std::unique_lock<std::mutex> uql(mtx);
        cv.wait(uql, [this] (){
            return !q.empty();
        });
        T front_element = std::move(q.front());
        q.pop();
        //Log("Removed element", front_element);
        cv.notify_one();
        return front_element;
    }

    private:
    const size_t capacity;
    std::queue<T> q;
    std::mutex mtx;
    std::condition_variable cv;
};


void producer(Bounded_queue<int>& bq)
{
    for(size_t i=0; i<10; i++)
    {
        bq.Enqueue(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer(Bounded_queue<int>& bq)
{
    for(size_t i=0; i<10; i++)
    {
        int val = bq.Dequeue();
        Log("Consumed: " , val);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main()
{
    Bounded_queue<int> bq(5);
    std::thread t1(producer, std::ref(bq));
    std::thread t2(consumer, std::ref(bq));

    t1.join();
    t2.join();
    return 0;
}