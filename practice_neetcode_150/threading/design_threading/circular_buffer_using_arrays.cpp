#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>

/*
    Circular buffer using Array
*/

std::mutex log_mutex;
template<typename... Args>
void Log(Args... args)
{
    std::lock_guard<std::mutex> lg(log_mutex);
    (std::cout << ... << args ) << std::endl;
}

template<typename T>

class Cicular_buffer
{
    public:
    explicit Cicular_buffer (size_t cap) : capacity(cap), buffer(cap) {};

    void push(T val)
    {
        {    
            std::unique_lock<std::mutex> uql(mtx);
            cv.wait(uql, [this] ()
            {
                return (count < capacity);
            });
            buffer[tail] = std::move(val);
            tail = (tail + 1) % capacity;
            count ++;
            cv.notify_one();
        }
        Log("values pushed: ", val);
        
    }

    T pop()
    {
        std::unique_lock<std::mutex> uql(mtx);
        cv.wait(uql, [this] ()
        {
            return count > 0;
        });
        T val = std::move(buffer[head]);
        head = (head + 1) % capacity;
        count --;
        cv.notify_one();
        return val;
    }

    private:
    std::vector<T> buffer;
    const size_t capacity; // [_,_,_,_,_]
                       //h       t
    size_t head = 0; // where we read
    size_t tail = 0; // where we write 
    size_t count = 0;

    std::mutex mtx;
    std::condition_variable cv;
};

void producer(Cicular_buffer<int> &cb)
{
    for(size_t i=0; i<20; i++)
    {
        cb.push(i);
    }
}

void consumer(Cicular_buffer<int>& cb)
{
    for(size_t i=0; i<20; i++)
    {
        int val = cb.pop();
        Log("Values removed: ", val);
    }
}


int main()
{
    Cicular_buffer<int>cb1(5);
    std::thread t1(producer, std::ref(cb1));
    std::thread t2(consumer, std::ref(cb1));

    t1.join();
    t2.join();
    return 0;
}