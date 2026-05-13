/////////////////// MEMORY ///////////////////////////

////// MEMORY POOL ///////////////////////
template<typename T>
class Memory_Pool{
    public:
    Memory_Pool(size_t size) : m_size(size){
        pool = new Block[m_size];
        for(size_t i=0; i<m_size -1; i++){
            // freelist -> [b0] -> [b1] ->[bn] -> nullptr
            pool[i].next = &pool[i+1]; // [b0] -> [b1] ->[bn]
        }
        pool[m_size - 1].next = nullptr;
        freelist = &pool[0];}
    T* allocate(){
        std::lock_guard<std::mutex> lg(mtx);
        // checks if the freelist is empty
        if(!freelist) return nullptr;
        Block* block = freelist; //grabbing current empty spot
        freelist = freelist->next;
        return(&block->data); // giving just the address of data portion where they can store anything
    }
    void deallocate(T* ptr){
        // check the ptr
        if(!ptr) return;
        std::lock_guard<std::mutex> lg(mtx);
        // cast the pointer back to block and push it into free list
        Block* block = reinterpret_cast<Block*>(ptr);
        block->next = freelist;
        freelist = block;}
    ~Memory_Pool(){
        delete[] pool;}
    private:
    // using struct The block size is sizeof(T) + sizeof(Block*).
    // using union The block size is max(sizeof(T), sizeof(Block*))
    /*
    "The union means when a block is free, its memory stores the next-free pointer. 
    When allocated, that same memory stores user data. 
    They're mutually exclusive so they share the same space — zero overhead for the free list. 
    Allocate and deallocate are both O(1).
    */
    union Block{
        T data;
        Block* next;};
    size_t m_size;
    Block* pool; // [B0] [B1] [B2] [B3]
    Block* freelist;
    std::mutex mtx;};

// int main()
// {
//     Memory_Pool<int> mp(3);
//     int *val_1 = mp.allocate(); *val_1 = 40;
//     int *val_2 = mp.allocate(); *val_2 = 42;
//     int *val_3 = mp.allocate(); *val_3 = 44;
//     std::cout << "Values: " << *val_1 << ", " << *val_2 << ", " << *val_3 << "\n";
//     std::cout << "Addresses: " << val_1 << ", " << val_2 << ", " << val_3 << "\n";
//     mp.deallocate(val_2);
//     // val_2 = nullptr
//     std::cout << "Adrresses: "<< val_2 << " values: " << *val_2 << std::endl;
//     return 0;
// }

/*************************************************************************************/
//////////// GPU BUFFER /////////////////////////////////////////

class GPU_Buffer{
    public:
    // constructor
    GPU_Buffer(size_t m_size) : buffer_size(m_size) {ptr = std::malloc(m_size);}
    // destructor
    ~GPU_Buffer(){std::free(ptr);}
    // disabling copy
    GPU_Buffer(const GPU_Buffer&) = delete;
    GPU_Buffer& operator = (const GPU_Buffer&) = delete;
    // // move assignment
    GPU_Buffer(GPU_Buffer&& other) noexcept{
        ptr = other.ptr;
        other.ptr = nullptr;
        other.buffer_size = 0;}

    GPU_Buffer& operator = (GPU_Buffer&& other) noexcept{
        if(this != &other){
            std::free(ptr);
            ptr = other.ptr;
            other.ptr = nullptr;
            other.buffer_size = 0;}
        return *this;}
    void* data() const { return ptr;} 
    private:
    void* ptr = nullptr;
    size_t buffer_size;};
// int main(){
//     GPU_Buffer gpu_buffer(sizeof(int));
//     int* myIntPtr = static_cast<int*>(gpu_buffer.data());
//     *myIntPtr = 20;
//     std::cout << "Value in gpu buffer: " << *myIntPtr << std::endl;
//     return 0;}

///////////////////// UNIQUR PTR SCRATCH ///////////////////////////////
template<typename T>
class Unique_pointer{
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
    Unique_pointer& operator = (Unique_pointer&& other) noexcept{
        if(this != &other) // (ptr1 adreess != p2 address)
        {
            delete ptr; // delete the curr resource
            ptr = other.ptr; // transfer the ownership 
            other.ptr = nullptr; // nullify the ownership
        }
        return *this;}
    // overload deference operator
    T& operator * () const { return *ptr; }
    // overload member access operator
    T* operator -> () const { return ptr;}
        // access the pointer
    T* get() const { return ptr;}
    private:
    T* ptr;
};
// int main(){
//     Unique_pointer<int> ptr1(new int(20));
//     std::cout << *ptr1 << std::endl;
//     Unique_pointer<int> ptr2 = std::move(ptr1);
//     //std::cout << *ptr1 << std::endl;
//     std::cout << *ptr2 << std::endl;
//     return 0;}

