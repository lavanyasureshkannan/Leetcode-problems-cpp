#include<iostream>
#include<thread>
#include<map>
#include<string>
using namespace std;

/*
    Multithreading is a specialized form of multitasking and a multitasking is the feature that allows your computer to run two or more programs concurrently. 
    In general, there are two types of multitasking: process-based and thread-based.

    Process-based multitasking handles the concurrent execution of programs. 
    Thread-based multitasking deals with the concurrent execution of pieces of the same program.

    A multithreaded program contains two or more parts that can run concurrently. 
    Each part of such a program is called a thread, and each thread defines a separate path of execution.
*/

/*
    Real life example of multithreading
    1. create your own data and refresh the weather forecast data every two second
*/

void RefreshForeCast(map<string,int> forecastMap)
{
    while(true)
    {
        for(auto& i: forecastMap)
        {
            // increment the temp for every two seconds
            i.second++;
            cout << i.first << "-" << i.second << endl;
        }
        this_thread::sleep_for(2000ms);
    }
}


int main()
{
    map<string,int> forecastMap = {
        {"Mumbai", 20},
        {"chennai", 30},
        {"bangalore", 50}
    }; 
    thread worker(RefreshForeCast,forecastMap);
    return 0;
}