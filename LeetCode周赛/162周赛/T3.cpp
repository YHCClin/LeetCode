#include "Include_all.h"
using namespace std;

/*  将延伸至矩阵边缘的陆地全变成水，再计算岛屿个数就可以了
	当然，也可以直接在DFS计算岛屿数量的过程中判断当前岛屿
	是否有延伸到边缘，有的话就不计数，这里我为了方便直接改的
	之前的代码哈哈哈。
*/

class Solution {
public:
    void DFS(vector<vector<int>>& grid,vector<vector<int>>& mark,int x,int y)
    {
        if(grid[x][y]==1)
            return;
        mark[x][y]=1;
        static const int dx[] = {-1,0,1,0};
        static const int dy[] = {0,1,0,-1};
        for(int i=0;i<4;++i)
        {
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(newx>=0&&newx<grid.size()&&newy>=0&&newy<grid[0].size()&&mark[newx][newy]==0)
            {
                DFS(grid,mark,newx,newy);
            }
        }
    }
    int numIslands(vector<vector<int>>& grid,vector<vector<int>> mark) {
        int numOflands=0;
        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]==0 && mark[i][j]==0)
                {
                    DFS(grid,mark,i,j);
                    numOflands++;
                }
            }
        return numOflands;
    }
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<int>> mark;
        for(int i=0;i<grid.size();++i)
        {
            vector<int> dim(grid[0].size(),0);
            mark.push_back(dim);
        }
        int allIslands = numIslands(grid,mark);
        int edgeIslands = 0;
        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]==0 && mark[i][j]==0)
                {
                    if(i==0 || j==0 || i == grid.size()-1 || j == grid[0].size()-1)
                    {
                        DFS(grid,mark,i,j);
                        edgeIslands++;
                    }
                }
            }
        return allIslands - edgeIslands;
    }
};