#include <iostream>
#include <thread>
using namespace std;


int main()
{
    unsigned int con_threads = thread::hardware_concurrency();
    cout << con_threads << endl;
    return 0;
}
