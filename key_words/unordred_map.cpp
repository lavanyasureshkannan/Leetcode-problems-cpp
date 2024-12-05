#include<iostream>
#include<unordered_map>
using namespace std;



int main()
{
    vector<int> arr = {1,1,2,2,3,3,4,4,5,5};
    unordered_map<int,int> freq_mp;
    for(int i=0;i<arr.size(); i++)
    {
        freq_mp[arr[i]]++;
    }
    //for(const auto& pair: freq_mp)
    //{
    //    cout << pair.first << ": " << pair.second << endl;
    //}
    //inorder to iterate through the mp in for(int i=0; i<arr.size(); i++) format, create a pair which is in vector format
    vector<pair<int,int>> mp_vect(freq_mp.begin(), freq_mp.end());
    for(int i=0; i<mp_vect.size(); i++)
    {
        cout << mp_vect[i].first << ": " << mp_vect[i].second << endl;
    }
    return 0;
}