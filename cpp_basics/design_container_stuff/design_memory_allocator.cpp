#include <iostream>
#include <vector>
using namespace std;

class Allocator
{
    public:
    int n;
    vector<int> memory;

    Allocator(int m_n)
    {
        n = m_n;
        memory = vector<int> (n,0);
    }
    int allocate(int size, int mID)
    {
        for(int i=0; i<=n-size; i++)
        {
            bool freeblock = true;
            for(int j=0; j<size; j++)
            {
                if(memory[i+j] != 0)
                {
                    freeblock = false;
                    break;
                }
            }

            if(freeblock)
            {
                for(int j=0; j<size; j++)
                {
                    memory[i+j] = mID;
                }
                return i;
            }
        }
        return -1;
    }

    int freememory(int mID)
    {
        int freed = 0;
        for(int i=0; i<memory.size(); i++)
        {
            if(memory[i] == mID)
            {
                memory[i] = 0;
                freed++;
            }
        }
        return freed;
    }
};

int main()
{
    Allocator alloc(10);
    cout << alloc.allocate(3,1) << endl;
    cout << alloc.allocate(4,2) << endl;
    cout << alloc.allocate(3,3) << endl;
    cout << alloc.freememory(2) << endl;
    return 0;
}