///////////////// SHARED POINTER /////////////////////

template<typename T>
class Shared_pointer_class{
    public:
    //contructor
    explicit Shared_pointer_class(T* p) {
        ptr = p;
        if(p != nullptr){ref_counts = new int(1);}
        else{ref_counts = nullptr;}}
    // destructor
    ~Shared_pointer_class(){cleanup();}
    // copy assignment
    // copy constructor
    Shared_pointer_class(const Shared_pointer_class& other) {
        ptr = other.ptr;
        ref_counts = other.ref_counts;
        // increment ref count
        if(*ref_counts) {
            (*ref_counts) ++;}}
    // copy assignment operator
    Shared_pointer_class& operator = (const Shared_pointer_class& other){
        if(this != &other){
            cleanup();
            ptr = other.ptr;
            ref_counts = other.ref_counts;
            if(ref_counts){
                (*ref_counts) ++;}}
        return *this;}
    // move assignmenet
    Shared_pointer_class(Shared_pointer_class&& other) noexcept{
        ptr = other.ptr;
        ref_counts = other.ref_counts;
        other.ptr = nullptr;
        other.ref_counts = nullptr;}
    // overloading operators
    Shared_pointer_class& operator = (Shared_pointer_class&& other) noexcept{
        if(this != &other){
            cleanup();
            ptr = other.ptr;
            ref_counts = other.ref_counts;
            other.ptr = nullptr;
            other.ref_counts = nullptr;}
        return *this;}
    T& operator * () const { return *ptr; }
    T* operator -> () const { return ptr;}
    T* get() { return ptr; }
    int use_count() const{
        if(ref_counts) return *ref_counts;
        else return 0;}
    private:
    T* ptr;
    std::atomic<int> *ref_counts; // pointer to the shared reference count
    void cleanup(){
        if(ref_counts){
            (*ref_counts) --;
            if(*ref_counts == 0){
                delete ptr;
                delete ref_counts;}}}};
int main(){
    // std::shared_ptr<int> ptr_a = std::make_shared<int>(5);
    // std::cout << *ptr_a << std::endl;
    Shared_pointer_class<int> ptr1(new int(100));
    std::cout << "value: " << *ptr1 << std::endl;
    std::cout << "Ref_count: " << ptr1.use_count() << std::endl;{
        Shared_pointer_class<int> ptr2 = ptr1;
        std::cout << "After count copy: " << ptr1.use_count() << std::endl;
        *ptr2 = 200;}
    return 0;}

////////////////// LEETCODE MEMORY ALLOCATOR /////////////////////////////////////////

class Memory_Allocator{
    public:
    Memory_Allocator(size_t m_n) : n(m_n){
        freeblock = std::vector<int>(n,0);}

    int allocate(size_t size, size_t mID){
        bool canAllocate = false;
        // step 1 : check
        for(size_t i=0; i<=(n-size); i++){
            canAllocate = true;
            for(size_t j=0; j<size; j++){
                if(freeblock[i+j] != 0){
                    canAllocate = false;
                    break;}}
            // step 2. write
            if(canAllocate){
                for(size_t j=0; j<size; j++){
                    freeblock[i+j] = mID;}
                return i;}}
        return -1;}
    int deallocate(size_t mID){
        int freed = 0;
        for(size_t i=0; i<n; i++){
            if(freeblock[i] == mID){
                freeblock[i] = 0;
                freed ++;}}
        return freed;}
    private:
    size_t n;
    std::vector<int> freeblock;}

/////////////////////// MEMCPY /////////////////////

void* memcopy_scratch(void* dest, void* source, size_t size_n){
    // here when you just deal with pointers and keep incrementing it,
    // your compiler doesnt know how to increment => cvt to char 
    //Math Check: If you add 1 to an int*, it moves 4 bytes (the size of an int).
    // By casting to unsigned char*, you tell the compiler to move exactly 1 byte at a time
    unsigned char* d = static_cast<unsigned char*> (dest);
    const unsigned char* s = static_cast<unsigned char*> (source);
    for(size_t i=0; i<size_n; i++){
        d[i] = s[i];}
    return dest;}

///////////////////// memmove /////////////////////////////
void* myMemMove(void* dest, const void* src, size_t n) {
    char* d = (char*)dest;
    const char* s = (const char*)src;

    if (d == s || n == 0) return dest;

    if (d < s) {
        // Safe to copy forward
        for (size_t i = 0; i < n; i++) {
            d[i] = s[i];
        }
    } else {
        // Copy backward to prevent overwriting source
        for (size_t i = n; i > 0; i--) {
            d[i - 1] = s[i - 1];
        }
    }
    return dest;
} 



