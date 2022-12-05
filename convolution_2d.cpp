#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;



void display(vector<vector<int>> convolution_2d)
{
    for(int i=0; i<convolution_2d.size(); i++)
    {
        for(int j=0; j<convolution_2d[0].size(); j++)
        {
            cout << convolution_2d[i][j] << " ";
        }
    }
}


// without PADDING
vector<vector<int>> convolution_2d(vector<vector<int>>& image, vector<vector<int>>& kernel)
{
    int x_image = image.size();
    int y_image = image[0].size();

    int x_kernel = kernel.size();
    int y_kernel = kernel[0].size();

    int x_output = x_image - x_kernel + 1;
    int y_output = y_image - y_kernel + 1;

    vector<vector<int>> result(x_output, vector<int> (y_output,0));

    for(int i =0; i < x_output; i++)
    {
        for(int j = 0; j < y_output; j++)
        {
            for(int k_x = 0; k_x < x_kernel; k_x++)
            {
                for(int k_y = 0; k_y < y_kernel; k_y++)
                {
                    // increase the tc by skipping 0 multiplication
                    if(image[ i + k_x][ j + k_y] == 0 || kernel[k_x][k_y] == 0)
                        continue;
                    result[i][j] += image[i + k_x][j + k_y] * kernel[k_x][k_y]; 
                }
            }
        }
    }
    display(result);
    return result;
};


// with padding
vector<vector<int>> padding_image(vector<vector<int>>& image, int x, int y)
{
    // padding in top, bottom , left and right
    int x_padded = image.size() + (2 * x);
    int y_padded = image[0].size() + (2 * y);

    vector<vector<int>> result(x_padded, (vector<int> (y_padded,0)));
    for(int i = x; i < (x + image.size()); i++)
    {
        for(int j = y; j < (y + image[0].size()); j++)
        {
            result[i][j] = image[i-x][j-y];
        }
    }
    return result;
}





int main()
{
    vector<vector<int>> img = {{1,2,3,4,5,6},
                                {6,5,4,3,2,1},
                                {1,2,3,4,5,6},
                                {6,5,4,3,2,1},
                                {1,2,3,4,5,6}};

    vector<vector<int>> kernel = {{1,1,1},{1,1,1},{1,1,1}};
    convolution_2d(img, kernel);
    return 0;
}