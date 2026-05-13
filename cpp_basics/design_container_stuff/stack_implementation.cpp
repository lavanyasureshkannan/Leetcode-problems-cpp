#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


/*  
    stack -> Last In First Out
    push  => push the element to the container
    pop => remove the last element and return that
    peek => top element 
    size => current of the stack
    isempty => if the stack is empty or not

*/

// template<typename T>

// class Stack
// {
//     private:
//     vector<T> arr;// fixed array
//     size_t capacity;
    
//     public:
//     explicit Stack (size_t cap)
//     {
//         capacity = cap
//         arr.reserve(capacity);
//     }

//     bool isEmpty() {return (arr.empty());}
//     bool isFull() {return (arr.size() == capacity)}
//     size_t arr_size() {return arr.size();}

//     void push(const T& n)
//     {
//         // check if the stack is full
//         if(arr.size() >= capacity)
//         {
//             cout << "stack overflow. cannot add more elements" << endl;
//             return;
//         }
//         // if space available then push the element
//         arr.push_back(n);
//         cout << "value pushed: " << n << endl;
//     }

//     T peek()
//     {
//         // check if its empty
//         if(arr.empty()) 
//         {
//             cout << "stack is empty" << endl;
//         }
//         T top = arr.back();
//         cout << "top element: " << top << endl;
//         return top;
//     }

//     T pop()
//     {
//         if(arr.empty())
//         {
//             cout << "stack overflow. No element available to pop" << endl;
//         }
//         T top = arr.back();
//         arr.pop_back();
//         cout << "Popped element: " << top << endl;
//         return top;
//     }

// };

template<typename T>
class stack_st
{
    private:
    size_t capacity;
    stack<T> st;

    public:
    bool isFull() {return st.size() == capacity;}
    bool isEmpty() {return st.empty();}
    size_t size_stack() {return st.size();}

    explicit stack_st(size_t cap)
    {
        capacity = cap;
    }
    void push_back(const T& x)
    {
        if(isFull())
        {
            cout << "stack is full cannot push more elements" << endl;
            return;
        }
        cout << "Element pushed: " << x << endl;
        st.push(x);
    }

    void pop_back()
    {
        if(isEmpty())
        {
            cout << "Stack is empty. No elements to pop" << endl;
            return;
        }
        T pop_element = st.top();
        st.pop();
        cout << "Element popped: " << pop_element << endl;
    } 

    T top_element()
    {
        if(isEmpty())
        {
            cout << "Stack is empty. No elements to peek" << endl;
            return T {};
        }
        T pop_element = st.top();
        cout << "Peek element: " << pop_element << endl;
        return pop_element;
    }
};

int main()
{
    stack_st<int> st1(3);
    st1.push_back(10);
    st1.push_back(20);
    st1.push_back(30);

    cout << st1.size_stack() << endl;

    st1.pop_back();
    st1.top_element();
}

// int main()
// {
//     Stack<int>st(3);
//     st.push(10);
//     st.push(20);
//     st.push(30);
//     //st.push(40);
//     // st.pop();

//     // st.peek();

//     // st.size_st();

//     while(!st.isEmpty())
//     {
//         st.pop();
//     }

// }
