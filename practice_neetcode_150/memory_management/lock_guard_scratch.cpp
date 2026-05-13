#include <iostream>
#include <mutex>
#include <thread>

template<typename T>
class LockGuard
{
    private:
    T& mutex_ref;
    // constructor locks upon object creation
    public:
    explicit LockGuard(T& mtx) : mutex_ref(mtx)
    {
        mutex_ref.lock();
    }
    // destrcutor unlocks upon object destruction
    ~LockGuard()
    {
        mutex_ref.unlock();
    }
    // disable copying
    LockGuard(const LockGuard&) = delete;
    LockGuard &operator = (const LockGuard&) = delete;

    /*
    "why no move":
    "A lock_guard is scope-bound by design — it locks when created and unlocks when that scope exits. 
    Allowing move would mean transferring responsibility for the lock to a different scope, 
    which breaks the RAII guarantee and makes the unlock point unpredictable. 
    unique_ptr allows move because ownership can legitimately transfer between scopes. A lock cannot."

    */
};

std::mutex mtx;
    
int counter = 0;
void increment()
{
    for(size_t i=0; i<10; i++)
    {
        LockGuard<std::mutex> lg(mtx);
        counter ++;
        std::cout << "counter val: " << counter << std::endl;
    }
}


int main()
{
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();
    return 0;
}