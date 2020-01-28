#include <iostream>
#include <vector>
using namespace std;

/*  算法思想：
 *    直接暴力
 *    1. 若碰到一个服务器则看其同行或同列是否有另一个服务器，有的话该服务器就满足条件    
 */
class real_Solution {
public:
  int dx[4] = {0,0,1,-1};
  int dy[4] = {1,-1,0,0};

  int countServers(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    for(int i = 0;i < m;i++)
    {
      for(int j = 0;j < n;j++)
      {
        if(grid[i][j] == 1)
        {
          int falg = false;
          for(int i = 0;i < 4;i++)
          {
            int nx = i + dx[i];
            int ny = j + dy[i];
            if(grid[nx][ny] == 1)
            {
              ans ++;
              break;
            }
          } 
        }
      }
    }
    return ans;
  }
};

















// 哈哈哈看错题目写了十几分钟。。
class Solution {
public:
    // 方向数组
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    // 广度优先遍历
    void BFS(int &N ,int x, int y, vector<vector<int>> &grid)
    {
        queue<pair<int,int>> que;
        que.push(make_pair(x,y));
        grid[x][y] = 0;
        while(!que.empty())
        {
            int cur_x = que.front().first;
            int cur_y = que.front().second;
            N++;
            que.pop();
            for(int i = 0;i < 4;i++)
            {
                int nx = cur_x + dx[i];
                int ny = cur_y + dy[i];
                if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny]==1)
                {
                    que.push(make_pair(nx,ny));
                    grid[nx][ny] = 0;
                }
            }
        }
    }
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                int N = 0;
                if(grid[i][j] == 1)
                    BFS(N,i,j,grid);
                if(N > 1)
                    ans += N;
            }
        }
        return ans;

    }
};
