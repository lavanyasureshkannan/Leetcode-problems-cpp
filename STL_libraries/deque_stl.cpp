#include<iostream>
#include<deque>
#include<iterator>
using namespace std;

/*
Double-ended queues are sequence containers with the feature of expansion and contraction on both ends. 
They are similar to vectors, but are more efficient in case of insertion and deletion of elements. 
Unlike vectors, contiguous storage allocation may not be guaranteed. 

The functions for deque are same as vector, with an addition of push and pop operations for both front and back.  

Accessing Elements- O(1)
Insertion or removal of elements- O(N)
Insertion or removal of elements at start or end- O(1)
*/


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