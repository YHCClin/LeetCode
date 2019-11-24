#include "Include_all.h"
using namespace std;

vector<int> gardenNoAdj(int N, vector<vector<int>>& paths)
{
	vector<vector<int>> Mgraph(N);
	//结果数组，下标表示花园编号-1
	vector<int> res(N,0);
	int n = paths.size();
	//建立邻接表
	for(int i = 0;i < n;++i)
	{
		if(paths[i][0] > paths[i][1])
			Mgraph[paths[i][0]-1].push_back(paths[i][1]-1);
		else
			Mgraph[paths[i][1]-1].push_back(paths[i][0]-1);
	}
	//开始着色
	for(int i = 0;i < N;++i)
	{
		vector<int> used_color;
		//编号为i+1的花园的邻接花园数组
		vector<int> adj_set = Mgraph[i];
		int color = 1;
		//存储邻接花园用过的颜色
		for(auto it : adj_set)
		{
			used_color.push_back(res[it]);
		}
		//选择一个没用过的颜色
		while(find(used_color.begin(),used_color.end(),color) != used_color.end())
		{
			++color;
		}
		res[i] = color;
	}
	return res;
}

int main()
{
	vector<vector<int>> paths = {{1,2},{2,3},{3,4},{4,1},{1,3},{2,4}};
	vector<int> res(gardenNoAdj(4,paths));
	for(auto i : res)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}