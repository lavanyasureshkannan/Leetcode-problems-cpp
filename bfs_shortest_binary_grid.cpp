#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Check if it is possible to go to (x, y) from the current position. The
// function returns false if the cell has value 0 or already visited
bool isTraversable(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j)
{
	return (i >= 0 && j < grid.size() && j >= 0 && j < grid[0].size()) &&
			grid[i][j] == 1 && !visited[i][j];
}

void findShortestPath(vector<vector<int>> &grid, vector<vector<bool>>& visited, int source_i, int source_j, int dest_i, int desti_j, int &min_dist, int dist)
{
	if (source_i == dest_i && source_j == desti_j)
    {
		min_dist = min(dist, min_dist);
		return;
	}

	visited[source_i][source_j] = true;
	// go to the bottom cell
	if (isTraversable(grid, visited, source_i + 1, source_j)) 
    {
		findShortestPath(grid, visited, source_i + 1, source_j, dest_i, desti_j, min_dist, dist + 1);
	}
    // right
    if (isTraversable(grid, visited, source_i , source_j + 1)) 
    {
		findShortestPath(grid, visited, source_i , source_j + 1, dest_i, desti_j, min_dist, dist + 1);
	}
    // top
    if (isTraversable(grid, visited, source_i - 1, source_j)) 
    {
		findShortestPath(grid, visited, source_i - 1, source_j, dest_i, desti_j, min_dist, dist + 1);
	}
    // left
    if (isTraversable(grid, visited, source_i , source_j - 1)) 
    {
		findShortestPath(grid, visited, source_i , source_j - 1, dest_i, desti_j, min_dist, dist + 1);
	}

	visited[source_i][source_j] = false;
}


int findDistance(vector<vector<int>> &grid, pair<int, int> &src, pair<int, int> &dest)
{
	if (grid.size() == 0 || grid[src.first][src.second] == 0 || grid[dest.first][dest.second] == 0)
    {
		return -1;
    }
	int row = grid.size();
	int col = grid[0].size();
	vector<vector<bool>> visited;
	visited.resize(row, vector<bool>(col));
	int dist = INT_MAX;
	findShortestPath(grid, visited, src.first, src.second, dest.first, dest.second, dist, 0);
	if (dist != INT_MAX)
		return dist;
	return -1;
}

int main()
{
	vector<vector<int>> grid =
	            {
                {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
				{1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
				{1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
				{0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
				{1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
				{1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
				{1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
				{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
				{1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
                };

	pair<int, int> src = make_pair(0, 0);
	pair<int, int> dest = make_pair(3, 4);
	int dist = findDistance(grid, src, dest);
	if (dist != -1)
		cout << "Shortest Path is " << dist;
	
	else
		cout << "Shortest Path doesn't exist";

	return 0;
}
