#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>
using namespace std;

queue<int> q;
condition_variable cv;

template<typename... Args>
void Log(Args... args)
{
    (cout << ... << args) << endl;
}

mutex m;
bool is_ready = false;


void producer()
{
    for(size_t i = 0; i<10; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(200));
        {
            lock_guard<mutex> lock(m);
            q.push(i);
            Log("Pushed = ", i);
        }
        cv.notify_one();
    }
    {
        lock_guard<mutex> lock(m);
        is_ready = true;
    }
    cv.notify_one();

}

void consumer()
{
    while(true)
    {
        unique_lock<mutex>lock(m);
         cv.wait(lock, [] {
            return !q.empty() || is_ready; // if q.empty() = false then go to sleep
                                // if true continue with execution
        });
        // if(!q.empty())
        // {
        if(q.empty() && is_ready) 
        {
            Log("consumer existing");
            break;
        }
        int val = q.front();
        q.pop();
        Log("Popped value = ", val);
        // }
    }
}

int main()
{
    thread producer_thread(producer);
    thread consumer_thread(consumer);
    producer_thread.join();
    consumer_thread.join();
    return 0;
}