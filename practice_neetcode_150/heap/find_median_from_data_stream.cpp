#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
["MedianFinder", "addNum", "1", "findMedian", "addNum", "3" "findMedian", "addNum", "2", "findMedian"]
Output:
[null, null, 1.0, null, 2.0, null, 2.0]
Explanation:
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.findMedian(); // return 1.0
medianFinder.addNum(3);    // arr = [1, 3]
medianFinder.findMedian(); // return 2.0
medianFinder.addNum(2);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
*/


class MedianFinder
{
    public:
    MedianFinder() {}
    vector<double> nums;
    void addNum(double val)
    {
        nums.push_back(val);
    }
    double calculate_median()
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        double result = 0.0;
        if(n%2 == 1)
        {
            result = nums[n/2];
        }
        else
        {
            result = (nums[n/2] + nums[n/2-1]) / 2.0;
        }
        return result;
    }
};


class MedianFinderPQ
{
    public:
    priority_queue<double> pq_left; // descending
    priority_queue<double, vector<double>, greater<double>> pq_right;
    
    void addNum(double val)
    {
        // default push it to the left
        pq_left.push(val);
        // balance
        pq_right.push(pq_left.top());
        pq_left.pop();
        if(pq_right.size() > pq_left.size())
        {
            pq_left.push(pq_right.top());
            pq_right.pop();
        }

    }
    double calculate_median() const
    {
        if(pq_left.empty()) return 0.0;
        double result = 0;
        if(pq_left.size() == pq_right.size())
        {
            double left_val = pq_left.top();
            double right_val = pq_right.top();
            result = (left_val + right_val) / 2.0;
            return result;
        }
        else return pq_left.top();
    }
};



/*
    FOllow up:
    What happens if you are dealing with enormous amount of data?
        Standard heaps don't support arbitrary deletion. 
        Use unordered_map to keep track of the deletion
*/

int main()
{
    MedianFinder Mf1;
    Mf1.addNum(1);
    cout << Mf1.calculate_median() << endl;
    Mf1.addNum(3);
    cout << Mf1.calculate_median() << endl;
    Mf1.addNum(2);
    cout << Mf1.calculate_median() << endl;

    cout << "############################################" << endl;
    MedianFinderPQ Mfpq1;
    Mfpq1.addNum(1);
    cout << Mfpq1.calculate_median() << endl;
    Mfpq1.addNum(3);
    cout << Mfpq1.calculate_median() << endl;
    Mfpq1.addNum(2);
    cout << Mfpq1.calculate_median() << endl;

    
}