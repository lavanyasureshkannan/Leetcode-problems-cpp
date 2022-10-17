#include<iostream>
#include<vector>

void display(std::vector<std::vector<int>> mat)
{
    for(int i=0; i<mat.size(); i++)
    {
        for(int j=0; j<mat[0].size(); j++)
        {
            std::cout << mat[i][j] << " ";
        } 
    }
}

std::vector<std::vector<int>> multiply(std::vector<std::vector<int>>& m1, std::vector<std::vector<int>>& m2)
{
    int m1_row = m1.size();
    int m1_col = m1[0].size();
    int m2_col = m2[0].size();
    std::vector<std::vector<int>> result(m1_row, std::vector<int>(m2_col,0));
    for(int i=0; i<m1_row; i++)
    {
        for(int j=0; j<m1_col; j++)
        {
            // check if the curr element is zero or not
            if(m1[i][j] != 0)
            {
                // if not then iterate over the col
                for(int k=0; k<m2_col; k++)
                {
                    result[i][k] += m1[i][j] * m2[j][k];
                }
            }
        }
    }
    display(result);
    return result;
}

// TC: O(m1_row, m1_col, m2_col)
// SC: O(1)
////////////////////////////////////////////////////////////////////////////////////////////////

/*  
    Approach 2:Compress the matrix and then multiply 
    1. create a compression funtion for the for the matrix and find the non zero values of each matrix
    2. then iterate through that matrix and perform the multiplication function
*/ 


class Solution 
{
    public:
    std::vector<std::vector<std::pair<int, int>>> compressMatrix(std::vector<std::vector<int>>& matrix) 
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        std::vector<std::vector<std::pair<int, int>>> compressedMatrix(rows);
        
        for (int row = 0; row < rows; ++row) 
        {
            for (int col = 0; col < cols; ++col) 
            {
                if (matrix[row][col] != 0) 
                {
                    compressedMatrix[row].push_back({matrix[row][col], col}); 
                }
            }
        }
        return compressedMatrix;
    }
    
    std::vector<std::vector<int>> multiply(std::vector<std::vector<int>>& mat1, std::vector<std::vector<int>>& mat2) 
    {
        int m = mat1.size();
        int k = mat1[0].size();
        int n = mat2[0].size();
        
        // Store the non-zero values of each matrix.
        std::vector<std::vector<std::pair<int, int>>> A = compressMatrix(mat1);
        std::vector<std::vector<std::pair<int, int>>> B = compressMatrix(mat2);
        
        std::vector<std::vector<int>> ans(m, std::vector<int>(n, 0));
        
        for (int mat1Row = 0; mat1Row < m; ++mat1Row) 
        {
            // Iterate on all current 'row' non-zero elements of mat1.
            for (auto [element1, mat1Col] : A[mat1Row]) 
            {

                // Multiply and add all non-zero elements of mat2
                // where the row is equal to col of current element of mat1.
                for (auto [element2, mat2Col] : B[mat1Col]) 
                {
                    ans[mat1Row][mat2Col] += element1 * element2;
                }
            }
        }
        
        return ans;
    }
};

// TC: O(m. k. n)
// SC: O(m⋅k+k⋅n)


int main()
{
    std::vector<std::vector<int>> mat1 = {{1,0,0},{-1,0,3}};
    std::vector<std::vector<int>> mat2 = {{7,0,0},{0,0,0},{0,0,1}};
    multiply(mat1, mat2);
    
    return 0;
}