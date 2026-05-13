#include <iostream>
#include <functional>
/*
    std:: function<void ( ) > => It is like a wrapper that holds any callable
                    |    |
                return  input 
                type    param
*/

// 1. simple func
void say_hello() { std::cout << "say hello" << std::endl;}
std::function<void()> task1 = say_hello;


// 2. with lambda
std::function<void()> task2 = [] { std::cout << "say hello from task2" << std::endl;};

// 3. passing with args
int frame_id = 30;
std::function<void()> task3 = [] () {std::cout << "Outputs frame id: " << frame_id << std::endl;};


int main()
{
    task1();
    task2();
    task3();
    return 0;
}