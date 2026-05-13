#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
using namespace std;


// void func()
// {
//     cout << "thread starts" << endl;
//     for(int i=0; i<10; i++)
//     {
//         cout << i << " ";
//     }
//     this_thread::sleep_for(chrono::seconds(5));
//     cout << "thread finishes" << endl;
// }


// int count = 0;
// mutex mtx;

// void func1()
// {
//     mtx.lock();
//     for(int i=0; i<10000000; i++)
//     {
//         count ++;
//     }
//     mtx.unlock();
// }


// void func2()
// {
//     int count = 0;
//     for(int i=0; i<1000000000; i++)
//     {
//         count ++;
//     }
//     cout << count << endl;
// }


// mutex mtx;
// int count = 0;

// void func_lock_g()
// {
//     lock_guard<mutex> lg(mtx);
//     for(int i =0; i<10000000; i++)
//     {
//         count ++;
//     }
// }

// void unique_lock_g()
// {
//     unique_lock<mutex> uql(mtx);
//     for(int i=0; i<1000000; i++)
//     {
//         count ++;
//     }
//     uql.unlock();

// }

// void defer_locks()
// {
//     unique_lock<mutex> uql(mtx, defer_lock);
//     uql.lock();
//     for(int i=0; i<10000000; i++)
//     {
//         count ++;
//     }
//     uql.unlock();

// }

// condition_variable cv;
// mutex mtx;
// int count = 0;
// int target = 100000;
// void func_cv()
// {
//     unique_lock<mutex> uql(mtx);
//     for(int i=0; i<target; i++)
//     {
//         count ++;
//     }
//     cv.notify_one();
// }

// void func_cv2()
// {
//     unique_lock<mutex> uql(mtx);
//     for(int i=0; i<target; i++)
//     {
//         count ++;
//     }
//     while(count < 2 * target)
//     {
//         cv.wait(uql);
//     }
// }

atomic<int> count = 0;

void func_atomic()
{
    for(int i=0; i<100000; i++)
    {
        count ++;
    }
}

int main()
{
    thread t1(func_atomic);
    thread t2(func_atomic);
    t1.join();
    t2.join();
    int con_threads = thread::hardware_concurrency();
    cout << con_threads << endl;
    cout << count << endl;




    // cout << "main starts" << endl;
    // thread t1(func);
    // t1.detach();
    // this_thread::sleep_for(chrono::seconds(3));
    // cout << "main finishes" << endl;
    // return 0;
}