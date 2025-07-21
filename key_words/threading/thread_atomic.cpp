#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>
using namespace std;


/*
    ATOMIC -> You can use atomic instead of mutex. 
    1. You can use atomic only if you need to protect a simple variables like int, bool, long long
    2. It wont work with vectors, maps or other complicated/fancy objects/containers
    3. Its faster, safe, and very easy to implement.
*/

atomic<int> count = 0;
// mutex mtx;

void func1()
{
    // mtx.lock();
    for(int i=0; i<1000000; i++)
    {
        count ++;
    }
    // mtx.unlock();
}

atomic_flag flag = ATOMIC_FLAG_INIT;
int shared = 0;

void func2(int id)
{
    for(int i=0; i<5; i++)
    {
        while(flag.test_and_set()) // if it is false sets to true
        {   

        }
        shared++;
        cout << "Thread " << id << " is running" << endl; 
        flag.clear(); // sets the flag to false
    }

}


int main()
{
    // cout << flag << endl;
    thread t1(func2, 1);
    thread t2(func2, 2);

    t1.join();
    t2.join();

    cout << shared << endl;
    return 0;
}