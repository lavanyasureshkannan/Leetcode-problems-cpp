#include <iostream>
#include <vector>
using namespace std;

/*
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. 
However, choosing the rightmost card first will maximize your total score. 
The optimal strategy is to take the three cards on the right, giving a final score of 
            1 + 6 + 5 = 12.

Example 2:
Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, 
your score will always be 4.

*/

/*
    LOGIC BEHIND

    Max picked sum = Total sum - Sum of removed middle 
    find the sum of removed element

    ex:
    cards = [1,2,3,4,5,6,1]
    k = 3
    n = 7
    window_size = n - k = 4

    step 1 : total_sum => 1+2+3+4+5+6+1 = 22
    step 2 : All windows:
            [1,2,3,4] → 10
            [2,3,4,5] → 14
            [3,4,5,6] → 18
            [4,5,6,1] → 16 

            👉 Minimum = 10
    step 3 :
        22 - 10 = 12 ✅
*/

template<typename... Args>
void Log(Args... args)
{
    (cout << ... << args) << endl;
}

int maximum_points_in_card(vector<int>& card_points, int k)
{
    // 1. calculate the total sum
    size_t n = card_points.size();
    int total_points = 0;
    for(size_t i = 0; i < n; i++)
    {
        total_points += card_points[i];
    }
    // base case
    if (k == n) return total_points;

    // 2. calculate the curr window size
    size_t window_size = n - k;
    // 3. calculate the curr window sum
    int curr_window_sum = 0;
    for(size_t i = 0; i<window_size; i++)
    {
        curr_window_sum += card_points[i];
    }
    int min_window_sum = curr_window_sum;
    // 4. sliding window
    for(size_t i = window_size; i<n; i++)
    {
        curr_window_sum += card_points[i]; // adding the next element
        curr_window_sum -= card_points[i-window_size]; // remove the old element
        min_window_sum = min(curr_window_sum, min_window_sum);
    }

    // 5. return total points - min_window_sum
    return (total_points - min_window_sum);
}

// TC: O(N)
// SC: O(1)

int main()
{
    vector<int> card_points = {1,2,3,4,5,6,1};
    int k = 3;
    Log(maximum_points_in_card(card_points,k));
    return 0;
}