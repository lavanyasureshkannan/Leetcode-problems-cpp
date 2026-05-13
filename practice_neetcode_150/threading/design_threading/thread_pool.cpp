#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <atomic>

/*
    THREAD POOL
    A group of worker threads, that are established at the start of the program and 
    stored in a pool to be used later are called thread pools.
    
    The Thread Pool effectively maintains and allocates existing threads to do several tasks concurrently, 
    saving time compared to starting a new thread for each activity.

    What you need to create a thread pool?
        Queue => take the tasks
        Fixed number of thread => hardware concurrency
        synchronization => mutex, condition variable
*/

template<typename... Args>
void Log(Args... args)
{
    (std::cout << ... << args) << std::endl;
}

class Thread_pool
{
    public:
    Thread_pool(size_t num_threads = std::thread::hardware_concurrency())
    {
        // to create your worker threads
        for(size_t i=0; i<num_threads; i++)
        {
            workers_threads.push_back(std::thread{[this]{worker();}});
        }
    }

    void enqueue(std::function<void()> task)
    {
        //push the task
        {
            std::unique_lock<std::mutex> uql(q_mutex);
            tasks_queue.push(std::move(task));
        }
        // and notify other workers
        cv.notify_one();
    }
    
    ~Thread_pool()
    {
        // lock the queue to update the flag
        {
            std::unique_lock<std::mutex> uql(q_mutex);
            stop = true;
        }
        // notify all threads
        cv.notify_all();
        // join all for completed tasks
        for(auto &thread :workers_threads)
        {
            thread.join();
        }
    }
    
    private:
    std::vector<std::thread> workers_threads;
    std::queue<std::function<void()>> tasks_queue;
    std::mutex q_mutex;
    std::condition_variable cv;
    std::atomic<bool> stop = {false};
    void worker()
    {
        while(true)
        {
            std::function<void()> task;
            {
                std::unique_lock<std::mutex> uql(q_mutex);
                cv.wait(uql, [this] ()
                {
                    return !tasks_queue.empty() || stop;
                });
                if(tasks_queue.empty() && stop) return;
                task = std::move(tasks_queue.front());
                tasks_queue.pop();
            }
            task();
        }
    }
};

void dummy(size_t id)
{
    Log("Task", id, " is running on thread: ", std::this_thread::get_id());
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}


int main()
{
    Thread_pool pool(5);
    for(size_t i=0; i<5; i++)
    {
        pool.enqueue([i]{ dummy(i);});
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    return 0;
}