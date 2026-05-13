#include <iostream>

/*
    Unique pointer from scratch using a raw pointer

    1. constructor
    2. destructor
    3. copy forbidden
    4. move ownership
*/


template<typename T>
class Unique_pointer
{
    public:
    // constructor
    explicit Unique_pointer(T* m_ptr) : ptr(m_ptr) { };

    // destructor
    ~Unique_pointer() { delete ptr;}

    // Disabling copy 
    Unique_pointer(const Unique_pointer&) = delete; 
    // copy contructor = delete
    Unique_pointer& operator = (const Unique_pointer&) = delete;

    // enable move ownership
    Unique_pointer(Unique_pointer&& other) noexcept
    // A contructor takes a movable uniqueptr and gurantees it wont throw exceptions
    {
        ptr = other.ptr; // takes ownership
        other.ptr = nullptr; // leave the old object ownership
    }

    Unique_pointer& operator = (Unique_pointer&& other) noexcept
    {
        if(this != &other) // (ptr1 adreess != p2 address)
        {
            delete ptr; // delete the curr resource
            ptr = other.ptr; // transfer the ownership 
            other.ptr = nullptr; // nullify the ownership
        }
        return *this;
    }

    // overload deference operator
    T& operator * () const { return *ptr; }
    // overload member access operator
    T* operator -> () const { return ptr;}
        // access the pointer
    T* get() const { return ptr;}

    private:
    T* ptr;
};


int main()
{
    Unique_pointer<int> ptr1(new int(20));
    std::cout << *ptr1 << std::endl;
    Unique_pointer<int> ptr2 = std::move(ptr1);
    //std::cout << *ptr1 << std::endl;
    std::cout << *ptr2 << std::endl;
    return 0;
}
