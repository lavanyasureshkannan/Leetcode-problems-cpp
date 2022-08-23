
class Solution{
    public:
    bool isValid(string s){
        int size = s.size();        
        stack<char> stack;
        
        for(int i = 0; i < size; i++){
            char curr = s[i];
            if (curr == '('){
                stack.push(')');
            }
            else if (curr == '['){
                stack.push(']');
            }
            else if (curr == '{'){
                stack.push('}');
            }
            else if (!stack.empty() && curr == stack.top()){
                stack.pop();
            }
            else{
                return false;
            }
        }
        return stack.empty();
        
    }
};

// TC: O(N)->because we simply traverse the given string one character at a time and push and pop operations on a stack take O(1) time.
// SC: O(N)-> stack