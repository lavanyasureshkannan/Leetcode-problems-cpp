88. Merge Sorted Array

APPROACH1 :

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0; i < nums2.size(); i++){
            nums1[i+m] = nums2[i];
        }
        sort(nums1.begin(),nums1.end());
        
    }
};
TIme complexity = O((n + m).log(n + m))

APPROACH2:

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;
        for(int i = 0; i < m; i++){
            res.push_back(nums1[i]);
        }
        for (int i=0; i <n; i++){
            res.push_back(nums2[i]);
        }
        sort(res.begin(),res.end());
        nums1  = res;
        
    }
};
time O((n + m).log(n + m))

