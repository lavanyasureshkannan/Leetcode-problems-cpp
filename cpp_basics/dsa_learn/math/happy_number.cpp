#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
Input: n = 19
Output: true
Explanation:
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/

int calulate_sum (int n)
{
    int sum = 0;
    while(n > 0)
    {
        int digit = n % 10;
        sum = sum + (digit * digit);
        n = n/10;
    }
    return sum;
}


bool helper_happy_number(int n, unordered_set<int>& visited)
{
    if(n == 1) return true;
    // detect the cycle means some number never reaches 1
    if(visited.count(n)) return false;
    visited.insert(n);
    int new_sum = calulate_sum(n);
    return helper_happy_number(new_sum, visited);
}

bool ishappy(int n)
{
    unordered_set<int> visited;
    return helper_happy_number(n, visited);
}

/////////////////////////////////////////

bool floyd_algorithm (int n)
{
    int slow = n; // 19
    int fast = calulate_sum(n); // 82
    while(fast != 1 && slow != fast)
    {
        slow = calulate_sum(n); // 82 
        fast = calulate_sum(calulate_sum(n)); //68
    }
    return fast == 1;
}

int main()
{
    cout << ishappy(19);
    return 0;
}