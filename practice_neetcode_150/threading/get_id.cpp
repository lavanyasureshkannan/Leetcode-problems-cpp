#include <iostream>
#include <thread>
using namespace std;

void worker()
{
    this_thread::sleep_for(chrono::milliseconds(200));
    cout << "Thread ID inside worker " << this_thread::get_id() << endl;
}

int main()
{
    int con_threads = thread::hardware_concurrency();
    cout << con_threads << endl;
    // cout << "Main thread ID: " << this_thread::get_id() << endl;
    // thread t1(worker);
    // thread t2(worker);
    // t1.join();
    // t2.join();
    return 0;
}