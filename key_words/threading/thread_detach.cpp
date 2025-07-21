#include <iostream>
#include <chrono>
#include <thread>
using namespace std;


/*
    1. Main starts
    2. Thread created and starts
    3. Main will not wait for the thread to finish.
    4. If your main finishes before your thread then your thread is forcefully terminated.
    5. So inorder to avoid that you can use join/condition varibale/ or add a sleep time in your main till your thread finishes.
*/


void print()
{
    cout << "Thread : I am starting" << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "Thread : I am done !!" << endl;
}

int main()
{
    cout << "Main: I am starting" << endl;
    thread t1(print);
    t1.detach();

    cout << " Main: Doing something else" << endl;
    this_thread::sleep_for(chrono::seconds(5));

    cout << "Main finishes !!" << endl;

    return 0;
}