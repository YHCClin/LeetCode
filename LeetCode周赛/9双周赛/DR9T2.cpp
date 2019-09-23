#include "Include_all.h"
using namespace std;

/* 5073 进击的骑士 */

int minKnightMoves(int x, int y)
{
	//定义方向数组
	int dx[8] = {1,2,2,1,-1,-2,-2,-1};
	int dy[8] = {-2,-1,1,2,2,1,-1,-2};
	//定义棋盘，dist[i][j]表示跳到（i，j）点的步数
	int dist[400][400];
	queue<pair<int,int> > que;

	//规划为第一象限讨论
	if(x < 0) x = -x;
	if(y < 0) y = -y;
	//初始化棋盘
	memset(dist, -1, sizeof(dist));
	while(!que.empty()) que.pop();
	//定义（10，10）为相对原点
	dist[10][10] = 0;que.push(make_pair(10,10));

	while(!que.empty())
	{
		int x = que.front().first; int y = que.front().second;
		que.pop();

		//遍历可及的八个临近点
		for(int k = 0; k < 8; ++k)
		{
			int nx = x + dx[k], ny = y + dy[k];
			//若超出棋盘范围，啥都不做
			if(nx < 0 || ny < 0 || nx > 350 || ny > 350) continue;

			if(dist[nx][ny] == -1) //该点还未遍历到
			{
				dist[nx][ny] = dist[x][y]+1;//是从(x,y)点跳到的
				que.push(make_pair(nx,ny));
			}
		}
	}
	/*
	for(int m = 0;m < 400;m++)
	{
		for(int n = 0;n < 400;n++)
			cout << dist[m][n] << " ";
		cout << endl;
	}
	*/
	return dist[x + 10][y + 10];
}

int main()
{
	cout << minKnightMoves(5,5) << endl;
	return 0;
}