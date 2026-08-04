#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

/*
Input: arr = [2,1,3,1,2,3,3]
Output: [4,2,7,2,4,4,5]
Explanation:
- Index 0: Another 2 is found at index 4. |0 - 4| = 4
- Index 1: Another 1 is found at index 3. |1 - 3| = 2
- Index 2: Two more 3s are found at indices 5 and 6. |2 - 5| + |2 - 6| = 7
- Index 3: Another 1 is found at index 1. |3 - 1| = 2
- Index 4: Another 2 is found at index 0. |4 - 0| = 4
- Index 5: Two more 3s are found at indices 2 and 6. |5 - 2| + |5 - 6| = 4
- Index 6: Two more 3s are found at indices 2 and 5. |6 - 2| + |6 - 5| = 5
*/

vector<int> intervals_between_identical(vector<int>& nums)
{
    int n = nums.size();
    vector<int> result(n,0);
    for(size_t i=0; i<nums.size(); i++)
    {
        int sum = 0;
        for(size_t j=0; j<nums.size(); j++)
        {
            if(i!=j && nums[i] == nums[j])
            {
                int curr = i -j;
                curr = abs(curr);
                sum += curr;
            }
        }
        result[i]= sum;
    }
    return result;
}

class Solution 
{
    public:
    vector<long long> getDistances(vector<int>& arr) {
        // Step 1: Get size of array
        int n = arr.size();
        // Step 2: Map each value -> list of indices where it appears
        // Example: 1 -> [0,2,3]
        unordered_map<int, vector<int>> mp;
        // Fill the map with positions
        for (int i = 0; i < n; i++) 
        {
            mp[arr[i]].push_back(i);
        }

        // Step 3: Result array initialized to 0
        vector<long long> ans(n, 0);

        // Step 4: Process each group of identical values
        for (auto &it : mp) {

            // Extract index list for current value
            vector<int> &idx = it.second;

            // Number of occurrences of this value
            int m = idx.size();

            // Step 5: Build prefix sum of indices
            // prefix[i] = sum of first i indices
            vector<long long> prefix(m + 1, 0);

            for (int i = 0; i < m; i++) {

                // Build running sum
                prefix[i + 1] = prefix[i] + idx[i];
            }

            // Step 6: Compute answer for each occurrence
            for (int i = 0; i < m; i++) {

                // Current index in original array
                long long cur = idx[i];

                // LEFT SIDE:
                // cost = (distance to all indices on left)
                // formula: i * cur - sum_of_left_indices
                long long left =
                    1LL * i * cur - prefix[i];

                // RIGHT SIDE:
                // cost = (distance to all indices on right)
                // formula: sum_of_right_indices - (count_right * cur)
                long long right =
                    (prefix[m] - prefix[i + 1]) -
                    1LL * (m - i - 1) * cur;

                // Final answer = left + right
                ans[cur] = left + right;
            }
        }

        // Step 7: Return result array
        return ans;
    }
};

int main()
{
    vector<int>arr = {2,1,3,1,2,3,3};
    vector<int> result = intervals_between_identical(arr);
    for(size_t i=0; i<result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}