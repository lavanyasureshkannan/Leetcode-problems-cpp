#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;
int main()
{
    vector<int> v {100,100,120,30,10,30,40,50,50};
    unordered_set <int> s (v.begin(), v.end());
    for(auto i : s)
    {
        cout << i << endl;
    } 
    return 0;
}