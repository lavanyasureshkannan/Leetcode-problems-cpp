#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

/*
    PRODUCER -> func 
    keep adding the incoming data till the buffer is full.

    CONSUMER -> func
    Keep removing the elements from the buffer. 
*/

vector<int> incoming_data = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
vector<int> buffer;
const int MAX_BUFFER = 5;
mutex mtx;
condition_variable cv;

void producer()
{
    for(int i=0; i<incoming_data.size(); i++)
    {
        // lock the buffer
        unique_lock<mutex> uq_lock(mtx);

        // check if the buffer is full
        while(buffer.size() >= MAX_BUFFER)
        {
            // release the lock and wait untill the consumer notifies
            cv.wait(uq_lock);
        }
        buffer.push_back(incoming_data[i]);
        cout << "Producer: " << incoming_data[i] << endl;
        
        uq_lock.unlock(); // unlock the thread
        cv.notify_all(); // tell comsumer that the new item is available
        this_thread::sleep_for(chrono::seconds(2));
    }
}


void consumer()
{   
    int consumed = 0;
    int total_items = incoming_data.size();

    while(consumed < total_items)
    {
        unique_lock<mutex>uq_lock(mtx); // lock the mutex
        while(buffer.empty())
        {
            cv.wait(uq_lock); // unlock here and wait til producer sends signal
        }
        int item = buffer.front();  // get first item
        buffer.erase(buffer.begin()); // remove the first item (FIFO)
        cout << "consumer: " << item << endl;
        consumed ++; // count the consumer

        uq_lock.unlock(); // unlock the buffer
        cv.notify_all(); // tell producer that the buffer has space
        this_thread::sleep_for(chrono::seconds(2));
    }
}

int main()
{
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();
    
    return 0;
}