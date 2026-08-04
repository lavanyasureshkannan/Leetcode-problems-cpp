#include <iostream>
using namespace std;

/////////////// DISTNICT ISLAND //////////////////////////////
void dfs(int i, int j, int bi, int bj, vector<vector<int>>& grid, vector<pair<int,int>>& s){
    if (i<0 || j<0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) return;
    grid[i][j] = 0;
    s.push_back({i - bi, j - bj});
    dfs(i + 1, j, bi, bj, grid, s); 
    dfs(i - 1, j, bi, bj, grid, s); 
    dfs(i, j + 1, bi, bj, grid, s); 
    dfs(i, j - 1, bi, bj, grid, s);}
int distinct_islands(vector<vector<int>>& grid){
    set<vector<pair<int,int>>> shapes;
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[0].size(); j++){
            if(grid[i][j] == 1){
                vector<pair<int,int>> shape;
                dfs(i,j,i,j, grid, shape);
                shapes.insert(shape);}}    }
    return shapes.size();}

/////////////// SLIDING WINDOW MAXIMUM ///////////////////
vector<int> sliding_window_maxi(vector<int>& nums, int k){
    vector<int> result; deque<int> dq;
    for(int i=0; i<nums.size(); i++){
        // removing the useless elements
        if(!dq.empty() && dq.front() < i-k+1) {dq.pop_front();}
        // removing the smaller elements
        while(!dq.empty() && nums[dq.back()] < nums[i]){dq.pop_back();}
        dq.push_back(i);
        // if window is ready take the max out of it
        if(i >= k-1){result.push_back(nums[dq.front()]);}}
    return result;}

/////////////// maximum angle point /////////////////////////////
int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
    vector<double> ang; //int same = 0; 
    int x0 = location[0]; int y0 = location[1];
    // Step 1: convert to angles
    for (auto &p : points) {
        int x = p[0], y = p[1];
        // if (x == x0 && y == y0) // {
        //     same++;//     continue;// }
        ang.push_back(atan2(y - y0, x - x0));}
    // Step 2: sort
    sort(ang.begin(), ang.end()); int n = ang.size();
    // // Step 3: duplicate for circular handling
    // for (int i = 0; i < n; i++) {
    //     ang.push_back(ang[i] + 2 * M_PI);
    // }
    double rad = angle * M_PI / 180.0;
    // Step 4: sliding window
    int i = 0; int ans = 0;
    for (int j = 0; j < ang.size(); j++) {
        while (ang[j] - ang[i] > rad) {i++;}
        ans = max(ans, j - i + 1);}
    return ans; // + same;}

///////////////// meeting rooms 2 /////////////////////////
int meeting_rooms(vector<vector<int>>& intervals){
    if(intervals.size() == 0) return 0;
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<int>> pq; // keeep track of the end time
    pq.push(intervals[0][1]);
    for(int i=1; i<intervals.size(); i++){
        int start_time = intervals[i][0]; int end_time = intervals[i][1];
        if(start_time >= pq.top()) // pq.top -> smallest end time
        {    pq.pop();}
        pq.push(end_time);}
    return pq.size();}

/////////////////// course scheudule ///////////////////////
bool course_schedule(vector<vector<int>>& prereq, int numCourses){
    // create adj list
    vector<vector<int>> adj_list(numCourses);
    for(auto pre : prereq){  int from = pre[1]; int to = pre[0];
        adj_list[from].push_back(to);}
    // calculate indegrees
    vector<int> indegrees(numCourses,0);
    for(int i=0; i<numCourses; i++){
        for(auto neigh:adj_list[i]){indegrees[neigh] ++;}}
    // create a queue and push indegrees 
    queue<int> q;
    for(int i=0; i<numCourses; i++){
        if(indegrees[i] == 0){q.push(i);}}
    // pop the element from the queue and add the neighbours
    vector<int> result;
    while(!q.empty()){
        int front = q.front();q.pop();
        result.push_back(front);
        for(auto neigh : adj_list[front]){
            indegrees[neigh] --;
            if(indegrees[neigh] == 0){
                q.push(neigh);}}}
    if(result.size() == numCourses) return true;
    else return false;}

