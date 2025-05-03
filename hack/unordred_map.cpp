#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
1. given an array store the index as key and element as value
*/

unordered_map <int,int> convert_mp(vector<int>& nums)
{
    unordered_map<int,int> mp;
    for(int i=0; i<nums.size(); i++)
    {
        mp[i] = nums[i];
    }
    // iterate through the unordered map
    for(const auto& pair : mp)
    {
        cout << "Index: " << pair.first << " Values: " << pair.second << endl;
    }
    return mp;
}


/*
2. store the number of occurences
*/
unordered_map <int,int> store_occurences(vector<int>& nums)
{
    unordered_map<int,int> mp;
    for(int i=0; i<nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    //iterate throough unordered map
    for(const auto& pair : mp)
    {
        cout << "Element: " << pair.first << " ocurences: " << pair.second << endl;
    }
    return mp;

}


int main()
{
    vector<int> arr = {1,1,2,2,3,3,4,4,5,5};
    //convert_mp(arr);
    store_occurences(arr);





    // unordered_map<int,int> freq_mp;
    // for(int i=0;i<arr.size(); i++)
    // {
    //     freq_mp[arr[i]]++;
    // }
    //for(const auto& pair: freq_mp)
    //{
    //    cout << pair.first << ": " << pair.second << endl;
    //}
    //inorder to iterate through the mp in for(int i=0; i<arr.size(); i++) format, create a pair which is in vector format
    // vector<pair<int,int>> mp_vect(freq_mp.begin(), freq_mp.end());
    // for(int i=0; i<mp_vect.size(); i++)
    // {
    //     cout << mp_vect[i].first << ": " << mp_vect[i].second << endl;
    // }
    // return 0;
}