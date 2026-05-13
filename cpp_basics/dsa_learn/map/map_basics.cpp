#include <iostream>
#include <unordered_map>
int main()
{
    std::unordered_map<int,int> mp;
    mp.insert({1,2});
    mp.insert({2, 30});
    mp.insert({1, 40});
    mp.insert({3, 60});
    mp.insert({4, 20});
    mp.insert({5, 50});

    std::cout << mp[5] << std::endl;
    std::cout << mp.count(1) << std::endl;

    return 0;
}