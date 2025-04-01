#include <iostream>
#include <vector>
using namespace std;


class Matrix
{
    private:
    vector<vector<int>> data;
    int rows;
    int cols;

    public:
    Matrix(const vector<vector<int>>& input_data)
    {
        data = input_data;
        rows = data.size();
        cols = data[0].size();
    }
    Matrix multiply(const Matrix& other)
    {
        vector<vector<int>> result(rows, vector<int>(cols, 0));
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<other.cols; j++)
            {
                for(int k=0; k<cols; k++)
                {
                    result[i][j] += data[i][k] * other.data[k][j];
                }
            } 

        }
        return Matrix(result);
    }
    void display()
    {
        for(auto& row: data)
        {
            for(int elem : row)
            {
                cout << elem << " ";
            }
            cout << endl;
        }
    }
};


int main()
{
    Matrix matrix1({{1, 2}, {3, 4}});
    Matrix matrix2({{5, 6}, {7, 8}});
    Matrix result = matrix1.multiply(matrix2);
    result.display();
    return 0;
}