#include <iostream>

/*
    GPU buffer
    1. contructor
    2. destructor
    3. copying frobidden
    4. move assignment
    5. return data
*/


class GPU_Buffer
{
    public:
    // constructor
    GPU_Buffer(size_t m_size) : buffer_size(m_size) 
    {
        ptr = std::malloc(m_size);
    }
    // destructor
    ~GPU_Buffer()
    {
        std::free(ptr);
    }
    // disabling copy
    GPU_Buffer(const GPU_Buffer&) = delete;
    GPU_Buffer& operator = (const GPU_Buffer&) = delete;

    // // move assignment
    GPU_Buffer(GPU_Buffer&& other) noexcept
    {
        ptr = other.ptr;
        other.ptr = nullptr;
        other.buffer_size = 0;
    }

    GPU_Buffer& operator = (GPU_Buffer&& other) noexcept
    {
        if(this != &other)
        {
            std::free(ptr);
            ptr = other.ptr;
            other.ptr = nullptr;
            other.buffer_size = 0;
        }
        return *this;
    }
    void* data() const { return ptr;} 
    private:
    void* ptr = nullptr;
    size_t buffer_size;

};


int main()
{
    GPU_Buffer gpu_buffer(sizeof(int));
    int* myIntPtr = static_cast<int*>(gpu_buffer.data());
    *myIntPtr = 20;
    std::cout << "Value in gpu buffer: " << *myIntPtr << std::endl;
    return 0;
}