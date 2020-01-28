#include "Include_all.h"

/*
    动态规划：
        dp[i][j] 点(i,j) 与0的最短距离
        dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1],dp[i+1][j+1]) + 1;
        dp[i][j] = 1; if(near(i,j)) = 0;
 */
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    for(int i = 0;i < m;i++)
    {
        
    }
}

// 在遍历过程中记录结果（AC）
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue <pair<int,int>> q;
        int m = matrix.size();
        int n = matrix[0].size();
        vector <pair<int,int>> around = {{0,1},{0,-1},{-1,0},{1,0}}; //周围节点
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(matrix[i][j] == 0) q.push({i,j}); //将元素为0 的点推入队列
                else matrix[i][j] = INT_MAX;
            }
        }
        while(!q.empty())
        {
            pair <int,int> temp = q.front(); 
            q.pop();
            for(int b = 0; b < 4; ++ b) //探索周围节点
            {
                int y = temp.first + around[b].first;
                int x = temp.second + around[b].second;
                //判断在图内，且新点的元素大于该点元素。
                if(0 <= x && x < n && 0 <= y && y < m && matrix[temp.first][temp.second] < matrix[y][x])
                {
                    matrix[y][x] = matrix[temp.first][temp.second] + 1;
                    q.push({y,x});
                }
            }
        }
        return matrix;
    }
};


// 暴力bfs(超时)
class Solution {
public:
    // 方向数组
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    
    int findZero(int x, int y, vector<vector<int>>& matrix)
    {
        int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        queue<pair<int,int>> que;
        que.push(make_pair(x,y));
        while(!que.empty())
        {
            int size = que.size();
            ans++;
            while(size)
            {
                int cur_x = que.front().first;
                int cur_y = que.front().second;
                que.pop();
                for(int i = 0;i < 4;i++)
                {
                    int nx = cur_x + dx[i];
                    int ny = cur_y + dy[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && matrix[nx][ny] == 0) return ans;
                    if(nx>=0 && nx<n && ny>=0 && ny<m && matrix[nx][ny]!=0 && matrix[nx][ny]!=-1)
                    {
                        que.push(make_pair(nx,ny));
                        matrix[nx][ny] = -1;
                    }
                }
                size--;
            }
        }
        return ans;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> mx(matrix);
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(mx[i][j]!=0)
                {
                    mx[i][j] = findZero(i, j, matrix);
                }
            }
        }
        return mx;
    }
};

int main()
{
    vector<vector<int>> matrix = {{0,0,1},{0,1,1},{1,1,1}};
    vector<vector<int>> ans = updateMatrix(matrix);
    for(auto v : ans)
    {
        for(auto j : v)
            cout << j << "  ";
        cout << endl;
    }
}