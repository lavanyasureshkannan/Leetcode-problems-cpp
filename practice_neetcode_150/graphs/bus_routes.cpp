#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
    Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
    Output: 2
*/

int bus_routes(vector<vector<int>>& routes, int source, int target)
{
    // base case
    if(source == target) return 0;
    // 1. build an adj list from the routes
    unordered_map<int, vector<int>> stop_to_buses;
    for(size_t route=0; route<routes.size(); route++)
    {
        for(size_t stop:routes[route])
        {
            stop_to_buses[stop].push_back(route);
        }
    }
    /*
        stops    bus
          1       0
          2       0
          7       0,1
          3       1
          6       1
    */

    // 2. Look for the bus that takes in the source stop
    queue<int> q;
    unordered_set<int> visited;
    for(auto route : stop_to_buses[source]) 
    {
        q.push(route); // bus 0 takes it -> from stop_to_bus list
        visited.insert(route); // marked
    }
    int bus_count = 1;

    // 3. jump into the q
    while(!q.empty())
    {
        int q_size = q.size();
        for(size_t i=0; i<q_size; i++)
        {
            int bus = q.front();
            q.pop();

            // 4. Get all the stops that the bus takes and see if it reaches the target
            for(auto stop : routes[bus])
            {
                if(stop == target)
                {
                    return bus_count;
                }
                // 5. If not push the stops to the q
                for(auto nextRoute : stop_to_buses[stop])
                {
                    if(!visited.count(nextRoute))
                    {
                        visited.insert(nextRoute);
                        q.push(nextRoute);
                    }
                }
            }

        }
        bus_count ++;
    }
    return -1;
}

// TC: O(V+E)
// SC: O(V+E)

int main()
{
    vector<vector<int>>routes = {{1,2,7},{3,6,7}};
    int source = 1;
    int target = 6;
    cout << bus_routes(routes, source, target) << endl;
    return 0;
}