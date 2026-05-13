#include <iostream>
#include <memory>
#include <shared_mutex>
#include <mutex>
using namespace std;


/*
    1.
    Raw pointer owned by class → Rule of 5 REQUIRED
    compiler-generated copy = shallow = double free
    you must define all 5 or explicitly delete copy

    unique_ptr member → Rule of 0
    compiler-generated move = correct (transfers ownership)
    compiler-generated copy = deleted automatically
    you define nothing — compiler does the right thing

    Raw pointer                 Rule of 5
  (int*, uint8_t*, T*)      define all 5 or things break

    unique_ptr                  Rule of 0
  (unique_ptr<T>)           define nothing, compiler is correct

    shared_ptr                  Rule of 0
  (shared_ptr<T>)           define nothing, but copy increments ref count

    No heap resources           Rule of 0
  (just ints, strings)      define nothing, everything is fine

  2. Rule of 5
  
    Contructor
    Destructor
    move assignment / operator
    copy assignment / operator
    return size/overload operator

*/


/**********************************************************************************/
// QUESTION 1

// int* get_value()
// {
//     int x = 42;
//     return &x;
// }

/*
    Returning the local variable ends up having dangling pointer
*/

// int* get_value()
// {
//     return new int (42);Raw pointer owned by class → Rule of 5 REQUIRED
// }

// std::unique_ptr<int> get_value()
// {
//     return std::make_unique<int>(42);
// }

/***********************************************************************************/
// QUESTION 2

// void delete_ptr()
// {
//     int* p = new int(10);
//     int* q = p;
//     delete p;
//     delete q;
// }

/* 
 double free. p and q point to the same heap address. 
 delete p frees the memory. 
 delete q calls free on an already-freed address — corrupts the heap allocator's metadata.
*/

/************************************************************************************/

// QUESTION 3

// void run_pipeline() 
// {
//     //SensorData* data = new SensorData();
//     auto data = std::make_unique<SensorData> ();
//     data->load_frame();
     
//     try 
//     {
//         process(data.get());   // may throw
//     } catch (...)

//     {
//         std::cerr << "processing failed";
//         return;          // data leaked on exception
//     }
     
//     delete data;
// }

/**********************************************************************************************/

// QUESTION 4

// std::unique_ptr<int> create() 
// {
//     return std::make_unique<int>(99);
// }

// std::string* get_name() 
// {
//     std::string name = "radar_sensor";
//     return &name;
// }

// unique_ptr<string> get_name()
// {
//     return make_unique<string>("radar_Sensor");
// }

// string get_name()
// {
//     return ("radar_sensor");
// }

// void setup() 
// {
//     std::string p = get_name();
//     std::cout << p << std::endl;  // use after free
// }

/**************************************************************************************************/

// QUESTION 5

// class FrameBuffer 
// {
//     public:
//     FrameBuffer(size_t size) 
//     {
//         data_ = new uint8_t[size];
//         size_ = size;
//     }
//     ~FrameBuffer() 
//     {
//         delete[] data_;
//     }
//     // no copy constructor defined
//     // no copy assignment defined
// private:
//     uint8_t* data_;
//     size_t size_;
// };

// FrameBuffer a(1024);
// FrameBuffer b = a;   // copy

/*
: Rule of 5 violation. 
Destructor defined but no copy constructor — compiler generates shallow copy. b.data_ == a.data_ (same pointer). 
Both destructors call delete[] on the same pointer — double free, heap corruption, crash.
*/ 

/******************************************************************************/

// QUESTION 6

// void write_log(const std::string& msg) 
// {
//     FILE* f = fopen("pipeline.log", "a");
    
//     if (msg.empty()) 
//     {
//         fclose(f);
//         return;  // the file was never closed  
//     }
    
//     fprintf(f, "%s", msg.c_str());
//     fclose(f);
// }

/******************************************************************************/

auto calib = std::make_shared<CalibMatrix>();
shared_mutex calib_mutex;
void perception_thread() 
{
    // read calibration
    shared_lock lock(calib_mutex);
    float val = calib->data[0];   // thread A reads
}

void calibration_thread() 
{
    // update calibration
    unique_lock lock(calib_mutex);
    calib->data[0] = new_value;   // thread B writes
}

/********************************************************************/
struct Node 
{
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;   // bidirectional
    int value;
};

// auto a = std::make_shared<Node>();
// auto b = std::make_shared<Node>();
// a->next = b;   // b ref count = 2
// b->prev = a;   // a ref count = 2
// main's ptrs go out of scope
// a: 2->1, b: 2->1 — neither reaches 0 — LEAK

// if (auto locked = node->prev.lock()) {
//     locked->do_work();   // object still alive
// }  

int main()
{
    // std::unique_ptr<int> ptr = get_value();
    // std::cout << *ptr << std::endl;

    // int *p = new int(30);
    // int *q = p;

    // cout << "Address of p: " << p << " value of p: " << *p << endl;
    // cout << "Address of q: " << q << " value of q: " << *q << endl;

    // std::unique_ptr<int> a = create();
    // std::unique_ptr<int> b = move(a);   // copy
    // std::cout << *b << std::endl;

    // shared_ptr<int> a = create();
    // shared_ptr<int> b = a;
    // //shared_ptr<>
    // cout << b.use_count() << endl;


    // cout << &a << endl;
    // cout << &b << endl;

    return 0;
}