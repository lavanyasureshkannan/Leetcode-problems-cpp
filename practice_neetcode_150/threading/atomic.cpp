#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

template<typename... Args>
void Log(Args... args)
{
    (cout << ... << args) << endl;
}

atomic<int> counter = 0; 

void worker(int id)
{
    for(size_t i = 0; i<100000; i++)
    {
        counter ++;
        cout << "counter update = " << counter << endl; 
        //Log("counter update = ", counter);
    }
}

int main()
{
    thread t1(worker,0);
    thread t2(worker,1);
    t1.join(); 
    t2.join();

    cout << "Final counter = " << counter << endl;
    //Log("Final counter = ", counter);
    return 0;
}