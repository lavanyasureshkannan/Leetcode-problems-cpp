#include <iostream>
#include <thread>
#include <mutex>
using namespace std;


/*
    1. Creates a thread
    2. When two or more thread try to modify the same gloabl variable then 
    it results in something called race condition.
    3. Race condition can be avoided using mutex. 
    4. No race condition when its local variable.
    5. But when the variable is passed as reference then it causes race condition.


*/

int count = 0;
mutex mtx;

void func1(int &x)
{
    cout << "thread starts func1 ....." << endl;
    mtx.lock();
    for(int i=0; i<1000000; i++)
    {
        count ++;
    }
    cout << "thread func1 ends ....." << endl;
    mtx.unlock();
}


// void func_loc1()
// {
//     int count = 0;
//     for(int i=0; i<5; i++)
//     {
//         count ++;
//         cout << count << endl;
//     }
// }

// void func_loc2()
// {
//     int count = 100;
//     for(int i=0; i<5; i++)
//     {
//         count ++;
//         cout << count << endl;
//     }
// }


int main()
{
    thread t1(func1, ref(count));
    thread t2(func1, ref(count));
    t1.join();
    t2.join();

    cout << count << endl;

    // thread t1(func_loc1);
    // thread t2(func_loc2);

    // t1.join();
    // t2.join();


    return 0;
}