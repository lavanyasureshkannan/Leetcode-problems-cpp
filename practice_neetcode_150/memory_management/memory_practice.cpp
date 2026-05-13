#include <iostream>
#include <memory>
#include <thread>
#include <vector>
using namespace std;


/*
    1. RULE 5 violation because destructor defined w/o copy constructor 
    => compiler generates shallow copy if two sensor buffers points to same data
    2. Dangling pointer issue
    3. no move semantics. 

*/
// class SensorBuffer 
// {
//     public:
//     SensorBuffer(size_t size) 
//     {
//         // data_ = new uint8_t[size];
//         unique_ptr<uint8_t[]> data_ = make_unique<uint8_t[]>(size);
//         size_ = size;
//     }

//     void resize(size_t new_size) 
//     {
//         // delete[] data_;
//         // data_ = new uint8_t[new_size];
//         // size_ = new_size; 
//         unique_ptr<uint8_t[]> new_data = make_unique<uint8_t[]>(new_size);
//         data_ = move(new_data);
//         size = new_size;  
//     }
//     uint8_t* data() { return data_; }

//     private:
//     unique_ptr<uint8_t[]> data_;
//     size_t size_;
//     // no copy constructor
//     // no copy assignment
//     // no move constructor
//     // no move assignment
// };

/*
    when you try to access the variable after move the object is basically invalid.
*/
// std::vector<std::string> sensor_names;

// void register_sensor(std::string name) 
// {
//     std::cout << "Registered: " << name << std::endl;
//     sensor_names.push_back(std::move(name));
//     // log the name after move
// }

// int main() 
// {
//     register_sensor("camera_front");
//     register_sensor("radar_rear");
// }

/*
    Bug: exception safety failure. 
*/
// class Pipeline 
// {
//     unique_ptr<Sensor> sensor_;
//     unique_ptr<Processor> processor_;
    
//     public:
//     Pipeline() 
//     {
//         sensor_ = make_unique<Sensor>();        // allocated
//         processor_ = make_unique<Processor>(); // throws here!
//     }  

// };

/*
    self-referential shared_ptr. 
    Node holds a shared_ptr to itself. Ref count = 2 (main's node + self_).
*/

// class Node 
// {
//     public:
//     void set_self(std::shared_ptr<Node> self) 
//     {
//         self_ = self;   // node holds shared_ptr to itself
//     }
//     private:
//     std::weak_ptr<Node> self_;
// };

// int main() 
// {
//     auto node = std::make_shared<Node>();
//     node->set_self(node);   // ref count = 2
//     // node goes out of scope
//     // ref count 2 -> 1 — never reaches 0
//     // LEAK
// }

/*

*/

// std::vector<int> frames = {1, 2, 3, 4, 5};

// void process() 
// {
//     // for (auto it = frames.begin(); it != frames.end(); ++it) 
//     // {
//     //     if (*it % 2 == 0) 
//     //     {
//     //         frames.erase(it);   // modifies vector during iteration
//     //     }
//     // }
//     auto it = frames.begin();
//     while(it != frames.end())
//     {
//         if(*it % 2 == 0)
//         {
//             it = frames.erase(it);
//         }
//         else
//         {
//             it ++;
//         }
//     }
// }
//

// void load_calibration(const std::string& path) 
// {
//     FILE* f = fopen(path.c_str(), "rb");
//     if (!f) throw std::runtime_error("cannot open file");

//     unique_ptr<CalibData*> data = new CalibData();
    
//     size_t read = fread(data, sizeof(CalibData), 1, f);
//     if (read != 1) {
//         fclose(f);
//         throw std::runtime_error("read failed");  // data leaked!
//     }
    
//     apply_calibration(data);   // may also throw
    
//     fclose(f);
// }


// std::vector<uint8_t> processed;
// processed.reserve(MAX_FRAME_SIZE)

// std::vector<Detection> detections;
// detections.reserve(MAX_DETECTIONS)

