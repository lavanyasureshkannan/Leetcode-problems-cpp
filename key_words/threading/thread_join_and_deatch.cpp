#include<iostream>
#include<thread>
#include<chrono>
#include<ctime>
using namespace std;

/*
    JOIN
   -> Join in threading means, once the thread is started we wait for this thread to finish by calling the join() function on the thread.
   -> If needed we should check the thread if it is joinable before joining.

    DETACH
    -> It is used to detach the newly created thread from its parent thread. 
    -> When you detach thread it means that you don't have to join() it before exiting main().
*/

void display(int a)
{
    while(a --> 0)
    {
        cout << "Hello world" << endl;
    }
}

int main()
{
    thread t1(display, 10);
    //t1.join(); // this will let the program finish its thread and then execute
    cout << "program starts" << endl;

    t1.detach(); // In this case the output will be the two print statements
                 // you are creating a thread t1, then the OS will take time to start the thread
                 // Meanwhile you are detaching the thread 
                 // which means your detach is not letting your program start the thread  
    cout << " program ends" << endl;


    return 0;
}