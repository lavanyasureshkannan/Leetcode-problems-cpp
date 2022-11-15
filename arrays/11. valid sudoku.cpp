36. Valid Sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) { 
        //vector of sets; elements can be inserted by pushback 
        vector<set<int>> rows(9);
        vector<set<int>>  cols(9);
        vector<set<int>>  boxes(9);
        
    
        for(int i =0; i< board.size(); i++){
            for(int j =0; j< board.size(); j++){
                if(board[i][j] == '.'){
                    continue;
                }
                int curr_element = board[i][j];
                int idx = (i / 3) *3 + j/3;
                if(rows[i].count(curr_element) || cols[j].count(curr_element) || boxes[idx].count(curr_element)){
                    return false;
                    
                }
                        
    
                else{
                    rows[i].insert(curr_element);
                    cols[j].insert(curr_element);
                    boxes[idx].insert(curr_element);
                    }
                     
                        
                
            }
        }
        return true;
        
        
    }
};


//TC: O(N^2) // 2 for loop trverse every position
//SC: O(N^2) // inserting and checking
