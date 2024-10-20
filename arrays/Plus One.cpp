#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

// APPROACH 1
// case 1 - 1,2,3 --> Increase the last value by 1
// case 2 - 1,2,9 --> change 9 to 0
// case 3 - 9,9,9 --> change 9 to 0 and index goes out of range so add 1 to the beginning.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> plus_one(vector<int>&nums)
{
    int n = nums.size();
    for(int i=n-1; i>=0; i--)
    {
        if(nums[i] < 9)
        {
            nums[i]++;
            return nums;
        }
        nums[i] = 0;
    }
    nums.insert(nums.begin(), 1);
    return nums;
}


int main() {
    vector<int> digits = {4, 3, 2, 9}; // Represents 4329
    vector<int> result = plus_one(digits);

    cout << "Result: ";
    for (int digit : result) {
        cout << digit;
    }
    cout << endl; // Outputs: Result: 4330

    return 0;
}
