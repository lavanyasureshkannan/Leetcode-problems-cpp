#include <iostream>
#include <thread>
using namespace std;


void func1()
{
    cout << " thread for func1 starts..." << endl;
    this_thread::sleep_for(chrono::seconds(5));
    cout << " thread for func1 ends.." << endl;
}

// void func2()
// {
//     cout << "thread -> func2" << endl;
// }

int main()
{
    cout << "Main starts ...." << endl;
    thread t1(func1);
    t1.detach();
    this_thread::sleep_for(chrono::seconds(10));
    cout << "main ends ...." << endl;
}

// int main()
// {
//     cout << "Main startss....." << endl;
//     thread t1(func1);
//     t1.join();
//     cout << "Mian: doing something else" << endl;
//     this_thread::sleep_for(chrono::seconds(3));
//     cout << "Main ends..." << endl;
//     return 0;
// }