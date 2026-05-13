#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    // max heap
    priority_queue<int> pq_max;
    pq_max.push(5);
    pq_max.push(10);
    pq_max.push(15);
    pq_max.push(20);
    pq_max.push(25);


    while(!pq_max.empty())
    {
        int max_element = pq_max.top();
        cout << max_element << endl;
        pq_max.pop();
    }

    cout << "//////////////////////////////////////////////////////////////" << endl;
    // min heap
    priority_queue<int, vector<int>, greater<int>> pq_min;
    pq_min.push(60);
    pq_min.push(40);
    pq_min.push(30);
    pq_min.push(50);

    while(!pq_min.empty())
    {
        int min_element = pq_min.top();
        cout << min_element << endl;
        pq_min.pop();
    }

    cout << "//////////////////////////////////////////////////////////////" << endl;
    vector<int> nums = {13,12,9,8,1,3,10,25,21,16};
    //priority_queue<int> pq_num_max(nums.begin(), nums.end());
    priority_queue<int, vector<int>, greater<int>> pq_num_min(nums.begin(), nums.end());
    while(!pq_num_min.empty())
    {
        int pq_num_max_element = pq_num_min.top();
        cout << pq_num_max_element << endl;
        pq_num_min.pop();
    }


    return 0;
}