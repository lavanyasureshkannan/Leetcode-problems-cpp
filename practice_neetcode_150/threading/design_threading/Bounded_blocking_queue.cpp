#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

/*
Input:
1
1
["BoundedBlockingQueue","enqueue","dequeue","dequeue","enqueue","enqueue","enqueue","enqueue","dequeue"]
[[2],[1],[],[],[0],[2],[3],[4],[]]

Output:
[1,0,2,2]

Explanation:
Number of producer threads = 1
Number of consumer threads = 1

BoundedBlockingQueue queue = new BoundedBlockingQueue(2);   // initialize the queue with capacity = 2.

queue.enqueue(1);   // The producer thread enqueues 1 to the queue.
queue.dequeue();    // The consumer thread calls dequeue and returns 1 from the queue.
queue.dequeue();    // Since the queue is empty, the consumer thread is blocked.
queue.enqueue(0);   // The producer thread enqueues 0 to the queue. The consumer thread is unblocked and returns 0 from the queue.
queue.enqueue(2);   // The producer thread enqueues 2 to the queue.
queue.enqueue(3);   // The producer thread enqueues 3 to the queue.
queue.enqueue(4);   // The producer thread is blocked because the queue's capacity (2) is reached.
queue.dequeue();    // The consumer thread returns 2 from the queue. The producer thread is unblocked and enqueues 4 to the queue.
queue.size();       // 2 elements remaining in the queue. size() is always called at the end of each test case.
*/

template<typename... Args>
void Log(Args... args)
{
    (std::cout << ... << args) << std::endl;
}

template<typename T>

class BoundedBlockingQueue
{
    public:
    BoundedBlockingQueue(size_t cap) : capacity(cap) {};

    void enqueue(T val)
    {
        {
            std::unique_lock<std::mutex> uql(mtx);
            cv.wait(uql, [this] () {
                return q.size() < capacity;
            }) ;
            q.push(std::move(val));
            Log("Enqueued val ", val);
        }
        cv.notify_one();
    }

    T dequeue()
    {
        T front_val;
        {
            std::unique_lock<std::mutex> uql(mtx);
            cv.wait(uql, [this] () {
                return !q.empty();
            });
            front_val = std::move(q.front());
            Log("Dequeued val: ", front_val);
            q.pop();
        }
        cv.notify_one();
        return front_val;
    }

    size_t size()
    {
        std::lock_guard<std::mutex> lg(mtx);
        return q.size(); 
    }

    private:
    std::queue<T> q;
    std::mutex mtx;
    std::condition_variable cv;
    size_t capacity;
};

void producer(BoundedBlockingQueue<int>& bq)
{
    for(size_t i=0; i<5; i++)
    {
        bq.enqueue(i);
    }
}

void consumer(BoundedBlockingQueue<int>& bq)
{
    for(size_t i=0; i<5; i++)
    {
        bq.dequeue();
    }
}

int main()
{
    BoundedBlockingQueue<int> bq(3);
    std::thread t1(producer, std::ref(bq));
    std::thread t2(consumer, std::ref(bq));

    t1.join();
    t2.join();
    return 0;
}