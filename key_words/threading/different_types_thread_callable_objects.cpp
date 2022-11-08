#include<iostream>
#include<thread>
#include<chrono>
#include<ctime>
using namespace std;

/*
    THREADING IN C++

    Types of thread creation in c++

    Ways to create thread -> callable object:
    1. funtion pointers
    2. lambda functions
    3. functors
    4. member functions
    5. static member functions

*/

// 1. Function pointer

// void fun(int x)
// {
//     while(x-- > 0)
//     {
//         cout << x << endl;
//     }
// }

// int main()
// {
//     thread t1(fun, 10);
//     t1.join();

//     return 0;
// }


// 2. lambda function
// int main()
// {
//     auto fun = [](int x)
//     {
//         while(x -- > 0)
//         {
//             cout << x << endl;
//         }
//     };
//     std::thread t1(fun, 10);
//     t1.join();
//     return 0;
// }

// 3. FUnctors
// class base
// {
//     public:
//     void operator () (int x)
//     {
//         while(x -- > 0)
//         {
//             cout << x << endl;
//         }
//     }

// };

// int main()
// {
//     thread t1((base()), 10);
//     t1.join();
//     return 0;
// }

// 4. Non - static member functions
// class base
// {
//     public:
//     void fun(int x)
//     {
//         while(x-- > 0)
//         {
//             cout << x << endl;
//         }
//     }
// };

// int main()
// {
//     base b1;
//     // (&class :: function, &object, param);
//     thread t1(&base :: fun, &b1, 10);

// }


// 5. Static member function
// class base
// {
//     public:
//     static void fun(int x)
//     {
//         while(x-- > 0)
//         {
//             cout << x << endl;
//         }
//     }
// };

// int main()
// {
//     thread t1(&base :: fun, 10);
//     t1.join();
//     return 0;
// }