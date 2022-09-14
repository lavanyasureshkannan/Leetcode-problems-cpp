#include<iostream>
#include<queue>
using namespace std;

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
