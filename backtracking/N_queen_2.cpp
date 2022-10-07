#include<iostream>
#include<set>
using namespace std;

/* number of queens that can be placed in a row
    Restrictions : A queen can travel in any possible directions including right, left, up. down, diagnols
    So, the queen in the next row should'nt be placed anywhere in contact with the prev or next row queens.

    CLASSIC BACKTRACKING APPROACH
*/

class Solution
{
    private:
    int size;
    public:
    int totalNQueens(int n)
    {
        size = n;
        set<int> diag;
        set<int> antidiag;
        set<int> col;
        // backtrack(row, diag, antidiag, col)
        return backtrack(0, diag, antidiag, col);
    }
    int backtrack(int row, set<int>& diagnols, set<int>& antiDiagnols, set<int>& cols)
    {
        if(row == size) return 1;
        int result = 0;
        // iterate through the row
        for(int col = 0; col < size; col++)
        {
            int curr_diag = row - col;
            int curr_anti_diag = row + col;
            // if the queen cannot be placed anywhere
            if(cols.find(col) != cols.end() || 
                diagnols.find(curr_diag) != diagnols.end() || 
                antiDiagnols.find(curr_anti_diag) != antiDiagnols.end()) continue;
            // "ADD" the queen to the board
            cols.insert(col);
            diagnols.insert(curr_diag);
            antiDiagnols.insert(curr_anti_diag);
            // move on to the next rows
            result += backtrack(row+1, diagnols, antiDiagnols, cols);
            // "Remove" the queen from the board since we have already
            // explored all valid paths using the above function call
            cols.erase(col);
            diagnols.erase(curr_diag);
            antiDiagnols.erase(curr_anti_diag);

        }
        return result;
    }

};

// TC: O(N!) where N is the number of queens (which is the same as the width and height of the board).
// SC: O(N) where N is the number of queens (which is the same as the width and height of the board).



int main()
{
    return 0;
}