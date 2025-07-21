#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

/*
    Deadlock : It is a condition where one thread waits for the other to finish but for some reason it never finishes and 
    stuck in a loop forever.
*/


// mutex mtx;
// int count = 0;
// void func1(int id)
// {
//     mtx.lock();
//     cout << "Thread " << id << "running" << endl;
//     this_thread::sleep_for(chrono::seconds(3));
//     for(int i=0; i<10000; i++)
//     {
//         count ++;
//     }
//    // mtx.unlock();
//     cout << "Thread " << id << "end ... " << endl;
// }




// int main()
// {
//     thread t1(func1, 1);
//     thread t2(func1, 2);
//     t1.join();
//     t2.join();

//     cout << count << endl;
//     return 0;
// }



mutex mtx1;
mutex mtx2;

void func1(int id)
{
    lock_guard<mutex> lg1(mtx1);
    cout << "Thread " << id << " running " << endl;

    this_thread::sleep_for(chrono::seconds(3));
    
    lock_guard<mutex> lg2(mtx2);
    cout << "Thread " << id << " ends .... " << endl;
}

void func2(int id)
{
    cout << "Thread " << id << " running " << endl;
    lock_guard<mutex> lg1(mtx2);
    this_thread::sleep_for(chrono::seconds(3));

    lock_guard<mutex> lg2(mtx1);
    cout << "Thread " << id << " ends .... " << endl;
}

int main()
{
    thread t1(func1, 1);
    thread t2(func2, 2);
    t1.join();
    t2.join();
}