#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
using namespace std;



/*
    shared_lock -> std::shared_lock is a read-only lock used with std::shared_mutex
        1. It allows multiple threads to read the same data at the same time.
        2. But only one thread can write, and when it does, no other reads or writes are allowed.   
    syntax ->   shared_mutex (instead of plain std::mutex)
                #include <shared_mutex> (C++17 or later)
                shared_lock<shared_mutex> for readers
                unique_lock<shared_mutex> for writers
    ex: Imagine a library:
    📚 Many people can read the same book at once — that’s shared_lock.
    ✍️ But only one librarian can edit the book at a time — that’s unique_lock.

*/


shared_mutex smtx;
int count = 0;

void reader(int id)
{
    shared_lock<shared_mutex> sl(smtx);
     cout << "[Reader " << id << "] reads data = " << count << endl; 
}

void writer(int id)
{
    unique_lock<shared_mutex> sl(smtx);
    count ++;

    cout << "[Writer " << id << "] updated data to " << count << endl;
}


int main()
{
    thread r1(reader, 1);
    thread r2(reader, 2);
    thread r3(reader, 3);
    thread w1(writer, 1);

    r1.join();
    r2.join();
    r3.join();
    w1.join();

}