#include <iostream>
#include <thread>
#include <chrono>
using namespace std;


/*
    1. Main starts
    2. Thread created and starts
    3. Main will wait till thread continous
    4. once thread finishes then main takes over
*/

void print()
{
    cout << "hello from thread" << endl;
    this_thread::sleep_for(chrono::seconds(5));
    cout << "I am done !!" << endl;

}

int main()
{
    cout << "Main starts" << endl;
    thread t1(print);
    t1.join();

    cout << " Main: Doing something else" << endl;
    this_thread::sleep_for(chrono::seconds(5));
    cout << "Main finishes" << endl;
    return 0;
}