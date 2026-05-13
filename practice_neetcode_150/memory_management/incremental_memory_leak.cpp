#include <iostream>
#include <vector>

/*
Input: memory1 = 2, memory2 = 2
Output: [3,1,0]
Explanation: The memory is allocated as follows:
- At the 1st second, 1 bit of memory is allocated to stick 1. The first stick now has 1 bit of available memory.
- At the 2nd second, 2 bits of memory are allocated to stick 2. The second stick now has 0 bits of available memory.
- At the 3rd second, the program crashes. The sticks have 1 and 0 bits available respectively.
*/

std::vector<int> memory_leak(int memory1, int memory2)
{
    int time = 1;
    while(true)
    {
        if(memory1 >= memory2)
        {
            if(memory1 >= time)
            {
                memory1 -= time;
            }
            else break;
        }
        else
        {
            if(memory2 >= time)
            {
                memory2 -= time;
            }
            else break;
        }
        time ++;
    }
    return {time, memory1, memory2};
}


int main()
{
    return 0;
}