#include <bits/stdc++.h>
using namespace std;

// 方向数组
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

vector<vector<char>> graph = {
					{'.','*','.','*','.','*','.','.','.','.','.','.','.','.','.','.','.','*','.','.'},
					{'.','.','.','.','a','*','*','.','.','*','.','.','.','.','.','*','.','*','.','.'},
					{'.','.','.','*','*','*','.','*','.','.','.','.','.','.','.','.','.','*','.','.'},
					{'.','*','*','.','.','.','.','.','.','*','.','*','.','*','*','*','.','*','.','.'},
					{'.','.','.','.','.','*','.','.','.','*','.','*','.','.','.','.','.','*','.','.'},
					{'.','*','.','*','.','.','.','*','.','.','.','*','.','*','.','.','.','*','.','.'},
					{'.','*','.','.','.','*','.','*','*','.','.','*','.','*','.','.','.','*','.','.'},
					{'.','*','.','*','.','.','.','.','*','.','*','*','.','*','.','.','.','.','.','.'},
					{'.','*','.','.','.','*','.','*','.','.','.','*','.','.','.','.','*','*','*','.'},
					{'.','.','.','.','.','.','.','*','.','.','.','.','.','*','.','.','*','*','*','b'},
				};
queue<pair<int,int>> que;
int res = INT_MAX;
void DFS(vector<vector<char>> graph, int x ,int y, int len)
{
	if(graph[x][y] == 'b') {res = len < res ? len : res;}
	else if(graph[x][y] != '*')
	{
		// 标记已访问
		graph[x][y] = '#';
	}
	int temp = len;
	for(int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if(nx>=0 && nx<10 && ny>=0 && ny<20 && graph[nx][ny]!='*' && graph[nx][ny]!='#')
		{
			DFS(graph,nx,ny,len+1);
		}
		//回溯还原
		graph[nx][ny] = '.';
		len = temp;
	}
}
int BFS(vector<vector<char>> &graph, int x,int y)
{
	int res = 1;
	que.push(make_pair(x,y));
	while(!que.empty())
	{
		int size = que.size();
		res++;
		while(size)
		{
			int x_ = que.front().first, y_ = que.front().second;
			que.pop();
			for(int i = 0; i < 4;i++)
			{
				int nx = x_ + dx[i], ny = y_ + dy[i];
				if(nx>=0 && nx<10 && ny>=0 && ny<20 && graph[nx][ny]!='*' && graph[nx][ny]!='#')
				{
					if(graph[nx][ny] == 'b') {cout << "Found it" << endl; return res;};
					que.push(make_pair(nx,ny));
					graph[nx][ny] = '#';
				}
			}
			size--;
		}
	}
	cout << "Unexisit A Possible Path." << endl;
	return -1;
}
int main()
{
	cout << BFS(graph,1,4) << endl;
	//DFS(graph,1,4,0);
	//cout << res << endl;
	for(auto i : graph)
	{
		for(auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}