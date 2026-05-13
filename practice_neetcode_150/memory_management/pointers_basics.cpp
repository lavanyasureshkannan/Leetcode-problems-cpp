#include <iostream>
#include <memory>

/*
    Dangling pointer -> pointer exists but the memeory inside is gone. so setting it to nullptr is important.
    Double deleting a pointer -> results in crash

    
*/

template<typename... Args>
void Log(Args... args)
{
    (std::cout << ... << args) << std::endl;
}

struct dets
{
    size_t det_id;
    float range;
    float azimuth;
    float elevation;
};

int main()
{
    // int *ptr = new int(10);
    // Log("Before deleting: ", *ptr);
    // delete ptr;
    // delete ptr; // crash
    // ptr = nullptr;
    // Log("after deleting: ", ptr); // dangling pointer
    
    // std::unique_ptr<int> p = std::make_unique<int>(10);


    // {
    //     std::unique_ptr<dets> ptr_det = std::make_unique<dets>();
    //     ptr_det->det_id = 1;
    // }

    std::unique_ptr<int> p = std::make_unique<int> (10);
    Log("Value of p: ", *p);
    std::unique_ptr<int> q = move(p);
    //Log("after owner change value of p: ", *p); // segmentation fault 
    Log("after owner change value of q: ", *q);
    return 0;
}