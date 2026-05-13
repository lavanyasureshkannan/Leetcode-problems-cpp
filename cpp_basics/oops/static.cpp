#include <iostream>
using namespace std;


class Myclass
{
    public:
    static int val;
    Myclass()
    {
        val ++;
    }

    static void display()
    {
        cout << val << endl;
    }

};

int Myclass :: val = 10;

// void counter()
// {
//     static int count = 0;
//     count ++;
//     cout << count << endl;
// }

int main()
{
    // counter();
    // counter();
    Myclass mc1;
    mc1.display();
    return 0;
}