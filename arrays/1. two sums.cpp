1. APPROACH ONE

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0 ; i <nums.size() ; i++){
            for (int j = i+1 ; j<nums.size() ; j++){
                if (nums[i]+ nums[j] == target) {
                    result = {i,j};
                }
            }
        }
        return result;
    }
};

// TIME COMPLEXITY O(N^2)
// SPACE COMPLEXITY O(N)

2. APPROACH 2 USING HASHMAPS

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map <int,int> hmap;
        vector<int> result;
        for(int i = 0;i< nums.size();i++)
        {
            // current element + x = target
            // x = target - current element 
            int search = target - nums[i];
            // find that search element in your map
            if (hmap.find(search) != hmap.end())
            {
                result.push_back(i);
                result.push_back(hmap[search]);
                return result;
            }
            
            else
            {
                hmap[nums[i]] = i;
                
            }
        }
        
        return result;
        }
};

};
// TIME COMPLEXITY O(N)
// SPACE COMPLEXITY O(N)
