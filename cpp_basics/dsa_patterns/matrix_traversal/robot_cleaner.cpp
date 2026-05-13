#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Robot
{
    public:
    int row,col,dir;
    vector<vector<int>>room;
    vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    Robot(vector<vector<int>>& grid, int start_Row, int start_Col)
    {
        row = start_Row;
        col = start_Col;
        room = grid;
        dir = 0;
    }
    bool move()
    {
        int nr = row + directions[dir][0];
        int nc = col + directions[dir][1];
        if(nr < 0 || nc < 0 || nr >= room.size() || nc >= room[0].size() || room[nr][nc] == 0) return false;
        row = nr;
        col = nc;
        return true;
    }

    void turnLeft()
    {
        dir = (dir + 3) % 4;
    }
    void turnRight()
    {
        dir = (dir + 1) % 4;
    }
    void clean()
    {
        room[row][col] = 2;
        cout << "cleaned" << endl;
    }
};

class CleanRobot
{
    public:
    // directions
    vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    // visited
    set<pair<int,int>> visited;

    void goback(Robot& robot)
    {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

    void dfs(int r, int c, int dir, Robot& robot)
    {
        visited.insert({r,c});
        robot.clean();
        
        for(int i=0; i<4; i++)
        {
            int new_dir = (dir + i) % 4;
            int nr = r + directions[new_dir][0];
            int nc = c + directions[new_dir][1];
            
            if(!visited.count({nr,nc}) && robot.move())
            {
                dfs(nr,nc,new_dir,robot);
                goback(robot);
            }
            robot.turnRight();
        }
    }


    void cleanRoom(Robot& robot)
    {
        dfs(0,0,0, robot);
    }
};


int main()
{
    vector<vector<int>> room = {{1, 1, 1, 1},{1, 0, 1, 0},{1, 1, 1, 1}};
    Robot robot(room,1,0);
    CleanRobot cleanrob;
    cleanrob.cleanRoom(robot);
    return 0;
}