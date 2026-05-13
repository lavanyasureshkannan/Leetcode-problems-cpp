#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main()
{
    vector<int> v {100,120,30,10,30,40,50,50};
    unordered_map<int,int> mp1;
    for(int i=0; i<v.size(); i++)
    {
        mp1[v[i]] ++;
    }
    for(auto it = mp1.begin(); it != mp1.end(); )
    {
        if(it->second == 1)
        {
            it = mp1.erase(it);
        }
        else
        {
            it++;
        }
    }
    for(auto i : mp1)
    {
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}