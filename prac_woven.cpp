#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

// itoa int to string
string itoa(int num)
{
    // base case
    if(num == 0) return "0";
    // to handle negative numbers
    bool isnegative = false;
    if(num < 0)
    {
        isnegative = true;
        num = -(num);
    }
    // positive numbers
    string result = "";
    while(num != 0)
    {
        int digit = num % 10;
        result += digit + '0';
        num = num / 10;
    }
    if(isnegative)
    {
        result += "-";
    }
    reverse(result.begin(), result.end());
    return result;
}

string itoa_optmized(int num)
{
    if(num == 0) return ""; // base case
    vector<char> buffer(12); // creating a fixed buffer (int_max len 10 + minus + null terminator)
    char *ptr = buffer.data() + buffer.size(); // pointer points to last element
    *--ptr = '\0'; // null terminator
    bool isnegative = false;
    if(num < 0)
    {
        isnegative = true;
        num = static_cast<unsigned>(-(num)); // to acoid overflow
    }
    else
    {
        num = static_cast<unsigned>(num);
    }
    while(num !=0)
    {
        int digit = num % 10;
        *--ptr = digit + '0';
        num = num / 10;
    }
    if(isnegative)
    {
        *--ptr = '-';
    }
    return string(ptr); // building at character and convert to string

}

int atoi (string s)
{
    int n = s.length();
    int sign = 1;
    int i = 0;
    int result = 0;
    //base case
    if(n == 0) return -1;
    // handle whitespace
    while(s[i] == ' ' && i<n)
    {
        i++;
    }
    // handle negative
    if(s[i] == '-' && i < n)
    {
        sign = -1;
        i++;
    }
    else if(s[i] == '+' && i < n)
    {
        sign = 1;
        i++;
    }
    // handle numbers
    while(i<n && (s[i] >= '0' && s[i] <= '9'))
    {
        int digit = s[i] - '0';
        if(result > (INT_MAX - digit)/10)
        {
            if(sign = 1) return INT_MAX;
            else return INT_MIN;
        }
        result = (result * 10) + digit;
        i++;
    }
    return (sign * result);
}


