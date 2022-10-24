#include<iostream>
#include<vector>
using namespace std;

/*
    no of diagnols => {{     1       } ->0
                        {    2,4     } -> 1
                        {    3,5,7   } -> 2
                        {    6,8       } ->3
                        {       9    }} ->4
    [
    00  01   02
    1    2   3
    10   11  12
    4    5   6
    20   21  22
    7    8   9]
    
(ans : 124753689)

    i+j = 0+0 = 0
            0+1 = 1 (put the element 01 in 1)
            0+2 = 2......
    after that reverse the vector which is in even digit
*/



class Solution 
{
    public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) 
    {
        
		int m = matrix.size();
		int n = matrix[0].size();

        
		vector<vector<int>> diagnol(m+n-1); // find the diagnols
		vector<int> v;

        if(m == 0 || n == 0) return v;
    
		for(int i=0; i<m; i++)
        {
			for(int j=0; j<n; j++)
            {
				diagnol[i+j].push_back(matrix[i][j]); 
			}
		}
		for(int i=0; i<diagnol.size(); i++)
        {
			if(i%2 == 0)
			{
				reverse(diagnol[i].begin(), diagnol[i].end());
            }
            for(int j=0; j<diagnol[i].size(); j++)
			{
            	v.push_back(diagnol[i][j]);
		
            }
        }
		return v;
	}
};


//TC: O(N)
// SC: O(1)