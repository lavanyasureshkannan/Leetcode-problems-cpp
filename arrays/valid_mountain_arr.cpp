class Solution 
{
public:
    bool validMountainArray(vector<int>& arr) 
    {
        int left = 0;
        int right = arr.size();
        
        // walking up
        while(left+1 < right && arr[left] < arr[left+1]) left++;
        
        // peak cant be first or last
        if(left == 0 || left == right -1) return false;
        // walking down
        while(left+1 < right && arr[left] > arr[left+1]) left++;
        
        return left == right -1;
        
    }
};

// TIME COMPLEXITY O(N) --> N is the size of A
// SPACE COMPLEXITY O(1)