// void perception_loop(const RawFrame& raw) 
// {
//     processed.resize(raw);
//     // convert raw to processed
//     std::memcpy(processed.data(), raw.data(), raw.size());
    
//     // run detection
//     run_yolo(processed, detections);
    
//     // copy results for publishing
//     publish(detections);
// }

// class CameraFrame 
// {
//     public:
//     CameraFrame(size_t size) : size_(size) 
//     {
//         data_ =  make_unique<uint8_t[]>(size);
//     }
//     // move constructor defined
//     CameraFrame(CameraFrame&& o) noexcept
//         : data_(o.data_), size_(o.size_) {
//         o.data_ = nullptr;
//     }
//     // no copy constructor defined
//     CameraFrame& operator= (CameraFrame&& o) noexcept
//     {
//         if(this != &o)
//         {
//             //free current
//             delete [] data_;
//         }
//     }
//     // no copy assignment defined
//     // no move assignment defined

// private:
//     //uint8_t* data_;
//     unique_ptr<uint8_t[]> data_;
//     size_t size_;
// };

// std::vector<CameraFrame> frame_buffer;
// frame_buffer.push_back(CameraFrame(1024));
// frame_buffer.push_back(CameraFrame(2048)); // vector may resize


struct Processor 
{
    void process(const Frame& f) 
    { /* heavy work */ }
};

std::shared_ptr<Processor> g_proc =std::make_shared<Processor>();

// void worker_thread() 
// {
//     // take a local copy of the shared_ptr
//     Processor* raw = g_proc.get();   // raw pointer 
    
//     // g_proc may be reset from another thread here
    
//     raw->process(current_frame);     // use-after-free if reset
// }


// void worker_thread() {
//     // take shared_ptr copy — increments ref count
//     std::shared_ptr<Processor> local = g_proc;
//     // even if g_proc.reset() called now:
//     // local still holds a ref count — object stays alive
    
//     local->process(current_frame);  // safe
// }
// void update_processor() {
//     g_proc.reset(new Processor());   // replaces the processor
// }


// class SensorPipeline 
// {
//     //std::vector<uint8_t*> frame_buffers_;
//     vector<unique_ptr<uint8_t []>> frame_buffers;
//     size_t frame_size_;
//     thread worker_;
//     atomic<bool> running_ {true};

// public:
//     SensorPipeline(size_t frame_size, int num_buffers)
//         : frame_size_(frame_size) 
//         {
//             for (int i = 0; i < num_buffers; i++)
//             {
//             //frame_buffers_.push_back(new uint8_t[frame_size]);
//             frame_buffers.push_back(make_unique<uint8_t []>(frame_size));
//             worker_ = jthread([this]{ process_loop(); });
//             }
//         }

//     // ~SensorPipeline() {
//     //     running_ = false;
//     //     worker_.join();
//     //     // frame_buffers_ not freed
//     // }

//     void process_loop() 
//     {
//         while (running_) 
//         {
//             for (auto& buf : frame_buffers_) 
//             {
//                 process_frame(buf.get(), frame_size_);
//             }
//         }
//     }
// };


// #include <iostream>
// #include <queue>
// #include <thread>
// #include <mutex>
// #include <condition_variable>

// struct Frame 
// {
//     int id;
// };

// class FramePool 
// {
//     public:
//     FramePool(int size) 
//     {
//         for (int i = 0; i < size; i++) 
//         {
//             pool.push(make_unique<Frame>());
//         }
//     }

//     unique_ptr<Frame> acquire() 
//     {
//         std::unique_lock<std::mutex> lock(mtx);
//         // if (pool.empty()) 
//         // {
//             // no predicate
//             cv.wait(lock, [this] () {
//                 return !pool.empty();
//             });
//         // }

//         auto f = move(pool.front());
//         pool.pop();
//         return f;
//     }

//     void release(unique_ptr<Frame> f) 
//     {
//         {
//             std::lock_guard<std::mutex> lock(mtx);
//             pool.push(move(f));
//         }
//         cv.notify_one();
//     }

