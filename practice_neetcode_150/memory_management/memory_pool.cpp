#include <iostream>
#include <thread>
#include <mutex>
/*
    Memory pool : A memory pool is a memory management technique where a large block of memory is pre-allocated upfront 
    and divided into smaller, typically fixed-size chunks

    Memory Pool = preallocated + fast reuse

    1. constructor
    2. allocator
    3. deallocator
    4. destrutor

    POOL (contiguous memory)
    [ B0 ][ B1 ][ B2 ][ B3 ]
        |     |     |     |
    freeList head
*/

template<typename T>
class Memory_Pool
{
    public:
    Memory_Pool(size_t size) : m_size(size)
    {
        pool = new Block[m_size];
        for(size_t i=0; i<m_size -1; i++)
        {
            // freelist -> [b0] -> [b1] ->[bn] -> nullptr
            pool[i].next = &pool[i+1]; // [b0] -> [b1] ->[bn]
        }
        pool[m_size - 1].next = nullptr;
        freelist = &pool[0];
    }

    T* allocate()
    {
        std::lock_guard<std::mutex> lg(mtx);
        // checks if the freelist is empty
        if(!freelist) return nullptr;
        Block* block = freelist; //grabbing current empty spot
        freelist = freelist->next;
        return(&block->data); // giving just the address of data portion where they can store anything
    }

    void deallocate(T* ptr)
    {
        // check the ptr
        if(!ptr) return;
        std::lock_guard<std::mutex> lg(mtx);
        // cast the pointer back to block and push it into free list
        Block* block = reinterpret_cast<Block*>(ptr);
        block->next = freelist;
        freelist = block;
    }

    ~Memory_Pool()
    {
        delete[] pool;
    }

    private:
    // using struct The block size is sizeof(T) + sizeof(Block*).
    // using union The block size is max(sizeof(T), sizeof(Block*))
    /*
    "The union means when a block is free, its memory stores the next-free pointer. 
    When allocated, that same memory stores user data. 
    They're mutually exclusive so they share the same space — zero overhead for the free list. 
    Allocate and deallocate are both O(1).
    */
    union Block
    {
        T data;
        Block* next;
    };
    size_t m_size;
    Block* pool; // [B0] [B1] [B2] [B3]
    Block* freelist;
    std::mutex mtx;

};

int main()
{
    Memory_Pool<int> mp(3);
    int *val_1 = mp.allocate(); *val_1 = 40;
    int *val_2 = mp.allocate(); *val_2 = 42;
    int *val_3 = mp.allocate(); *val_3 = 44;

    std::cout << "Values: " << *val_1 << ", " << *val_2 << ", " << *val_3 << "\n";
    std::cout << "Addresses: " << val_1 << ", " << val_2 << ", " << val_3 << "\n";

    mp.deallocate(val_2);
    // val_2 = nullptr
    std::cout << "Adrresses: "<< val_2 << " values: " << *val_2 << std::endl;
    return 0;
}