//////////////// LOCK GURAD FROM SCRATCH //////////////////////////////

template<typename T>
class LockGuard
{
    private:
    T& mutex_ref;
    // constructor locks upon object creation
    public:
    explicit LockGuard(T& mtx) : mutex_ref(mtx){mutex_ref.lock();}
    // destrcutor unlocks upon object destruction
    ~LockGuard(){mutex_ref.unlock();}
    // disable copying
    LockGuard(const LockGuard&) = delete;
    LockGuard &operator = (const LockGuard&) = delete;

    /*
    "why no move":
    "A lock_guard is scope-bound by design — it locks when created and unlocks when that scope exits. 
    Allowing move would mean transferring responsibility for the lock to a different scope, 
    which breaks the RAII guarantee and makes the unlock point unpredictable. 
    unique_ptr allows move because ownership can legitimately transfer between scopes. A lock cannot."

    */
};

///////////////////// THREADING /////////////////////////
///////////////BLOCKING QUEUE ////////////////////////

template<typename T>

class BoundedBlockingQueue{
    public:
    BoundedBlockingQueue(size_t cap) : capacity(cap) {};
    void enqueue(T val){{
            std::unique_lock<std::mutex> uql(mtx);
            cv.wait(uql, [this] () {
                return q.size() < capacity;
            }) ;
            q.push(std::move(val));
            Log("Enqueued val ", val);}
        cv.notify_one();}
    T dequeue(){
        T front_val;
        {
            std::unique_lock<std::mutex> uql(mtx);
            cv.wait(uql, [this] () {
                return !q.empty();
            });
            front_val = std::move(q.front());
            Log("Dequeued val: ", front_val);
            q.pop();}
        cv.notify_one();
        return front_val;}
    size_t size(){
        std::lock_guard<std::mutex> lg(mtx);
        return q.size(); }
    private:
    std::queue<T> q; std::mutex mtx; 
    std::condition_variable cv; size_t capacity;};

void producer(BoundedBlockingQueue<int>& bq){
    for(size_t i=0; i<5; i++){bq.enqueue(i);}}

void consumer(BoundedBlockingQueue<int>& bq){
    for(size_t i=0; i<5; i++){bq.dequeue();}}

// int main(){
//     BoundedBlockingQueue<int> bq(3);
//     std::thread t1(producer, std::ref(bq));
//     std::thread t2(consumer, std::ref(bq));

//     t1.join();
//     t2.join();
//     return 0;}

/////////////////// CIRCULAR BUFFER //////////////////////////

template<typename T>
class Cicular_buffer{
    public:
    explicit Cicular_buffer (size_t cap) : capacity(cap), buffer(cap) {};
    void push(T val){
        {    
            std::unique_lock<std::mutex> uql(mtx);
            cv.wait(uql, [this] ()
            {
                return (count < capacity);
            });
            buffer[tail] = std::move(val);
            tail = (tail + 1) % capacity;
            count ++;
            cv.notify_one();
        }
        Log("values pushed: ", val);}

    T pop(){
        std::unique_lock<std::mutex> uql(mtx);
        cv.wait(uql, [this] ()
        {
            return count > 0;
        });
        T val = std::move(buffer[head]);
        head = (head + 1) % capacity;
        count --;
        cv.notify_one();
        return val;}

    private:
    std::vector<T> buffer;=
    const size_t capacity; // [_,_,_,_,_]
                       //h       t
    size_t head = 0; // where we read
    size_t tail = 0; // where we write 
    size_t count = 0;

    std::mutex mtx;
    std::condition_variable cv;};

void producer(Cicular_buffer<int> &cb){
    for(size_t i=0; i<20; i++){
        cb.push(i);}}

void consumer(Cicular_buffer<int>& cb){
    for(size_t i=0; i<20; i++){
        int val = cb.pop();
        Log("Values removed: ", val);}}
// int main(){
//     Cicular_buffer<int>cb1(5);
//     std::thread t1(producer, std::ref(cb1));
//     std::thread t2(consumer, std::ref(cb1));

//     t1.join();
//     t2.join();
//     return 0;}


/////////////////// THREAD POOL ///////////////////////

class Thread_pool{
    public:
    Thread_pool(size_t num_threads = std::thread::hardware_concurrency()){
        // to create your worker threads
        for(size_t i=0; i<num_threads; i++){
            workers_threads.push_back(std::thread{[this]{worker();}});}}

