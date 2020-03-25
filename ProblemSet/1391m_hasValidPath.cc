#include "Include_all.h"
using namespace std;

/**
 * 检查网格中是否存在有效路径:
    1 表示连接左单元格和右单元格的街道。
    2 表示连接上单元格和下单元格的街道。
    3 表示连接左单元格和下单元格的街道。
    4 表示连接右单元格和下单元格的街道。
    5 表示连接左单元格和上单元格的街道。
    6 表示连接右单元格和上单元格的街道。
 */
class Solution {
    int m,n,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};//0下、1右、2上、3左
    int pipe[7][4]={{-1,-1,-1,-1},{-1,1,-1,3},{0,-1,2,-1},{-1,0,3,-1},{-1,-1,1,0},{3,2,-1,-1},{1,-1,-1,2}};
    //记录各个拼图块路径的方向，0、1、2、3代表方向，-1代表不可走。
    bool dfs(int x,int y,int dir,vector<vector<int>>& grid){//(x,y,当前方向,地图)
        if(x==m-1&&y==n-1) return 1;//到达终点
        int xx=x+dx[dir];
        int yy=y+dy[dir];//得到下一个准备走的坐标
        if(xx<0||yy<0||xx>=m||yy>=n)return 0;//越界
        int nxt=grid[xx][yy];//得到下一块拼图的编号
        if(pipe[nxt][dir]!=-1)return dfs(xx,yy,pipe[nxt][dir],grid);//如果当前方向可走，则方向改变，继续走。
        return 0;//无法走，返回0
    }
    public:
    bool hasValidPath(vector<vector<int>>& grid) {    
        m=grid.size();
        n=grid[0].size();
        int sta=grid[0][0];//起点的拼图编号
        for(int i=0;i<4;++i)//朝着四个方向都试一下
            if(pipe[sta][i]!=-1)//当前方向可以走
                if(dfs(0,0,pipe[sta][i],grid))//沿着当前方向搜索
                    return 1;//拼图都有两个方向可以走，只要沿着一个初始方向走通就可以。
        return 0;
    }
};

int main() {
    vector<vector<int>> grid = {{2,4,3},{6,5,2}};
    Solution *s = new Solution();
    cout << s->hasValidPath(grid) << endl;
}