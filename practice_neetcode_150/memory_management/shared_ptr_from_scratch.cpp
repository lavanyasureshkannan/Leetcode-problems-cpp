#include <iostream>
#include <memory>
#include <memory>

/*
    A shared_ptr is a smart pointer that lets multiple parts of your program
    own the SAME object safely.
    
    Example:

    auto p1 = std::make_shared<int>(10);
    auto p2 = p1;   // shared ownership

    p1 → same object, p2 → same object, ref count = 2

    Example:

    Radar frame → used by:
  - perception module
  - visualization module
  - logging module

    auto frame = std::make_shared<Frame>();
    perception.process(frame);
    visualization.render(frame);
    logger.store(frame);

    ✔ Nobody deletes it prematurely
    ✔ Memory is freed only when ALL are done

*/

template<typename T>
class Shared_pointer_class
{
    public:

    //contructor
    explicit Shared_pointer_class(T* p) 
    {
        ptr = p;
        if(p != nullptr)
        {
            ref_counts = new int(1);
        }
        else
        {
            ref_counts = nullptr;
        }
    }
    // destructor
    ~Shared_pointer_class()   
    {
        cleanup();
    }
    // copy assignment
    // copy constructor
    Shared_pointer_class(const Shared_pointer_class& other) 
    {
        ptr = other.ptr;
        ref_counts = other.ref_counts;
        // increment ref count
        if(*ref_counts) 
        {
            (*ref_counts) ++;
        }
    }
    // copy assignment operator
    Shared_pointer_class& operator = (const Shared_pointer_class& other)
    {
        if(this != &other)
        {
            cleanup();
            ptr = other.ptr;
            ref_counts = other.ref_counts;
            if(ref_counts)
            {
                (*ref_counts) ++;
            }
        }
        return *this;
    }
    
    // move assignmenet
    Shared_pointer_class(Shared_pointer_class&& other) noexcept
    {
        ptr = other.ptr;
        ref_counts = other.ref_counts;
        other.ptr = nullptr;
        other.ref_counts = nullptr;
    }
    // overloading operators
    Shared_pointer_class& operator = (Shared_pointer_class&& other) noexcept
    {
        if(this != &other)
        {
            cleanup();
            ptr = other.ptr;
            ref_counts = other.ref_counts;
            other.ptr = nullptr;
            other.ref_counts = nullptr;
        }
        return *this;
    }

    T& operator * () const { return *ptr; }
    T* operator -> () const { return ptr;}
    T* get() { return ptr; }

    int use_count() const
    {
        if(ref_counts) return *ref_counts;
        else return 0;
    }
    private:
    T* ptr;
    std::atomic<int> *ref_counts; // pointer to the shared reference count
    void cleanup()
    {
        if(ref_counts)
        {
            (*ref_counts) --;
            if(*ref_counts == 0)
            {
                delete ptr;
                delete ref_counts;
            }
        }
    }

};


int main()
{
    // std::shared_ptr<int> ptr_a = std::make_shared<int>(5);
    // std::cout << *ptr_a << std::endl;

    Shared_pointer_class<int> ptr1(new int(100));
    std::cout << "value: " << *ptr1 << std::endl;
    std::cout << "Ref_count: " << ptr1.use_count() << std::endl;

    {
        Shared_pointer_class<int> ptr2 = ptr1;
        std::cout << "After count copy: " << ptr1.use_count() << std::endl;
        *ptr2 = 200;
    }
    return 0;
}