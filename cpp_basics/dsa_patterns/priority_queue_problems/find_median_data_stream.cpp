#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
*/

class Median_finder
{
    public:
    vector<int> nums;
    Median_finder()
    {
    }

    void addNum(int num) 
    {
        nums.push_back(num);
    }
    
    double findMedian() 
    {
        int n = nums.size();
        double result = 0;
        sort(nums.begin(), nums.end()); 
        if(n%2 == 1) result = nums[n/2];
        else result = (nums[n/2-1] + nums[n/2]) / 2.0;
        return result;
    }
};

//{5, 2, 3, 4}
class Median_finder_PQ
{
    public:

    priority_queue<double> left; // max heap
    priority_queue<double, vector<double>, greater<double>> right;
    
    Median_finder_PQ() {};
    
    void addNum(double num)
    {
        left.push(num); //5

        right.push(left.top()); // left : , right:5
        left.pop();

        // maintain the size
        if(left.size() < right.size())
        {
            left.push(right.top()); // left : , right:2,5
            right.pop(); // left:2, right:5
        }
    }
    double findMedian()
    {
        if(left.size() == right.size()) 
        {
            return (left.top() + right.top()) / 2.0;
        }
        else return left.top();
    }

};

// TC: O(log N)
// SC: O(N)

/*
Follow up : what if you are dealing with enormous amount of data
“
For enormous streams, storing all elements is impractical. 
We can either maintain a sliding window of size k using two heaps to bound memory, 
    or use approximate streaming algorithms like quantile/sketches to estimate the median efficiently. 
This keeps memory usage low while still providing real-time medians.”
*/

/*
1️⃣ Sliding / Bounded Window Median
    -> Often, we only care about last k elements instead of entire stream
    -> Keep heaps of size ≤ k → memory usage controlled
    -> Old elements outside window → remove from heaps
    -> Similar to sliding window max problem
Use case:
Last 1 hour of stock prices
Last 10 seconds of radar points
*/

int main()
{
    Median_finder mf;
    vector<int> stream = {5, 2, 3, 4};
    for(int i : stream)
    {
        mf.addNum(i);
        cout << "Median after inserting " << i << " = " << mf.findMedian() << endl;
    }
    cout << endl;
    Median_finder_PQ mf_pq;
    for(int i : stream)
    {
        mf_pq.addNum(i);
        cout << "Median after inserting " << i << " = " << mf_pq.findMedian() << endl;
    }
    return 0;
}