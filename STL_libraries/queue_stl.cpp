#include<iostream>
#include<queue>
using namespace std;
/*
Queues are a type of container adaptors that operate in a first in first out (FIFO) type of arrangement.
Elements are inserted at the back (end) and are deleted from the front.

TIME COMPLEXITY 

queue::empty()	O(1)
queue::size()	O(1)
queue::emplace()	O(1)
queue::front()	O(1)
queue::back()	O(1)
queue::push(g) 	O(1)
queue::pop() 	O(1)
*/

void display(queue<int> qq)
{
    while(!qq.empty())
    {
        cout << '\t' << qq.front();
        qq.pop();
    }
    cout << '\n';
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    display(q);

    cout << "The size of the queue is : " << q.size() << endl;
    cout << "The front element is : " << q.front() << endl;
    cout << "The last element is : " << q.back() << endl; 
    return 0;
}