///////////////////////// timestamp question ////////////////
class TimeMap
{public:TimeMap() {}
    unordered_map<string, vector<pair<int,string>>> mp;
    void set(string key, string value, int time){
        mp[key].emplace_back(time, value); // mp["foo"] = {{"bar",1},{"bar2,2"} ...}
    }
    string get(string key, int time){
        auto &values = mp[key];int left = 0;
        int right = values.size() - 1; string result = "";
        while(left <= right){
            int mid = left + (right - left) / 2; 
            if(values[mid].first <= time){
                result = values[mid].second;
                left = mid + 1;}
            right = mid - 1;}
        return result;}};
///////////////////////// MEDIAN FINDER //////////////////////
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
            result = (left_val + right_val) / 2.0; return result;}
        else return pq_left.top();}}

//////////////////// num of islands 2 /////////////////////
vector<int> numIslands2(int n, int m, vector<vector<int>>& positions) {
        vector<int> parent(n * m, -1);
        vector<int> rank(n * m, 0);
        vector<int> result;int count = 0;
        vector<int> dir = {0,1,0,-1,0};
        function<int(int)> find = [&](int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        };
        auto unite = [&](int x, int y) {
            int px = find(x);int py = find(y);
            if (px == py) return false;
            if (rank[px] < rank[py])parent[px] = py;
            else if (rank[px] > rank[py])parent[py] = px;
            else {
                parent[py] = px;rank[px]++;
            }
            return true;};
        for (auto &pos : positions) {
            int r = pos[0], c = pos[1];
            int idx = r * m + c;
            // already land
            if (parent[idx] != -1) {
                result.push_back(count);
                continue;}
            parent[idx] = idx; count++;  // new island
            // check 4 directions
            for (int d = 0; d < 4; d++) {
                int nr = r + dir[d]; int nc = c + dir[d+1];
                int nidx = nr * m + nc;
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && parent[nidx] != -1) {
                    if (unite(idx, nidx)) { count--;}}}result.push_back(count);}
        return result;}

///////////////// tasks scehduler ////////////////////////////
int task_scheduler(vector<char>& tasks, int n){
    // count freq => A3 B3
    unordered_map<char, int> mp;
    for(int i=0; i<tasks.size(); i++){
        mp[tasks[i]] ++;}
    // map in pq => 3,3
    priority_queue<int> pq;
    for(auto &i:mp){
        pq.push(i.second);}
    int time = 0;
    while(!pq.empty()){
        int cycle = n + 1;
        vector<int> temp;
        while(cycle > 0 && !pq.empty()){
            int count = pq.top(); pq.pop();
            if(count -1 > 0) { temp.push_back(count - 1);}
            time ++; cycle --;}
        for(int i:temp){ pq.push(i);}
        if(!pq.empty()) {time += cycle;}}
    return time;}

//////////////// DIAMETER OF BINARY TREE //////////////
    int length(TreeNode* root){
        // base case to find if the node doesnt exist
        if(root == NULL) return -1;
        int left = 1 + length(root->left); 
        int right = 1 + length(root->right);

        result = max(result, left + right);
        return max(left,right);}
    int diameterOfBinaryTree(TreeNode* root){
        length(root);
        return result;}

/////////////// flatten iterator ////////////////////
class NestedIterator {public:
    stack<NestedInteger> st;
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            st.push(nestedList[i]); }}
    void makeTopReady() {
        while (!st.empty() && !st.top().isInteger()) {
            vector<NestedInteger> lst = st.top().getList();
            st.pop();
            for (int i = lst.size() - 1; i >= 0; i--) {
                st.push(lst[i]);}}}
    int next() {
        makeTopReady(); int val = st.top().getInteger();
        st.pop(); return val;}
    bool hasNext() {
        makeTopReady();}}
      

