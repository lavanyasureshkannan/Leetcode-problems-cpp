#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <atomic>
#include <condition_variable>
using namespace std;

/*
    Join -> the main func will wait for thread to finish.
    detach -> the main will not wait for the thread to end.
               if main ends before thread then thread is forcefully shut down 
    Mutex -> mutex is a synchronization primitive that is used to protect data from race condition.
    atomic -> Its a variable that you can use when you dont want to use mutex
    lock_guard -> Its a wrapper for mutex that gets 
                  locked and unlocked automtatically when the onject goes out of scope.
    unique_lock -> Its almost same as lock_guard except that you can manually lock, unlock, 
                  defer_lock, change ownership and all those.
    shared_lock -> Its a read only lock used with shared_mutex
                   it allows many thread to read but let only one thread to write.
    condition_variable -> Its needed in cases where one thread should wait for the other thread to finish its tasks and
                    notify the thread.

                        Lost wakeup – a notification arrives before the thread starts waiting.
                        Spurious wakeup – the thread wakes up without any notification.
    

*/


////////////////////////////// JOIN ////////////////////////////////////////
void func1()
{
    cout << " thread for func1 starts..." << endl;
    this_thread::sleep_for(chrono::seconds(5));
    cout << " thread for func1 ends.." << endl;
}

// int main()
// {
//     thread t1(func1);
//     thread t2(func1);
//     cout << "Main starts .. " << endl;
//     this_thread::sleep_for(chrono::seconds(3));
//     t1.join();
//     t2.join();
// }

////////////////////////////////// detach /////////////////////////////////////
void func2()
{
    cout << " thread for func2 starts..." << endl;
    this_thread::sleep_for(chrono::seconds(5));
    cout << " thread for func2 ends.." << endl;
}

// int main()
// {
//     thread t1(func2);
//     thread t2(func2);
//     cout << "Main starts .. " << endl;
//     this_thread::sleep_for(chrono::seconds(3));
//     cout << "Main ends .." << endl;
//     t1.detach();
//     t2.detach();
    
// }

/////////////////////// mutex ///////////////////////////

// int count = 0;
// mutex mtx;
// void func3()
// {
//     mtx.lock();
//     for(int i=0; i<1000000; i++)
//     {
//         count ++;
//     }
//     mtx.unlock();
// }

// int main()
// {
//     thread t1(func3);
//     thread t2(func3);
//     t1.join();
//     t2.join();
//     cout << count << endl;
// }

//////////////////////////////////// lock_guard /////////////////////////////

// int shared = 0;
// mutex mtx1;

// void func4()
// {
//     lock_guard<mutex> lg(mtx);
//     for(int i=0; i<100000; i++)
//     {
//         shared ++;
//     }
// }

// int main()
// {
//     thread t1(func4);
//     thread t2(func4);
//     t1.join();
//     t2.join();
//     cout << shared << endl;
// }


/////////////////////////// unique_lock ////////////////
// int shared = 0;
// mutex mtx2;

// void func5()
// {
//     unique_lock<mutex> uq_l(mtx, defer_lock);
//     this_thread::sleep_for(chrono::seconds(3));
//     uq_l.lock();
//     for(int i=0; i<1000000; i++)
//     {
//         shared ++;
//     }
//     uq_l.unlock();
// }

// int main()
// {
//     thread t1(func5);
//     thread t2(func5);
//     t1.join();
//     t2.join();
//     cout << shared << endl;
// }


////////////////////////////// condition variable /////////////////////////

// int count = 0;
// mutex mtx;
// condition_variable cv;
// long long target = 100000;
// void producer()
// {
//     cout << "producer starts ..." << endl;
//     unique_lock<mutex> uql(mtx);
//     for(int i=0; i<target; i++)
//     {
//         count ++;
//     }
//     cv.notify_one();
//     cout << "producer starts ..." << endl;
// }

// void consumer()
// {
//     cout << "consumer starts ..." << endl;
//     unique_lock<mutex> uql(mtx);
//     for(int i=0; i<100000; i++)
//     {
//         count ++;
//     }
//     while (count < 2 * target)
//     {
//         cv.wait(uql);
//     }
//     cout << "consumer ends ... " << endl;

// }

// int main()
// {
//     thread t1(producer);
//     thread t2(consumer);
//     t1.join();
//     t2.join();
//     cout << count << endl;
// }


////////////////////////// shared lock //////////////////////////////

// int count = 0;
// mutex mtx;

// shared_mutex s_mtx;
// int shared = 0;


// void reader(int id)
// {
//     shared_lock<shared_mutex> sl(s_mtx);
//     cout << "[Reader " << id << "] reading data: " << shared << endl;
// }

// void writer(int id)
// {
//     unique_lock<shared_mutex> sl(s_mtx);
//     shared ++;
//     cout << "[Writer " << id << "] writing data: " << shared << endl;
// }

// int main()
// {
//     thread r1(reader, 1);
//     thread r2(reader, 2);
//     thread r3(reader, 3);
//     thread w1(writer, 1);

//     r1.join();
//     r2.join();
//     r3.join();
//     w1.join();

//     //cout << shared << endl;
//     return 0;
// }

//////////////////////// buffer ////////////////////////////////////


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

