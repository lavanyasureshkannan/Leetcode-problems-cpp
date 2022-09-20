#include<iostream>
#include<unordered_set>
using namespace std;

bool contains_duplicates(vector<int>& keys)
{
    unordered_set<int> st(keys.begin(), keys.end());
    return (nums.size() != keys.size());

}


bool findDuplicates(vector<int>& keys)
{
    unordered_set<int> st;
    for(auto i : keys)
    {
        if(st.count(i) > 0) return true;
        st.insert(i);
    }
    return false;
}

int main()
{
    return 0;
}