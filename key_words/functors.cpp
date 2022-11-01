// FUNCTORS or function pointers
// tip: "auto" ->   keyword is used in function pointers 
// Functors are objects that can be treated as though they are a function or function pointer.
// A function pointer is a variable that stores the address of a function that can later be called through that function pointer. 
// This is useful because functions encapsulate behavior.


#include<iostream>
using namespace std;


class Mul
{
    int m_val;
    public: 
    Mul() {};
    Mul(int val) : m_val(val) {}
    int operator()(int val)
    {
        return val * m_val;
    }

};

int main()
{
    Mul mul1(10); // object is working as function or state
    cout << mul1(2) << endl;
    cout << mul1(3) << endl;
    return 0;
}

