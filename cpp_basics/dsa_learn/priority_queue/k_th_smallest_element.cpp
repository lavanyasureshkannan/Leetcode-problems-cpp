#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], 
and the 8th smallest number is 13
*/

int k_th_smallest_element(vector<vector<int>>& mat, int k)
{
    vector<int> elements;
    for(int i=0; i<mat.size(); i++)
    {
        for(int j=0; j<mat[i].size(); j++)
        {
            elements.push_back(mat[i][j]);
        }
    }
    sort(elements.begin(), elements.end());
    int result = 0;
    for(int i=0; i<k; i++)
    {
        result = elements[k-1];
    }
    return result;
}

int k_th_smallest_element_pq(vector<vector<int>>& mat, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<mat.size(); i++)
    {
        for(int j=0; j<mat[i].size(); j++)
        {
            pq.push(mat[i][j]);
        }
    }
    for(int i=1; i<k; i++)
    {
        pq.pop();
    }
    int result = pq.top();
    return result;
}


int main()
{
    vector<vector<int>> mat = {{1,5,9},{10,11,13},{12,13,15}};
    int k = 8;
    cout << k_th_smallest_element(mat, k) << endl;
    cout << k_th_smallest_element_pq(mat,k) << endl;
    return 0;
}