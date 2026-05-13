#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <shared_mutex>
/*
    READ AND WRITE THREAD
    2 THREAD READS THE VARIABLE AND ONE THREAD WRITES TO IT.

    READERS -> Shared_lock
    WRITERS -> Unique_lock

    Always write the locks inside the scope and sleep outisde the scope
*/

std::mutex log_mtx;
template<typename... Args>

void Log(Args... args)
{
    std::lock_guard<std::mutex> lg(log_mtx);
    (std::cout << ... << args) << std::endl;
}


//std::atomic<int> count = 0;
int count = 0;
// std::mutex mtx_writer;
std::shared_mutex mtx;

void writer() 
{
    for(size_t i=0; i<10; i++) 
    {
        {
            std::unique_lock<std::shared_mutex> ul(mtx);
            count++;
            Log("Writer: ", count);
        }                    
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void reader(int thread_id) 
{
    for(size_t i=0; i<10; i++) 
    {
        {
            std::shared_lock<std::shared_mutex> sl(mtx);
            Log("Reader ", thread_id, " reads: ", count);
        }                    
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

int main()
{
    std::thread writer_thread(writer);
    // std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::thread reader_thread_1(reader, 1);
    std::thread reader_thread_2(reader, 2);
    std::thread reader_thread_3(reader, 3);

    writer_thread.join();
    reader_thread_1.join();
    reader_thread_2.join();
    reader_thread_3.join();

    return 0;
}