// private:
//     //std::queue<Frame*> pool;
//     queue<unique_ptr<Frame>> pool;
//     std::mutex mtx;
//     std::condition_variable cv;
// };

// FramePool pool(2);

// void producer() 
// {
//     for (int i = 0; i < 5; i++) 
//     {
//         unique_ptr<Frame> f = pool.acquire();
//         f->id = i;
//         std::cout << "Produced: " << f->id << "\n";
//         std::this_thread::sleep_for(std::chrono::milliseconds(100));
//         pool.release(move(f));
//     }
// }

// void consumer() 
// {
//     for (int i = 0; i < 5; i++) 
//     {
//         unique_ptr<Frame> f = pool.acquire();
//         std::cout << "Consumed: " << f->id << "\n";
//         std::this_thread::sleep_for(std::chrono::milliseconds(150));
//         pool.release(move(f));
//     }
// }



// int main()
// {
//     return 0;
// }


// #include <iostream>
// #include <thread>
// #include <queue>
// #include <mutex>
// #include <condition_variable>
// #include <memory>
// #include <functional>

// class SensorPipeline 
// {
//     public:
//     SensorPipeline(size_t buffer_size) 
//     {
//         //buffer_ = new uint8_t[buffer_size];   // line 1
//         buffer_ = make_unique<uint8_t[]>(buffer_size);
//         worker_ = jthread([this] {
//             process_loop();
//         });
//     }

//     // ~SensorPipeline() {
//     //     stop_ = true;                          // line 2
//     //     worker_.join();
//     //     // buffer_ never freed               // line 3
//     // }

//     void push_frame(std::shared_ptr<Frame>& frame) 
//     {
//         {
//             std::lock_guard<std::mutex> lock(mtx_);
//             frame_queue_.push(move(frame));
//         }
//         cv_.notify_one();
//     }

//     void register_callback(std::function<void(Frame)> cb) 
//     {
//         {
//             std::lock_guard<std::mutex> lock(mtx_);
//             callback_ = cb;
//         }
//         process_pending();                     // line 4
//     }

// private:
//     //uint8_t* buffer_;
//     unique_ptr<uint8_t []> buffer_;
//     atomic<bool> stop_ = false;                        // line 6
//     std::jthread worker_;
//     std::queue<std::shared_ptr<Frame>> frame_queue_;
//     std::mutex mtx_;
//     std::condition_variable cv_;
//     std::function<void(Frame)> callback_;

//     void process_loop() 
//     {
//         while (!stop_) 
//         {
//             {
//                 std::unique_lock<std::mutex> lock(mtx_);
//                 cv_.wait(lock, [this] {
//                 return !frame_queue_.empty() || stop_;
//                 });
//                 if (stop_) return;
//                 auto frame = move(frame_queue_.front());
//                 frame_queue_.pop();
//                 if (callback_) callback_(*frame);  // called under lock
//             }
//         }
//     }

//     void process_pending() 
//     {
//         // called from register_callback which holds mtx_
//         std::lock_guard<std::mutex> lock(mtx_); // line 4 detail
//         while (!frame_queue_.empty()) 
//         {
//             auto f = move(frame_queue_.front());
//             frame_queue_.pop();
//             if (callback_) callback_(*f);
//         }
//     }
// };

// class SensorPipeline : public std::enable_shared_from_this<SensorPipeline> 
// {
//     // Line 2: use shared_from_this() not shared_ptr(this)
//     std::shared_ptr<SensorPipeline> get_self() 
//     {
//         return shared_from_this();
//     }   
// }

// #include <iostream>
// #include <thread>
// #include <queue>
// #include <mutex>
// #include <condition_variable>
// #include <memory>

// struct Task 
// {
//     int data;
// };

// class TaskQueue 
// {
//     public:
//     void push(std::unique_ptr<Task> t) 
//     {
//         {
//             std::lock_guard<std::mutex> lock(mtx);
//             q.push(std::move(t));
//         }
//         cv.notify_one();
//     }

