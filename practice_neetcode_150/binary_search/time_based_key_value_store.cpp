#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
["TimeMap", "set", ["alice", "happy", 1], "get", ["alice", 1], "get", ["alice", 2], "set", ["alice", "sad", 3], "get", ["alice", 3]]
Output:
[null, null, "happy", "happy", null, "sad"]
Explanation:
TimeMap timeMap = new TimeMap();
timeMap.set("alice", "happy", 1);  // store the key "alice" and value "happy" along with timestamp = 1.
timeMap.get("alice", 1);           // return "happy"
timeMap.get("alice", 2);           // return "happy", there is no value stored for timestamp 2, thus we return the value at timestamp 1.
timeMap.set("alice", "sad", 3);    // store the key "alice" and value "sad" along with timestamp = 3.
timeMap.get("alice", 3);           // return "sad
*/

class TimeMap
{
    public:
    TimeMap() {}

    unordered_map<string, vector<pair<int,string>>> mp;
    void set(string key, string value, int time)
    {
        mp[key].emplace_back(time, value); // mp["foo"] = {{"bar",1},{"bar2,2"} ...}
    }

    string get(string key, int time)
    {
        auto &values = mp[key];
        int left = 0;
        int right = values.size() - 1;
        string result = "";
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(values[mid].first <= time)
            {
                result = values[mid].second;
                left = mid + 1;
            }
            right = mid - 1;
        }
        return result;
    }
};

int main()
{
    TimeMap TM1;
    TM1.set("alice", "happy", 1);
    cout << TM1.get("alice", 1);
    return 0;
}