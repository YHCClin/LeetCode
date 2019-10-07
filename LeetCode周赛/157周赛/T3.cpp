#include "Include_all.h"
using namespace std;

// 数据范围很小，可以暴力dfs

class Solution {
public:
	// 方向数组
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};
    int ans = 0; // 结果
    int gold[20][20] = {0};

    void dfs(int x,int y,int cur)
    {
        int rev = gold[x][y];
        gold[x][y] = 0;
        cur += rev;
        ans = max(ans,cur);
        // dfs 搜索四个方向
        for(int i = 0;i < 4;i++)
        {
            if(x+dx[i]>=0 && x+dx[i]<20 && y+dy[i]>=0 && y+dy[i]<20 && gold[x+dx[i]][y+dy[i]]>0)
                dfs(x+dx[i],y+dy[i],cur);
        }
        // 回溯还原
        gold[x][y] = rev;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                gold[i][j] = grid[i][j];
            }
        }
        // 尝试以每一个节点为起点
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(gold[i][j] > 0) dfs(i,j,0);
            }
        }
        return ans;
    }
};