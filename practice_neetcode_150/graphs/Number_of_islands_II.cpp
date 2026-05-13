class Solution {
public:
    vector<int> numIslands2(int n, int m, vector<vector<int>>& positions) {
        
        vector<int> parent(n * m, -1);
        vector<int> rank(n * m, 0);
        vector<int> result;
        
        int count = 0;
        
        vector<int> dir = {0,1,0,-1,0};
        
        function<int(int)> find = [&](int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        };
        
        auto unite = [&](int x, int y) {
            int px = find(x);
            int py = find(y);
            
            if (px == py) return false;
            
            if (rank[px] < rank[py])
                parent[px] = py;
            else if (rank[px] > rank[py])
                parent[py] = px;
            else {
                parent[py] = px;
                rank[px]++;
            }
            return true;
        };
        
        for (auto &pos : positions) {
            int r = pos[0], c = pos[1];
            int idx = r * m + c;
            
            // already land
            if (parent[idx] != -1) {
                result.push_back(count);
                continue;
            }
            
            parent[idx] = idx;
            count++;  // new island
            
            // check 4 directions
            for (int d = 0; d < 4; d++) {
                int nr = r + dir[d];
                int nc = c + dir[d+1];
                
                int nidx = nr * m + nc;
                
                if (nr >= 0 && nc >= 0 && nr < n && nc < m && parent[nidx] != -1) {
                    if (unite(idx, nidx)) {
                        count--;  // merged islands
                    }
                }
            }
            
            result.push_back(count);
        }
        
        return result;
    }
};