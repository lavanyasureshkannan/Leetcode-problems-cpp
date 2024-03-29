class MinStack {
public:
    
    stack<int> st;
    stack<int> min_vals;
    
    MinStack() {}
    
    void push(int val) 
    {
        st.push(val);
        if(min_vals.empty() || val<=min_vals.top())
        {
            min_vals.push(val);
        }
    }
    
    void pop() 
    {
        if(st.top() == min_vals.top())
        {
            min_vals.pop();
        }
        st.pop();    
    }
    
    int top() 
    {
        return st.top();    
    }
    
    int getMin() 
    {
        return min_vals.top();    
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */