/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */
#include "Include_all.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};    // 方向数组
    // 广度优先搜索
    int bfs(vector<vector<int>> &grid,int x,int y)
    {
        grid[x][y] = 0;
        int aera = 0;
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> que; // 遍历队列
        que.push(make_pair(x,y));
        while(!que.empty())
        {
            int curx = que.front().first, cury = que.front().second;
            que.pop();
            aera ++;
            for(int i = 0; i < 4; ++i )
            {
                int nx = curx + dir[i][0], ny = cury + dir[i][1];
                if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]!=0)
                {
                    que.push(make_pair(nx,ny));
                    grid[nx][ny] = 0;
                }
            }
        }
        return aera;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(grid[i][j] != 0)
                {
                    ans = max(bfs(grid,i,j), ans);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

