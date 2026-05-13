#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    vector<int> v{100,120,30,10,30,40,50,50};
    set<int>s(v.begin(), v.end());
    // for(auto i : s)
    // {
    //     cout << i << endl; 
    // }
    
    // 1. Finding a number from the set
    int target = 50;
    auto it = s.find(target);
    // if(it != s.end())
    // {
    //     cout << *it << endl;
    // }

    // 2. check if the number is there are not
    // if(s.count(target))
    // {
    //     cout << "Found" << endl;
    // }

    // 3. Find the target and remove it
    if(s.count(target))
    {
        s.erase(target);
    }
    
    cout << "printing the remaining" << endl;
    for(auto i : s)
    {
        cout << i << endl; 
    }



    return 0;
}