///////////// LRU CACHE /////////////////////////////////
class LRU_Cache{
    private:
    list<pair<int,int>>cache; // key, value
    unordered_map<int, list<pair<int, int>>::iterator> mp; // key and a pointer to the list 
                                                                // points to (1,10) inside list
    int capacity;
    public:
    LRU_Cache(int cap){
        capacity = cap;}

    int get(int key){
        if(mp.find(key) == mp.end()) return -1;
        // move accessed node to the front
        auto it  = mp[key];int value = it->second; // {key, value}
        cache.erase(it);
        cache.push_front({key,value});
        mp[key] = cache.begin();
        return value;}

    void put(int key, int val){
        // find if it is in the map and erase it 
        if(mp.find(key) != mp.end()) {
            cache.erase(mp[key]);}
        else if(cache.size() == capacity){
            // remove the least used 
            auto last_used = cache.back();mp.erase(last_used.first);cache.pop_back();}
        // insert the new val in the front
        cache.push_front({key,val}); mp[key] = cache.begin(); }};

///////////// WORD SEARCH 2 ///////////////////////////////////////////////
   struct TrieNode {
        TrieNode* child[26] = {};
        string word = "";};
    TrieNode* root = new TrieNode();
    void insert(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx])
                node->child[idx] = new TrieNode();
            node = node->child[idx];} node->word = word ;}

    void dfs(int i, int j, vector<vector<char>>& board, TrieNode* node,vector<string>& res) {
        char c = board[i][j];
        if (c == '#' || !node->child[c - 'a']) return;
        node = node->child[c - 'a'];
        if (node->word != "") {    res.push_back(node->word);node->word = ""; // avoid duplicates}
        board[i][j] = '#';
        int n = board.size(); int m = board[0].size();
        // 🔥 4 explicit DFS calls (your style)
        if (i + 1 < n) dfs(i + 1, j, board, node, res);
        if (i - 1 >= 0) dfs(i - 1, j, board, node, res);
        if (j + 1 < m) dfs(i, j + 1, board, node, res);
        if (j - 1 >= 0) dfs(i, j - 1, board, node, res);
        board[i][j] = c;}

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (auto &w : words)
            insert(w);
        vector<string> res;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(i, j, board, root, res);}}
        return res;}};

//////////////////////////////////////////////////////////

vector<int> num_of_visible_points(const vector<Tree>& points, double angle_rad, const vector<int>& location)
{
    // 1. convert all the points to angles
    vector<pair<double, int>> angles;
    angle_rad = angle_rad * M_PI / 180;

    double x = location[0];
    double y = location[1];
    int same_points = 0;
    for(auto i : points)
    {
        // atan2(y-y1, x-x1)
        double x1 = i.x;
        double y1 = i.y;
        // edge case 1
        if(x1==x && y1==y)
        {
            same_points ++;
            continue;
        }
        double ang = atan2(y1-y, x1-x);
        angles.push_back({ang, i.ID}); 
    }

    // 2. Sort all the angles
    sort(angles.begin(), angles.end());

    // edge case 2
    int n = angles.size();
    for(size_t i=0; i<n; i++)
    {
        angles.push_back({angles[i].first + 2 * M_PI, angles[i].second});
    }
    // 3. sliding window to get the maximum
    int max_points = 0;
    int best_left = 0;
    int left = 0;
    vector<int> results;
    for(int right = 0; right < angles.size(); right++)
    {
        while((angles[right].first - angles[left].first) > angle_rad)
        {
            left ++;
        }
        int curr_points = right - left + 1;
        if(curr_points > max_points)
        {
            best_left = left;
            max_points = curr_points;
        }
        //max_points = max(max_points, right - left + 1);
    }
    for (size_t i = best_left; i < (best_left + max_points); i++)
    {
        results.push_back(angles[i].second);
    }
    return results;
    //return max_points + same_points;
}