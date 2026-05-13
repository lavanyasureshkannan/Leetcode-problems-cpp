#include <iostream>
#include <queue>
#include <vector>
using namespace std;


// CIRCULAR BUFFER: Circular buffer using queue 
template<typename T>
class Circular_Buffer
{
    private:
    size_t capacity;
    queue<T> q;

    public:
    explicit Circular_Buffer(size_t cap)
    {
        capacity = cap;
    }

    bool isFull() { return (q.size() == capacity); }
    bool isEmpty() { return (q.empty()); }
    size_t q_size() { return q.size(); }

    void Enqueue(const T& x)
    {
        if(isFull())
        {
            q.pop();
            cout << "Overwriting the oldest" << endl;
        }
        q.push(x);
        cout << "ELement pushed: " << x << endl;
    }

    T getFront()
    {
        if(isEmpty())
        {
            cout << "Q is empty no front element" << endl;
            return T{};
        }
        T front_element = q.front();
        cout << "Current front element: " << front_element << endl;
        return front_element;
    }

    T Dequeue()
    {
        if(isEmpty())
        {
            cout << "NO element to be removed" << endl;
            return T{};
        }
        T front_element = q.front();
        q.pop();
        cout << "Element removed: " << front_element << endl;
        return front_element;
    }

    T getrear()
    {
        if(isEmpty())
        {
            cout << "NO element to be removed" << endl;
            return T{};
        }
        T last_element = q.back();
        cout << "current last element is: " << last_element << endl;
        return last_element;
    }
};


// CIRCULAR_BUFFER using vector

template<typename T>
class Circular_buffer_vector
{
    private:
    size_t capacity;
    vector<T> buffer;

    public:
    explicit Circular_buffer_vector(size_t cap)
    {
        capacity = cap;
        buffer.reserve(capacity);
    };

    bool isFull() const {return buffer.size() == capacity;}
    bool isEmpty() const {return buffer.empty();}
    size_t size()  const { return buffer.size(); }

    void add_elements(const T& x) 
    {
        if(isFull())
        {
            cout << "Buffer is full cannot add more elements" << endl;
            buffer.erase(buffer.begin());
        }
        buffer.push_back(x);
        cout << "Element pushed: " << x << endl;
    }

    T get_front_element()
    {
        if(isEmpty())
        {
            cout << "Buffer is empty. No element found";
            return T{};
        }
        return buffer.front();
    }

    T get_rear_element()
    {
        if(isEmpty())
        {
            cout << "Buffer is empty. No element found";
            return T{};
        }
        return buffer.back();
    }

    T remove_elements_From_front()
    {
        if(isEmpty())
        {
            cout << "Buffer is empty. No element found";
            return T{};
        }
        T front_element = buffer.front();
        buffer.erase(buffer.begin());
        return front_element;
    }
};

int main()
{
    Circular_buffer_vector<int> cbv(3);
    cbv.add_elements(10);
    cbv.add_elements(20);
    cbv.add_elements(30);
    cbv.add_elements(40);
    cout << cbv.get_front_element() << endl;
    cout << cbv.get_rear_element() << endl;
    

}

// int main()
// {
//     Circular_Buffer<int>cb(3);
//     cb.Enqueue(10);
//     cb.Enqueue(20);
//     cb.Enqueue(30);
//     while(!cb.isEmpty())
//     {
//         cb.Dequeue();
//     }
//     cb.Enqueue(40);
//     cb.Enqueue(50);
//     cb.Enqueue(60);
//     cb.Dequeue();
//     cb.getrear();
//     cb.getFront();
//     return 0;
// }