int roman_int(string s)
{
    unordered_map<char, int> roman = { {'I', 1}, {'V', 5}, {'X', 10},
                                    {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int total = 0;
    int prev = 0;

    for(int i=s.length()-1; i>=0; i--)
    {
        int curr = roman[s[i]];
        if(curr < prev)
        {
            total = total - curr; // subratct
        }
        else
        {
            total = total + curr; // add
        }
        prev = curr;
    }
    return total;

}

// "3+2*2"

int basic_Calculator(string s)
{
    int result = 0;
    char operation = '+';
    // base class
    if(s.length() == 0) return -1;
    stack<int> st;
    int curr_num = 0;
    for(int i=0; i<s.length(); i++)
    {
        char curr = s[i];
        if(isdigit(curr))
        {
            curr_num = (curr_num * 10) + (curr - '0');
        }
        if(!isdigit(curr) && !iswspace(curr) || i == s.length()-1)
        {
            if(operation == '-')
            {
                st.push(-curr_num);
            }
            else if(operation == '+')
            {
                st.push(curr_num);
            }
            else if(operation == '*')
            {
                int st_top = st.top();
                st.pop();
                st.push(st_top * curr_num);
            }
            else if(operation == '/')
            {
                int st_top = st.top();
                st.pop();
                st.push(st_top/ curr_num);
            }
            curr_num = 0;
            curr = operation;
        }
    }
    while(st.size() != 0)
    {
        result = result + st.top();
        st.pop();
    }
    return result;
}

bool canschedule(vector<vector<int>>& prerequisites, int numcourses)
{
    // convert to adjacency list
    vector<vector<int>> adjacency_list(numcourses);
    for(auto &pre: prerequisites)
    {
        int from = pre[0];
        int to = pre[1];
        adjacency_list[from].push_back(to);
    }
    // calculate indegrees
    vector<int> indegrees(numcourses, 0);
    for(int i=0; i<numcourses; i++)
    {
        for(auto neigh : adjacency_list[i])
        {
            indegrees[neigh] ++;
        }
    }
    // create q
    queue<int>q;
    for(int i=0; i<numcourses; i++)
    {
        if(indegrees[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> result;
    // pop the q values and reduce the indegrees
    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        result.push_back(front);
        for(int neigh : adjacency_list[front])
        {
            indegrees[neigh] --;
            if(indegrees[neigh] == 0)
            {
                q.push(neigh);
            }
        }
    }
    // check for the validity of the courses
    if(result.size() == numcourses)
    {
        cout << "true";
        return true;
    }
    return false;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    intervals = [[1,3],[2,6],[8,10],[15,18]]
    o/p = [[1,6],[8,10],[15,18]]
*/

void display(vector<vector<int>>& arrays)
{
    for(int i=0; i<arrays.size(); i++)
    {
        for(int j=0; j<arrays[i].size(); j++)
        {
            cout << arrays[i][j] << " ";
        }
        cout << endl;
    }
}

// vector<vector<int>> merge_intervals(vector<vector<int>>& intervals)
// {
//     vector<vector<int>> result;
//     sort(intervals.begin(), intervals.end());
//     int curr_begin = intervals[0][0];
//     int curr_end = intervals[0][1];
//     for(int i=0; i<intervals.size(); i++)
//     {
//         if(intervals[i][0] <= curr_end && intervals[i][0] >= curr_begin)
//         {
//             curr_begin = min(curr_begin, intervals[i][0]);
//             curr_end = max(curr_end, intervals[i][1]);
            
//         }
//         else
//         {
//             result.push_back({curr_begin,curr_end});
//             curr_begin = intervals[i][0];
//             curr_end = intervals[i][1];

//         }
//     }
//     result.push_back({curr_begin, curr_end});
//     display(result);
//     return result;
// }

// int main()
// {
//     vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
//     merge_intervals(intervals);
//     return 0;
// }



/*
    intervals = [[1,3],[2,6],[8,10],[15,18]]
    o/p = [[1,6],[8,10],[15,18]]
*/

vector<vector<int>> merge_intervals(vector<vector<int>>& intervals)
{
    // 1. sort the intervals
    sort(intervals.begin(), intervals.end());
    // 2. initialize the current begin and current end
    int curr_begin = intervals[0][0];
    int curr_end = intervals[0][1];
    // 3. create a result array
    vector<vector<int>> result; 
    // 4. iterate through the intervals and comapre the begin and end
    for(int i=1; i<intervals.size(); i++)
    {
        if(intervals[i][0] <= curr_end)
        {
            curr_end = max(curr_end, intervals[i][1]);
        }
        else
        {
            result.push_back({curr_begin, curr_end});
            curr_begin = intervals[i][0];
            curr_end = intervals[i][1];
        }
    }
    result.push_back({curr_begin, curr_end});
    display(result);
    return result;

}

#include <iostream>
#include <vector>
using namespace std;

/*
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

void display(vector<vector<int>>& nums)
{
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=0; j<nums[i].size(); j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}
void backtrack(vector<vector<int>>& result, vector<int>& curr, vector<bool>& visited, vector<int>& nums)
{
    if(curr.size() == nums.size())
    {
        result.push_back(curr);
        return;
    }
    for(int i=0; i<nums.size(); i++)
    {
        if(!visited[i])
        {
            curr.push_back(nums[i]);
            visited[i] = true;
            backtrack(result, curr, visited, nums);
            curr.pop_back();
            visited[i] = false;
        }
    }

}


vector<vector<int>> permutations(vector<int>& nums)
{
    vector<vector<int>> result;
    vector<int> curr;
    vector<bool> visited(nums.size(), false);  // (false, false, false)
    backtrack(result, curr, visited, nums);
    display (result);
    return result;
}

int main()
{
    vector<int> nums = {1,2,3};
    permutations(nums);
    return 0;
}

int main()
{
    //int a = -12345;
    //cout << itoa_optmized(a) << endl;
    //string s = "-12345678934";
    //cout << atoi(s) << endl;

    // string s = "3+2*2";
    // cout << basic_Calculator(s);

    vector<vector<int>> prerequisties = {{1,0}, {2,0}, {3,1}, {3,2}};
    int n = 4;
    canschedule(prerequisties,n);
    return 0;
}
