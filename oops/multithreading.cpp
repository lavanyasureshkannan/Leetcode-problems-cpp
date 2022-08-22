#include<iostream>
#include<thread>
using namespace std;

/*
    Multithreading is a specialized form of multitasking and a multitasking is the feature that allows your computer to run two or more programs concurrently. 
    In general, there are two types of multitasking: process-based and thread-based.

    Process-based multitasking handles the concurrent execution of programs. 
    Thread-based multitasking deals with the concurrent execution of pieces of the same program.

    A multithreaded program contains two or more parts that can run concurrently. 
    Each part of such a program is called a thread, and each thread defines a separate path of execution.
*/

void function1(char symbol)
{
    for(int i=0; i<200; i++)
    {
        cout << symbol;
    }
}

void function2()
{
    for(int i=0; i<200; i++)
    {
        cout << "-";
    }

}

int main()
{
    // the output depends on how fast the thread works
    thread worker1(function1,'+');
    thread worker2(function2);

    worker1.join();
    worker2.join();

    return 0;
}