/*
 * @lc app=leetcode.cn id=1162 lang=cpp
 *
 * [1162] 地图分析
 */

// @lc code=start
// 单源BFS， 超时
class Solution_ {
public:
    // 广度优先遍历
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    struct Point {
        int step;
        int x,y;
        Point(int X,int Y,int D) : x(X), y(Y), step(D) {}
    };
    
    int nx = 0, ny = 0;
    int BFS(vector<vector<int>>& grid,int x,int y, vector<vector<bool>> &vis) {
        int n = grid.size();
        queue<Point> que;
        que.push(Point(x,y,0));
        vis[x][y] = true;
        while(!que.empty()) {
            int sz = que.size();
            for(int i = 0;i < sz;++i) {
                int cx = que.front().x, cy = que.front().y;
                if(grid[cx][cy] == 1) return que.front().step;
                for(int j = 0;j < 4;++j) {
                    nx = cx + dx[j], ny = cy + dy[j];
                    if(nx<0 || ny<0 || nx>=n || ny>=n || vis[nx][ny]==true) continue;
                    else{
                        que.push(Point(nx,ny,que.front().step+1));
                        vis[nx][ny] = true;
                    }
                }
                que.pop();
            }
        }
        return -1;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0 || n == 1) return -1;
        int ans = 0;
        int flag = grid[0][0], f = 0;
        for(int i = 0;i < n;++i)
            for(int j = 0;j < n;++j)
                if(flag != grid[i][j]) f = 1;
        if(f == 0) return -1;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        for(int i = 0;i < n;++i) {
            for(int j = 0;j < n;++j) {
                if(grid[i][j]==0){
                    vis = vector<vector<bool>>(n,vector<bool>(n,false));
                    ans = max(BFS(grid,i,j,vis),ans);
                }
            }
        }
        return f ? ans : -1;
    }
};
class Solution {
public:
    static constexpr int MAX_N = 100 + 5;
    static constexpr int INF = int(1E6);
    static constexpr int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    int n;
    int d[MAX_N][MAX_N];

    struct Coordinate {
        int x, y;
    };

    queue <Coordinate> q;

    int maxDistance(vector<vector<int>>& grid) {
        this->n = grid.size();
        auto &a = grid;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = INF;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j]) {
                    d[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto f = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = f.x + dx[i], ny = f.y + dy[i];
                if (!(nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= n - 1)) continue;
                if (d[nx][ny] > d[f.x][f.y] + 1) {
                    d[nx][ny] = d[f.x][f.y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        int ans = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!a[i][j]) ans = max(ans, d[i][j]);
            }
        }

        return (ans == INF) ? -1 : ans;
    }
};

// @lc code=end

