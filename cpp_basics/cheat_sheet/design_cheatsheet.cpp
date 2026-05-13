#include <iostream>
#include <vector>
using namespace std;

class Allocator 
{
    private:
    vector<int> memory;
    int n;
    public:
    Allocator(int size) : n(size) {
        memory.resize(n, 0); // 0 = free
    }
    int allocate(int size) {
        for (int i = 0; i <= n - size; i++) {
            bool canAllocate = true;
            for (int j = 0; j < size; j++) {
                if (memory[i + j] != 0) {
                    canAllocate = false;
                    break;
                }
            }
            if (canAllocate) 
            {
                for (int j = 0; j < size; j++)
                memory[i + j] = 1; // mark allocated
                return i;
            }
        }
        return -1; // no space
    }

    void free(int start, int size) 
    {
        for (int i = start; i < start + size; i++)
            memory[i] = 0; // mark free
    }

    void printMemory() 
    {
        for (int i = 0; i < n; i++)
            cout << memory[i] << " ";
        cout << endl;
    }
};
int main() {
    Allocator alloc(10);
    int a = alloc.allocate(3); // allocate 3 units
    cout << "Allocated at: " << a << endl;
    alloc.printMemory();
    int b = alloc.allocate(4); // allocate 4 units
    cout << "Allocated at: " << b << endl;
    alloc.printMemory();
    alloc.free(a, 3); // free first block
    cout << "After freeing first block:" << endl;
    alloc.printMemory();
    return 0;
}


#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
class LRU_Cache 
{
    private:   
    size_t capacity;
    list<int> usage_order; // back = MRU, front = LRU
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    public:
    explicit LRU_Cache(size_t cap) : capacity(cap) {}
    void put(int key, int value) 
    {
        // Key already exists
        if (cache.find(key) != cache.end()) 
        {
            usage_order.erase(cache[key].second); // remove old position
        } 
        // Cache is full
        else if (cache.size() == capacity) 
        {
            int lru_key = usage_order.front(); // least recently used key
            usage_order.pop_front();
            cache.erase(lru_key);
        }

        usage_order.push_back(key); // insert at end -> most recently used
        cache[key] = {value, --usage_order.end()};
    }

    int get(int key) 
    {
        if (cache.find(key) == cache.end())
            return -1;

        // Move this key to the back (most recently used)
        usage_order.erase(cache[key].second);
        usage_order.push_back(key);
        cache[key].second = --usage_order.end();

        return cache[key].first;
    }

    void display() 
    {
        cout << "Cache state (LRU -> MRU): ";
        for (auto k : usage_order)
            cout << k << " ";
        cout << endl;
    }
};

int main() {
    LRU_Cache lru(3);
    lru.put(1, 100);
    lru.put(2, 200);
    lru.put(3, 300);
    lru.display(); // 1 2 3
    lru.get(2); // 2 becomes most recently used
    lru.display(); // 1 3 2
    lru.put(4, 400); // evicts key 1
    lru.display(); // 3 2 4
    cout << "Get key 3: " << lru.get(3) << endl; // returns 300
    lru.display(); // 2 4 3

    return 0;
}


enum processor_type
{
    BLUR,
    SHARPEN
};
class Image
{
    private:
    int height;
    int width;
    int* data;

    public:
    Image(int m_height, int m_width)
    {
        height = m_height;
        width = m_width;
    }
};


class Image_processor
{
    public:
    virtual void perform_image_processing(const Image& image) = 0;
    virtual ~Image_processor()
    {
        cout << "Image processor is destroyed" << endl;
    };
};

class Blur : public Image_processor
{
    public:
    void perform_image_processing(const Image& image)
    {
        cout << "Blur processor is created" << endl;
    }  
};

class sharpen : public Image_processor
{
    public:
    void perform_image_processing(const Image& image)
    {
        cout << "Sharpen processor is created" << endl;
    }
};

class Image_Processor_Factory
{
    public:
    // static unique_ptr<Image_processor> Image_processing_ptr(const string& name_processor)
    // {
    //     if(name_processor == "BLUR") return make_unique<Blur>();
    //     else if(name_processor == "sharpen") return make_unique<sharpen>();
    //     else return nullptr; 
    // }

    static unique_ptr<Image_processor> Image_Processor_ptr(processor_type process)
    {
        switch(process)
        {
            case processor_type::BLUR:
            {
                return make_unique<Blur>();
            }
            case processor_type::SHARPEN:
            {
                return make_unique<sharpen>();
            }
            default:
                return nullptr;
        }
        
    }
};

int main()
{
    int h = 10;
    int w = 20;
    Image image_1(h,w);
    //unique_ptr<Image_processor> process_image = Image_Processor_Factory::Image_processing_ptr("BLUR");
    //process_image->perform_image_processing(image_1);

    unique_ptr<Image_processor> process_1_image = Image_Processor_Factory::Image_Processor_ptr(processor_type::BLUR);
    process_1_image->perform_image_processing(image_1);
    
    unique_ptr<Image_processor> process_2_image = Image_Processor_Factory::Image_Processor_ptr(processor_type::SHARPEN);
    process_2_image->perform_image_processing(image_1);
    
    return 0;
}