//     std::unique_ptr<Task> pop() 
//     {
//         std::unique_lock<std::mutex> lock(mtx);

//         // if (q.empty()) 
//         // {
//         //     cv.wait(lock);   // ❌ BUG 1
//         // }
//         cv.wait(lock,[this] ()
//         {
//             return !q.empty();
//         });
        
//         auto t = std::move(q.front());
//         q.pop();
//         return t;
//     }

// private:
//     std::queue<std::unique_ptr<Task>> q;
//     std::mutex mtx;
//     std::condition_variable cv;
// };

// TaskQueue tq;

// void worker() 
// {
//     while (true) 
//     {
//         auto task = tq.pop();
//         if(!task) break;
//         std::cout << "Processing: " << task->data << "\n"; // ❌ BUG 2?
//     }
// }

// void producer() {
//     for (int i = 0; i < 5; i++) {
//         auto t = std::make_unique<Task>();
//         t->data = i;

//         tq.push(std::move(t));
//     }
// }

// int main() {
//     std::thread t1(worker);
//     std::thread t2(producer);
//     // producer();

//     t1.join();   // ❌ BUG 3?
//     t2.join();
// }


// #include <iostream>
// #include <thread>
// #include <queue>
// #include <mutex>
// #include <condition_variable>
// #include <memory>
// #include <atomic>
// #include <vector>
// #include <functional>

// class PerceptionPipeline 
// {
//     public:
//     PerceptionPipeline(size_t num_workers, size_t frame_size)
//         : frame_size_(frame_size)
//     {
//         // allocate shared processing buffer
//         //shared_buffer_ = new float[frame_size];        // bug 1
//         shared_buffer_ = make_unique<float []> (frame_size); 
//         // start worker threads
//         for (size_t i = 0; i < num_workers; i++) 
//         {
//             workers_.push_back(
//                 std::jthread(&PerceptionPipeline::worker_loop, this)
//             );
//         }
//     }

//     // ~PerceptionPipeline() {
//     //     stop_ = true;                                  // bug 2
//     //     cv_.notify_all();
//     //     for (auto& t : workers_) t.join();
//     // }

//     void submit_frame(std::vector<float> frame) 
//     {
//         {
//             std::lock_guard<std::mutex> lock(mtx_);
//             frame_queue_.push(move(frame));                      // bug 3
//         }
//         cv_.notify_one();
//     }

//     void set_callback(std::function<void(Result)> cb) 
//     {
//         lock_guard<mutex> lock(mutex);
//         callback_ = cb;                                // bug 4
//     }

//     Result get_latest_result() 
//     {
//         lock_guard<mutex> lock(mutex);
//         return latest_result_;                         // bug 5
//     }

// private:
//     //float* shared_buffer_;
//     unique_ptr<float []> shared_buffer_;
//     std::atomic<bool> stop_{false};
//     size_t frame_size_;
//     mutex result_mtx;

//     std::vector<std::thread> workers_;
//     std::queue<std::vector<float>> frame_queue_;
//     std::mutex mtx_;
//     std::condition_variable cv_;

//     std::function<void(Result)> callback_;             // bug 4 detail
//     Result latest_result_;                             // bug 5 detail

//     void worker_loop() 
//     {
//         vector<float> local_buffer;
//         while (true) 
//         {
//             std::vector<float> frame(frame_size_);
//             {
//                 std::unique_lock<std::mutex> lock(mtx_);
//                 cv_.wait(lock, [this] {
//                     return !frame_queue_.empty() || stop_;
//                 });
//                 if (stop_) return;
//                 frame = move(frame_queue_.front());          // bug 6
//                 frame_queue_.pop();
//             }
//             // process frame using shared buffer
//             memcpy(local_buffer, frame.data(),
//                    frame_size_ * sizeof(float));       // bug 7
//             Result r = run_detection(local_buffer.data());
//             {
//                 unique_lock<mutex> lock(result_mtx);
//                 latest_result_ = r;
//             }
//             if (callback_) callback_(r);
//         }
//     }
// };

