#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

/*
A sparse vector is a vector that has a large number of zeros so it takes unwanted space to store these zeroes.
The task is to store a given sparse vector efficiently without storing the zeros.
Dot product of two vectors => scalar
*/

// APPROACH 1 -> ignoring the sparsity of the array
class SparseVector
{
    public:
    // store the nums in a different container
    vector<int> array;
    SparseVector(vector<int> &nums) 
    {
        // copying numbers to array
        array = nums;
    }

    int dotProduct(SparseVector& vec)
    {
        int result = 0;
        for(int i=0; i<array.size(); i++)
        {
            // result = v1.dotProduct(v2);
            result = result + (array[i] * vec.array[i]); // array[i] => vector 1
                                                        // vec.array[i] => vector 2 
        }
        return result;
    }
};

// TC: O(N) or both constructing the sparse vector and calculating the dot product.
// SC: O(1) or constructing the sparse vector as we simply save a reference to the input array and O(1) for calculating the dot product.






// APPROACH 2 -> using unordered map
class SparseVector
{
    public:
    // create an unordered_map
    unordered_map<int, int>mp; // <key:index, val:non_zero_num>
    SparseVector(vector<int>& nums)
    {
        for(int i=0; i<nums.size(); i++)
        {
            //check if the vector has non-zero elements 
            if(nums[i] != 0)
            {
                mp[i] = nums[i];
            }
        }
    }

    int dotProduct(SparseVector& vec)
    {
        int result = 0;
        // comparing the two vectors and finding if its indexes matches
        for(auto i = mp.begin(); i != mp.end(); i++)
        {
            // if the indexes matches then do dot product
            result = result + (vec.mp[i->first] * i->second);
        } 
        
        return result;
    }

};

// TC: O(N) -> creating hashmap and calculating the dot product
// SC: O(L) -> creating map and O(1) for dot product 


// Approach 3 -> when you get the follow up
// follow up -> What if only one of the vectors is sparse? ->two pointer approach
class SparseVector 
{   
public:
    vector<int> nums;
    vector<int> nonZeros;
    SparseVector(vector<int> &nums) 
    {
        this->nums = nums;
        for (int i=0; i<nums.size();i++) 
        {
            if (nums[i] != 0)
                nonZeros.push_back(i);
        }
    }
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) 
    {
        int left = 0;
        int right = 0;
        int result = 0;
        while (left < nonZeros.size() && right < vec.nonZeros.size()) 
        {
            if (nonZeros[left] > vec.nonZeros[right])
                right ++;
            else if (nonZeros[left] < vec.nonZeros[right])
                left ++;
            else 
            {
                result += nums[nonZeros[left]] * vec.nums[vec.nonZeros[right]];
                left ++;
                right ++;
            }
        }
        return result;
    }
};

// TC: O(N)
// SC: O(L)


int main()
{
    return 0;
}