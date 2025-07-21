#include <iostream>
#include <thread>
#include <mutex>
using namespace std;


/*
    STARVATION -> 
    Starvation happens when one thread never gets a chance to run because 
    other threads keep taking the resource (like a mutex) again and again and again.
*/
mutex mtx;
bool stop = false;


void func1(int id)
{
    while(!stop)
    {
        if(mtx.try_lock())
        {
            cout << "Greedy Thread " << id << " got the lock!" << endl;
            this_thread::sleep_for(chrono::seconds(2));
            mtx.unlock();
        }
    }
}

void func2()
{
    lock_guard<mutex>lg(mtx);
    for(int i=0; i<5; i++)
    {
        cout << "prints : " << i << endl;
    }
}


/*
    Both thread t1 and t2 tries the lock once it gets free so the thread t3 never gets the chance to get in. 
    Thus t3 is the starvation thread.
*/

int main()
{
    thread t1(func1,1);
    thread t2(func1, 2);
    thread t3(func2);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}