#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// queue => First In First Out
int main()
{
    vector<int> nums = {20,40,10,50,30};
    queue<int>q;
    for(auto i : nums)
    {
        q.push(i);
    }
    while(!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}