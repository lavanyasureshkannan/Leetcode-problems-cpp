#include<iostream>
#include<vector>

int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
{
    int n = gas.size();
    int total_tank = 0;
    int curr_tank = 0;
    int starting_point = 0;
    for(int i=0; i<n; i++)
    {
        total_tank += gas[i] - cost[i];
        curr_tank += gas[i] - cost[i];
        if(curr_tank < 0)
        {
            starting_point = i+1; //check for negative and choose the starting point accordingly
            curr_tank = 0;
        } 
    }
    return (total_tank < 0) ? -1 : starting_point; // if the total tank gets negative return -1 else just return a strating point
}

// TC: O(N) since there is only one loop over all stations here.
// SC: O(1) since it's a constant space solution. 

int main()
{
    return 0;
}