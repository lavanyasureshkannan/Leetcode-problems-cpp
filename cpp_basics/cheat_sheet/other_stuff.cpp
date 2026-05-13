#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
string my_itoa(int num) {
    if (num == 0) return "0";
    bool isNegative = false;
    if (num < 0) {
        isNegative = true;
        num = -num;
    }
    string result;
    while (num > 0) {
        int digit = num % 10;
        result.push_back('0' + digit); // convert digit → char
        num /= 10;
    }
    if (isNegative) result.push_back('-');
    reverse(result.begin(), result.end());
    return result;
}


int calculate(string s){
    // check if the string is empty or not
        int size = s.size();
        if(size == 0) return 0;
        
        // initialize the variables
        stack<int> stack;
        int curr_num = 0;
        char operation = '+';
        
        // iterate through the string
        for(int i=0; i< size; i++){
            char curr_char = s[i];
            // convert the string to int
            if(isdigit(curr_char)) {
                curr_num = (curr_num * 10) + (curr_char - '0');
            }
            // check if the digit is not integer or white space
            if(!isdigit(curr_char) && !iswspace(curr_char) || i == size -1){
                if(operation == '-'){
                    stack.push(-curr_num);
                }
                else if(operation == '+'){
                    stack.push(curr_num);
                }
                else if(operation == '*'){
                    int stack_top = stack.top();
                    stack.pop();
                    stack. push (stack_top * curr_num);
                }
                else if (operation == '/'){
                    int stack_top = stack.top();
                    stack.pop();
                    stack.push (stack_top / curr_num);
                }
                curr_num = 0;
                operation = curr_char;
            }
        }
        // add all the elements in stack
        int result  = 0;
        while(stack.size() != 0){
            result = result + stack.top();
            stack.pop();
        }
        return result;
}

   bool helperFunction(vector<vector<char>>& board) // main function
    {
        // iterate through the 2d grid
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                // check if the curr cell value is '.'
                if (board[i][j] == '.')
                {       
                    // go ahead and try all the possible characters from '1' to '9' 
                    for (char c = '1'; c <= '9'; c++)
                    {
                        if (isValid(board, i, j, c))
                        {
                            // fill in the values
                            board[i][j] = c;
                            // if true we return as we only want atleast one correct way
                            if (helperFunction(board) == true) return true;
                            else
                            {
                                board[i][j] = '.'; // backtracking
                            }
                        }
                    }
                return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c)
    {    
        // iterate through the 2d grid and check for the validity
        for(int i = 0; i < 9; i++)
        {    
            // check the entire row
            if(board[row][i] == c) return false;
            // col check
            if(board[i][col] == c) return false; 
            // small 3x3 box
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
        }
        return true;
    }