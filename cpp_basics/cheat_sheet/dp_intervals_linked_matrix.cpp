#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

////////////////////////// DYNAMIC PORGRAMMING ///////////////////////////////////////
int coinchange(vector<int>& coins, int amount)
{
    int maxi = amount + 1;
    vector<int> dp(maxi, maxi); dp[0] = 0;
    for(int i=1; i<=amount; i++){
        for(int c:coins){
            if(c<=i){
                dp[i] = min(dp[i-c] + 1,  dp[i]);
            }
        }
    }
    if(dp[amount] > amount) return -1;
    return dp[amount];
}
int longest_common_subsequence(string text1, string text2)
{
    int m = text1.size(); int n = text2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(text1[i-1] == text2[j-1]) // if the characters match
            {
                dp[i][j] = dp[i-1][j-1]+1; // +1 updates the LCS
            }
            else{dp[i][j] = max(dp[i-1][j], dp[i][j-1]);}
        }
    }
    return dp[m][n];
}

int longest_common_increasing_subsequence(vector<int>& nums)
{
    int n = nums.size();
    vector<int> dp(n,1); int result = 0;
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=0; i<nums.size(); j++){
            if(nums[j] < nums[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    for(int i:dp) {result = max(result,i);}
    return result;
}
int unique_paths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 1)); // only one way to go right and down
    for(int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

///////////////////////////////// MERGE INTERVALS //////////////////////////////////
vector<vector<int>> merge_intervals(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end());
    int curr_begin = intervals[0][0];
    int curr_end = intervals[0][1];
    vector<vector<int>> result;
    for(int i=1; i<intervals.size(); i++)
    {
        if(intervals[i][0] <= curr_end){
            curr_end = max(curr_end, intervals[i][1]);
        }
        else{
            result.push_back({curr_begin, curr_end});
            curr_begin = intervals[i][0];
            curr_end = intervals[i][1];
        }
    }
    result.push_back({curr_begin, curr_end});
    return result;
}
bool meeting_room_1(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end());
    for(int i=0; i<intervals.size()-1; i++)
    {
        if(intervals[i][1] > intervals[i+1][0])
        {
            return false;
        }
    }
    return true;
}
int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(intervals[0][1]);
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] >= minHeap.top()) {
            minHeap.pop();
        }
        minHeap.push(intervals[i][1]);
    }
    return minHeap.size();
}
///////////////////////// LINKED LIST ///////////////////////////
struct Node
{
    int val;
    Node* next;
    Node(int m_val)
    {
        val = m_val;
    }
};
Node* reverselist(Node* head)
{
    Node* dummy = new Node(0);
    while(head)
    {
        Node* next_node = head->next;
        head->next = dummy->next;
        dummy = head;
        head =  next_node;
    }
    return head;
}
//////////////////////// MATRIX TRAVERSAL ////////////////////////////////
void dfs(vector<vector<int>>& image, int i, int j, int new_color, int old_color)
{
    if(i<0 || j<0 || i>=image.size() || j>=image[i].size() || image[i][j] != old_color) return;
    image[i][j] = new_color;
    dfs(image, i+1, j, new_color, old_color);
    dfs(image, i-1, j, new_color, old_color);
    dfs(image, i, j+1, new_color, old_color);
    dfs(image, i, j-1, new_color, old_color);
}

vector<vector<int>> floodfill(vector<vector<int>>& image, int sr, int sc, int new_color)
{
    int old_color = image[sr][sc];
    dfs(image, sr, sc, new_color, old_color);
    return image;
}
