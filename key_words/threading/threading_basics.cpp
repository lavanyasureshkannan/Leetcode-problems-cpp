#include<iostream>
#include<thread>
#include<chrono>
#include<ctime>
using namespace std;

/*
    THREADING IN C++
    
    Question:
    1. What is thread?
    A thread is a lightweight process. The idea of thread is to achieve parallelism  by dividing the process into multiple threads.
    In every application we have a default thread which is our main() function inside which we create other threads.

    Example:
    1. Different tabs in the browser is run by threads
    2. MS word uses multi threading as one thread is used to format text, another thread to process the inputs(spell checker)
    3. VS code uses threading to autocomplete the code (Intellicence).

    Ways to create thread -> callable object:
    1. funtion pointers
    2. lambda functions
    3. functors
    4. member functions
    5. static member functions

*/

long long find_even_sum(long long num1, long long num2)
{
    long long even_sum = 0;
    for(int i=num1; i<num2; i++)
    {
        if((i % 2) == 0)
        {
            even_sum = even_sum + i;
        }
    }
    return even_sum;
}

long long find_odd_sum(long long num1, long long num2)
{
    long long odd_sum = 0;
    for(int i=num1; i<num2; i++)
    {
        if((i % 2) == 1)
        {
            odd_sum = odd_sum + i;
        }
    }
    return odd_sum;
}


int main()
{
    // WITHOUT THREADING

    std::chrono::time_point<std::chrono::system_clock> start, end;
    long long start_num = 0;
    long long end_num = 1900000000; 
    start = std::chrono::system_clock::now();

    // cout << find_even_sum(start_num, end_num)<< endl;
    // cout << find_odd_sum(start_num, end_num) << endl;

    // end = std::chrono::system_clock::now();
    // std::chrono::duration<double> duration = end - start;
    
    // cout << duration.count() << endl; // give you 4 seconds

    // WITH THREADING

    thread t1(find_even_sum, start_num, end_num);
    //thread t2(find_odd_sum, start_num, end_num);

    t1.join();
    //t2.join();

    end = std::chrono::system_clock::now();
    // cout << find_even_sum << endl;
    // cout << find_odd_sum << endl;
    std::chrono::duration<double> duration = end - start;

    cout << duration.count() << endl; // result will be 2 sec
    return 0;

}
