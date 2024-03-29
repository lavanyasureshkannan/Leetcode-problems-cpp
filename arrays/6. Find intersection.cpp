350. Intersection of Two Arrays II

1.APPROACH USING SET INTERSECTION

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        vector<int> result;  
        set_intersection(begin(nums1),end(nums1),begin(nums2),end(nums2), inserter(result, end(result)));
        return result;
        
    }
};

// TC: O(nlogn + mlogm) 
// SC: O(log m + n)