    void enqueue(std::function<void()> task){
        //push the task
        {
            std::unique_lock<std::mutex> uql(q_mutex);
            tasks_queue.push(std::move(task));
        }
        // and notify other workers
        cv.notify_one();}
    
    ~Thread_pool(){
        // lock the queue to update the flag
        {
            std::unique_lock<std::mutex> uql(q_mutex);
            stop = true;
        }
        // notify all threads
        cv.notify_all();
        // join all for completed tasks
        for(auto &thread :workers_threads){
            thread.join();}}
    
    private:
    std::vector<std::thread> workers_threads; std::queue<std::function<void()>> tasks_queue;
    std::mutex q_mutex; std::condition_variable cv;
    std::atomic<bool> stop = {false};
    void worker(){
        while(true){
            std::function<void()> task;{
                std::unique_lock<std::mutex> uql(q_mutex);
                cv.wait(uql, [this] ()
                {
                    return !tasks_queue.empty() || stop;
                });
                if(tasks_queue.empty() && stop) return;
                task = std::move(tasks_queue.front());
                tasks_queue.pop();
            }
            task();}}};

void dummy(size_t id){
    Log("Task", id, " is running on thread: ", std::this_thread::get_id());
    std::this_thread::sleep_for(std::chrono::milliseconds(200));}
int main(){
    Thread_pool pool(5);
    for(size_t i=0; i<5; i++)
    {
        pool.enqueue([i]{ dummy(i);});
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    return 0;}

/////////////// LRU CACHE /////////////////////////////

class LRU_Cache
{
    private:
    list<pair<int,int>>cache; // key, value
    unordered_map<int, list<pair<int, int>>::iterator> mp; // key and a pointer to the list 
                                                       // points to (1,10) inside list
    int capacity;
    public:
    LRU_Cache(int cap){capacity = cap;}
    int get(int key){
        if(mp.find(key) == mp.end()) return -1;
        // move accessed node to the front
        auto it  = mp[key];
        int value = it->second; // {key, value}
        cache.erase(it);
        cache.push_front({key,value});
        mp[key] = cache.begin();
        return value; }

    void put(int key, int val){
        // find if it is in the map and erase it 
        if(mp.find(key) != mp.end())  {
            cache.erase(mp[key]);}
        else if(cache.size() == capacity){
            // remove the least used 
            auto last_used = cache.back();
            mp.erase(last_used.first);
            cache.pop_back();}
        // insert the new val in the front
        cache.push_front({key,val});
        mp[key] = cache.begin();}};

int main(){
    LRU_Cache lru1(3);
    lru1.put(1,10);
    cout << lru1.get(1) << endl;
    lru1.put(2, 20);  
    lru1.put(3, 30);   
    cout << lru1.get(2) << endl;  
    cout << lru1.get(1) << endl;       
    return 0;}

//////////////////////// sample pipeline design ///////////////////////////////////
#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <memory>
#include <vector>

// ---------------- Frame ----------------
struct Frame {
    int id;
};

// ---------------- Thread-safe queue ----------------
template<typename T>
class BlockingQueue {
public:
    void push(T item) {
        {
            std::lock_guard<std::mutex> lock(mtx);
            q.push(std::move(item));
        }
        cv.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return !q.empty(); });

        T item = std::move(q.front());
        q.pop();
        return item;
    }

private:
    std::queue<T> q;
    std::mutex mtx;
    std::condition_variable cv;
};

// ---------------- Pipeline ----------------
class Pipeline {
public:
    Pipeline(int pool_size) {
        // Preallocate memory pool
        for (int i = 0; i < pool_size; i++) {
            free_pool.push(std::make_unique<Frame>());
        }
    }

    void producer() {
        for (int i = 0; i < 5; i++) {
            auto frame = free_pool.pop();   // get empty buffer

            frame->id = i;
            std::cout << "Produced: " << frame->id << "\n";

            ready_queue.push(std::move(frame));  // send to consumer
        }
    }

    void consumer() {
        for (int i = 0; i < 5; i++) {
            auto frame = ready_queue.pop();  // get filled frame

            std::cout << "Consumed: " << frame->id << "\n";

            free_pool.push(std::move(frame));  // return buffer
        }
    }

private:
    BlockingQueue<std::unique_ptr<Frame>> free_pool;
    BlockingQueue<std::unique_ptr<Frame>> ready_queue;
};

// ---------------- Main ----------------
int main() {
    Pipeline p(3);

    std::thread t1(&Pipeline::producer, &p);
    std::thread t2(&Pipeline::consumer, &p);

    t1.join();
    t2.join();

    return 0;
}