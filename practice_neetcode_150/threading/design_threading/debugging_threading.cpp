#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <queue>

/*
    1. cv.wait(lock, [&], () { return q.empty()}) => all used variables by reference
       cv.wait(lock, [this], () { return q.empty()}) => only the curr object pointer

    2. Why cv.wait requires unique_lock over lockguard ?
        cv requires the ability to unlock and relock the nutex while safely waiting.
        (only cv.wait requires unique_lock)
        cv.wait(lock);
            This does two things internally:
            Atomically release the mutex
            Put the thread to sleep
            Wake up later and re-lock the same mutex

    3.  
    void launch() 
    {
        int local_val = 42;
        std::thread t([local_val]() { std::this_thread::sleep_for( std::chrono::milliseconds(100));
        std::cout << local_val << std::endl;
    });
    t.detach();}  
    "Never capture local variables by reference in a detached thread or any thread that outlives the enclosing scope. 
        Capture by value or use shared_ptr for heap-allocated data."

    4. Is atomic always fast ?
        Not always. under high contention atomic can serialize access and becomes bottleneck.
        lets say you have multiple threads
        t1, t2, t3, t4. cpu ensures only one thread updated memory at a time
        t1 -> update
        t2 -> wait
        t3 -> wait
        t4 -> wait 
        this becomes a sequential process.

    5. Dead lock scenarios => always mention about circular wait
    6. Why std::ref exists? 
        thread copies arg as default. if your takes reference, you must wrap it using
        std::ref, otherwise thread copies it and func modies the copy and not original.

    7. What happens if we dont include join or detach?
        If neither: destructor calls std::terminate() — program aborts. 
        "Terminate called without an active exception" "Aborted error"

        Effective solution, if we forget join or detach:
            using jthread => cpp 20 feature
            Its destructor is programmed to automatically call join() if the thread is still active. 
            This makes your code cleaner and prevents accidental crashes from forgotten join() calls
    
*/


/*****************************************************************************************/
/*
        BUG NAME:  TOCTOU => Time of Check and Time of Use
        Example below.

std::queue<int> q;
std::mutex mtx;

void consumer() 
{
    std::unique_lock<std::mutex> lock(mtx);
    if (!q.empty()) {           // check under lock
        lock.unlock();          // unlock before processing
        int val = q.front();    // BUG
        q.pop();
        process(val);
    }
}

FIX BELOW
*/
std::queue<int> q;
std::mutex mtx;
std::condition_variable cv;
void consumer() 
{
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] () {
        return !q.empty();
    });
    int val = q.front();    
    q.pop();
    process(val);
    
}

/*
    BUG NAME : This is a TOCTOU bug — the check and the use are separated by an unlock, 
                creating a window where another thread can invalidate the condition.
    MECHANISM : The window between lock and unlock can result in the undefined behaviour or crash.
    SCENARIO : Accessing an empty queue can result in undefined behaviour.
    RUNTIME BEHAVIOUR : Works with one consumer more than one can result in undefined behaviour.
    FIX: cv + predicate.
*/



/***************************************************************************************/
/*
            BUG NAME : NOTIFYING WHILE STILL HOLDING THE MUTEX

            Example below

void producer()
{   
    std::unique_lock<std::mutex> lock(mtx);
    data_ready = true;
    cv.notify_one();
}
void consumer() 
{
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { 
        return data_ready; 
    });
    process();
}
*/ 

std::mutex mtx;
std::condition_variable cv;
bool data_ready = false;

void producer() 
{
    //std::lock_guard<std::mutex> lock(mtx);
    {
        std::lock_guard<std::mutex> lock(mtx);
        data_ready = true;
    }
    cv.notify_one();    // notifying while holding lock
}

void consumer() 
{
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { 
        return data_ready; 
    });
    process();
}

/*
    BUG NAME : NOTIFY WHILE HOLDING BUG -> Perfromance based bug
    MECHANISM : 1. Producer locks mtx
                2. Producer sets data_ready = true
                3. Producer calls notify_one — WHILE holding mtx
                4. Consumer wakes up — tries to reacquire mtx
                5. Consumer BLOCKS — producer still holds mtx
                6. Producer releases mtx
                7. Consumer finally acquires mtx — proceeds
                Result: unnecessary block between wakeup and
                proceed context switch wasted — consumer woke up just
                to immediately sleep again
    SCENARIO : Here the wait thread will wake up but cannot proceed untilt the mutex is released.
    RUNTIME BEHAVIOUR : wake thread that immediatly blocks again
    FIX: Use unique_lock instead of lock_guard.
*/

/************************************************************************************/

std::mutex mtx;
std::condition_variable cv;
std::queue<Frame> frame_queue;

void process_frame() 
{
    Frame f;
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return !frame_queue.empty(); });
        f = frame_queue.front();
        frame_queue.pop();
    }
    // Process frame — takes 50ms
    run_detection(f);      // expensive — still holding lock
    run_fusion(f);         // expensive — still holding lock
    publish_result(f);     // expensive — still holding lock
}

/*
    BUG NAME : Lock held too long — excessive lock scope / lock contention
    MECHANISM : other threads cannot come in while it is still holding the lock.
    SCENARIO : frames here waiting can cause frame drops
    RUNTIME BEHAVIOUR : no crash, no undefined behaviour just systematic frame drops.
    FIX: scope and frame f
*/

/*****************************************************************************/
/*
        BUG NAME : ATOMIC TRAP
        Each atomic operation = indivisible
        Sequence of atomic operations = NOT indivisible

        count++        → atomic ✓
        count == 10    → atomic ✓
        count++ then count == 10 → NOT atomic — gap between them ✗

        example :

std::atomic<int> count{0};
std::vector<int> results;
std::mutex vec_mtx;

void worker(int id) {
    // do some work
    int result = compute(id);

    count++;                              // atomic increment

    std::lock_guard<std::mutex> lg(vec_mtx);
    results.push_back(result);

    if (count == 10) {                    // BUG
        publish_results(results);
    }
}
    FIX Below
*/

std::atomic<int> count{0};
std::vector<int> results;
std::mutex vec_mtx;

void worker(int id) 
{
    // do some work
    int result = compute(id);
    count++;                              // atomic increment
    {
        std::lock_guard<std::mutex> lg(vec_mtx);
        results.push_back(result);
        if (count == 10) {                    // BUG
            publish_results(results);
        }
    }
}

/************************************************************************************/
/*
            BUG: NOTIFY ALL VS NOTIFY ONE

    If you have more than one consumer -> notify_all
    If you have only one consumer -> notify_one.
*/
std::queue<Task> q;
std::mutex mtx;
std::condition_variable cv;

void producer(Task t) 
{
    {
        std::lock_guard<std::mutex> lock(mtx);
        q.push(t);
    }
    cv.notify_all();
}

void consumer() 
{
    while (true) 
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return !q.empty(); });
        Task t = std::move(q.front());
        q.pop();
        lock.unlock();
        process(t);
    }
}
