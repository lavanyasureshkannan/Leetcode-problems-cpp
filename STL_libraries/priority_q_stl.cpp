#include<iostream>
#include<queue>
using namespace std;

/*
PRIORITY QUEUE are nothing but the heap
The queue has specific order in which it is arranged either ascending (min heap) or descending (max heap)
*/

// max heap -> default
void display(priority_queue<int> pq)
{
    while(!pq.empty())
    {
        cout << '\t' << pq.top();
        pq.pop();
    }
    cout << '\n';
}

// min heap -> syntax -> priority_queue<int,vector<int>, greater<int>> min_heap

void display_2(priority_queue<int, vector<int>, greater<int>> mh)
{
    while(!mh.empty())
    {
        cout << '\t' << mh.top();
        mh.pop();
    }
    cout << '\n';
}

int main()
{
    priority_queue<int> max_heap;
    max_heap.push(5);
    max_heap.push(6);
    max_heap.push(8);
    max_heap.push(7);
    display(max_heap);


    priority_queue<int, vector<int>, greater<int>> min_heap;
    min_heap.push(100);
    min_heap.push(20);
    min_heap.push(30);
    min_heap.push(50);
    min_heap.push(10);
    display_2(min_heap);
    return 0;
}