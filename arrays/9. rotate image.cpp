48. Rotate Image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // do transpose
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // revrse the matrix
        for(int i =0; i<n; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

//TC: O(M) transposing the matrix
// SC: O(1)
