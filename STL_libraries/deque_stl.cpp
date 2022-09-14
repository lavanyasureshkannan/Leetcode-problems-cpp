#include<iostream>
#include<deque>
#include<iterator>
using namespace std;


void display(deque<int> dq)
{
    deque<int> :: iterator dq_ptr;
    for(dq_ptr = dq.begin(); dq_ptr < dq.end(); dq_ptr++)
    {
        cout << *dq_ptr << " ";
    }
    cout << "\n";
}


int main()
{
    deque<int> a;
    a.push_back(12);
    a.push_back(13);
    a.push_back(14);
    a.push_back(15);
    display(a);

    a.pop_front();
    display(a);

    a.pop_back();
    display(a);
    return 0;
}