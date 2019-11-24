#include "Include_all.h"
#include <cstring>
#include <functional>
using namespace std;

// 从所有叶子节点为起点广度优先遍历树得到树的最大高度
// 本解法超时
int treeDiameter_(vector<vector<int>>& edges)
{
	int node_num = edges.size() + 1;
	int Mgraph[node_num][node_num];
	for(int i = 0; i < node_num;i++)
	{
		for(int j = 0; j < node_num;j++)
			Mgraph[i][j] = 0;
	}
	for(auto i : edges){ Mgraph[i[0]][i[1]] = 1; Mgraph[i[1]][i[0]] = 1;}
	stack<int> zero_degree;
	for(int i = 0;i < node_num;i++)
	{
		int degree = 0;
		for(int j = 0; j < node_num; j++)
			if(Mgraph[i][j] == 1) degree++;
		if(degree == 1) zero_degree.push(i);
	}
	
	queue<int> que;
	bool visited[node_num];
	int max_diameter = 0;
	while(!zero_degree.empty())
	{
		memset(visited,false,sizeof(visited));
		int cur = zero_degree.top();
		visited[cur] = true;
		zero_degree.pop();
		que.push(cur);
		int diameter = -1;
		while(!que.empty())
		{
			diameter++;
			int size = que.size();
			//cout << size << endl;
			while(size--)
			{
				int cur_v = que.front();
				//cout << cur_v << " ";
				que.pop();
				for(int i = 0;i < node_num;i++)
				{

					if(Mgraph[cur_v][i] && !visited[i])
					{
						que.push(i);
						visited[i] = true;
					}
				}
			}
		}
		//cout << endl;
		if(max_diameter < diameter) max_diameter = diameter;
		//cout << cur << " - " << diameter << endl;
	}
	
	return max_diameter;
}
// dfs
// 一般来说求树的直径的题目都是先从任意一个节点开始遍历到最远处并记录该最远节点
// 第二次遍历从该最远节点开始，遍历到最远得到的步数就是树的直径了
// 
int treeDiameter(vector<vector<int>>& edges) {
        vector<vector<int>> graph(edges.size() + 1);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        int ans = 0;
        int index = 0;
        function<void (int, int, int sum)> dfs = [&](const int& start, const int& end, const int& sum) { // C++11 的新特性 functional 头文件中，功能类似于函数指针
            for (int i = 0; i < graph[start].size(); i++) {
                if (graph[start].at(i) == end) {
                    continue;
                }
                dfs(graph[start].at(i), start, sum + 1);
            }
            if (sum > ans) {
                ans = sum;
                index = start;
            }
        };

        dfs(0, -1, 0);	// 第一次遍历的到最远节点index
        dfs(index, -1, 0); // 第二次遍历从index开始得到结果

        return ans;
    }
int main()
{
	vector<vector<int>> edges = {{0,1},{1,2},{2,3},{1,4},{4,5}};
	cout << treeDiameter(edges) << endl;

	return 0;
}