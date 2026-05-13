#include <iostream>
#include <vector>
/*
Allocate a block of size consecutive free memory units and assign it the id mID.
Free all memory units with the given id mID.

n  = 7
[0,0,0,0,0,0,0]
allocate(3,1) // (size, mID)
[1,1,1,0,0,0,0] => 
allocate(2,2)
[1,1,1,2,2,0,0]
deallocate(1)
[0,0,0,2,2,0,0]
*/

class Memory_Allocator
{
    public:
    Memory_Allocator(size_t m_n) : n(m_n)
    {
        freeblock = std::vector<int>(n,0);
    }

    int allocate(size_t size, size_t mID)
    {
        bool canAllocate = false;
        // step 1 : check
        for(size_t i=0; i<=(n-size); i++)
        {
            canAllocate = true;
            for(size_t j=0; j<size; j++)
            {
                if(freeblock[i+j] != 0)
                {
                    canAllocate = false;
                    break;
                }
            }

            // step 2. write
            if(canAllocate)
            {
                for(size_t j=0; j<size; j++)
                {
                    freeblock[i+j] = mID;
                }
                return i;
            }
        }
        return -1;
    }

    int deallocate(size_t mID)
    {
        int freed = 0;
        for(size_t i=0; i<n; i++)
        {
            if(freeblock[i] == mID)
            {
                freeblock[i] = 0;
                freed ++;
            }
        }
        return freed;
    }

    private:
    size_t n;
    std::vector<int> freeblock;
};

//TC: O(N)
//SC: O(N)

int main()
{
    Memory_Allocator mb(7);
    std::cout << mb.allocate(3,1) << std::endl;
    std::cout << mb.allocate(2,2) << std::endl;
    std::cout << mb.deallocate(1) << std::endl;
    return 0;
}