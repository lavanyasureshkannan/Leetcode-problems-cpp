#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
using namespace std;

/*
    condition variable -> It's a tool that helps one thread wait until another thread says “go!
*/

mutex mtx;
int count = 0;
int target = 1000000;
condition_variable cv;

void func1()
{
    cout << "func 1 starts" << endl;
    this_thread::sleep_for(chrono::seconds(3));
    unique_lock<mutex> lg(mtx);
    for(int i =0; i < target; i++)
    {
        count ++;
    }
    cv.notify_one();
    cout << "func 1 ends " << endl;
}

// void func2()
// {
//     cout << "func 2 starts" << endl;
//     unique_lock<mutex> ul(mtx);
//     while(count < target)
//     {
//         cv.wait(ul); // releases the lock
//     }
//     cout << "func 2 ends" << endl;
// }

void func2()
{
    cout << "func 2 starts" << endl;
    unique_lock<mutex> ul(mtx); // mutex is locked 
    for(int i=0; i < target; i++)
    {
        count ++;
    }
    while(count < 2*target)
    {
        cv.wait(ul); // it sleeps here until someone notify
    }
    cout << "func 2 ends" << endl;
}

int main()
{
    thread t1(func1); // increment thread
    thread t2(func2); // waiting thread
    t1.join();
    t2.join();
    cout << count << endl;
    return 0;
}