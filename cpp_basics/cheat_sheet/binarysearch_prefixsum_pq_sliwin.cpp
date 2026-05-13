#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

///////////////////////////// BINARY SEARCH  MODIFIED ////////////////////////////////////
int search_target(vector<int>& nums, int target){
    int left = 0; int right = nums.size() - 1;
    while(left <= right){
        int mid = left + (right - left)/2; if(nums[mid] == target) return mid;
        else if(nums[mid] >= nums[left]){
            if(target >= nums[left] && target < nums[mid]){right = mid - 1;}
            else {left = mid + 1;}}
        else{if(target <= nums[right] && target > nums[mid]){left = mid + 1;}
            else{
                right = mid - 1;}}}
    return -1;}
/////////////////////////prefix sum /////////////////////////////////////////

vector<int>prefix_sum(vector<int>& arr){
    int n = arr.size();
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for(int i=1; i < arr.size(); i++){
        prefix[i] = prefix[i-1] + arr[i];}
    return prefix;}

//////////////////////////// PQ //////////////////////////////////////////////////
vector<vector<int>> k_closest_points(vector<vector<int>>& points, int k){
    vector<vector<int>> result;
    priority_queue<pair<int,pair<int,int>>> pq;
    for(int i=0; i<points.size(); i++){
        int key = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
        pair<int,int> val = {points[i][0], points[i][1]};
        pq.push({key,val});
        if(pq.size() > k) { pq.pop();}}
    while(pq.size() > 0){
        auto the_point = pq.top().second;
        result.push_back({the_point.first, the_point.second});
        pq.pop();}
    return result;}

vector<int> top_q_elements(vector<int>& nums, int k){
    unordered_map<int,int> mp;
    for(int i=0; i<nums.size(); i++){
        mp[nums[i]] ++;
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(auto i:mp){
        pq.push({i.second, i.first});
        if(pq.size() > k)
        {
            pq.pop();}}
    vector<int> result;
    while(pq.size() > 0){
        int x = pq.top().second;
        result.push_back(x);
        pq.pop();}
    return result;}

class MedianFinderPQ{
    public:
    priority_queue<double> pq_left; // descending
    priority_queue<double, vector<double>, greater<double>> pq_right;
    void addNum(double val){
        // default push it to the left
        pq_left.push(val);
        // balance
        pq_right.push(pq_left.top());pq_left.pop();
        if(pq_right.size() > pq_left.size()){
            pq_left.push(pq_right.top());pq_right.pop();}}
    double calculate_median() const{
        if(pq_left.empty()) return 0.0; double result = 0;
        if(pq_left.size() == pq_right.size()){
            double left_val = pq_left.top(); double right_val = pq_right.top();
            result = (left_val + right_val) / 2.0;
            return result;}
        else return pq_left.top();}};
int last_stone_weight(vector<int>& nums)
{
    priority_queue<int> pq_max(nums.begin(), nums.end());
    while(pq_max.size() > 1)
    {
        int y = pq_max.top();
        pq_max.pop();
        int x = pq_max.top();
        pq_max.pop();
        if(x != y)
        {
            pq_max.push(y-x);
        }
    }
    if(pq_max.empty()) return 0;
    else return pq_max.top();
}

///////////////////////// sliding window /////////////////////////
double findMaxAverage(vector<int>& nums, int k) {
    double curr_sum = 0;
    for(int i=0; i<k; i++){
        curr_sum = curr_sum + nums[i];}
    double max_sum = curr_sum;
    for(int i=k; i<nums.size(); i++){
        curr_sum = curr_sum - nums[i-k] + nums[i];
        max_sum = max(max_sum, curr_sum);}
    return max_sum/k;}
int longest_substring_wo_repeating(string s){
    int left = 0;int right = 0;int maxi = 0;unordered_set<char> chars;
    while(right < s.length()){
        if(chars.find(s[right]) == chars.end()){
            chars.insert(s[right]);right ++;maxi = max(maxi, (right - left));}
        else{chars.erase(s[left]);left ++;}}return maxi;}
int longest_repeating_char_DEV(string s, int k){
    int freq[26] = {0}; int left = 0; int N = s.length();
    int maxi = 0; int max_freq = 0;
    for(int right=0; right<N; right++){
        // keep track of the frequencies freq[A] - 3
        freq[s[right] - 'A']++;
        // track of freq count 
        max_freq = max(max_freq, freq[s[right] - 'A']); 
        // main logic
        int curr_window = right - left + 1;
        // shrinking the window part
        if((curr_window - max_freq) > k){
            freq[s[left] - 'A'] --; left ++;}
        maxi = max(maxi, right - left + 1);}return maxi;}
string min_window_substring(string s, string t){
    int left = 0; int right = 0;
    // unordered_map to keep track of target freq
    unordered_map<char, int> target_freq; 
    for(int i=0; i<t.length(); i++){target_freq[t[i]] ++;}
    int min_len = INT_MAX; int have = 0;
    int need = target_freq.size(); int start =0 ;  
    unordered_map<char, int> window_freq; 
    while(right < s.length()){
        char c = s[right];
        // check if the curr window has the target char
        window_freq[c] ++;
        if(target_freq.count(c) && window_freq[c] == target_freq[c]) have ++;
        while(have == need){
            // since we have have = need update the curr length
            int curr_len = right - left + 1;
            if(curr_len < min_len){
                min_len = curr_len; start = left;}
            // shirnking part
            char left_c = s[left]; window_freq[left_c] --;
            if(target_freq.count(left_c) && window_freq[left_c] < target_freq[left_c]) have --;
            left ++;}
        right ++;}
    if(min_len == INT_MAX) return "";
    else return(s.substr(start, min_len));}
vector<int> sliding_window_maxi(vector<int>& nums, int k){
    vector<int> result; deque<int> dq;
    for(int i=0; i<nums.size(); i++){
        // removing the useless elements
        if(!dq.empty() && dq.front() < i-k+1){dq.pop_front();}
        // removing the smaller elements
        while(!dq.empty() && nums[dq.back()] < nums[i]){dq.pop_back();}
        dq.push_back(i);
        // if window is ready take the max out of it
        if(i >= k-1){result.push_back(nums[dq.front()]);}}
    return result;}