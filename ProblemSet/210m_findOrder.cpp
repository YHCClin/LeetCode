#include "Include_all.h"
using namespace std;

vector<int> findOrder(int N, vector<vector<int>> &prerequisites)
{
	unordered_map<int,int> indegree;
	for(int i = 0;i < N;i++) indegree[i] = 0;
	vector<vector<int>> Mgraph(N);
	for(auto i : prerequisites)
	{
		indegree[i[0]]++;
		Mgraph[i[1]].push_back(i[0]);
	}
	stack<int> sta;
	//度为0的节点入栈
	for(auto i : indegree)
	{
		if(i.second == 0)
			sta.push(i.first);
	}
	vector<int> res;
	int top = 0;
	while(!sta.empty())
	{
		int course = sta.top();
		top++;
		res.push_back(course);
		sta.pop();
		for(auto j : Mgraph[course])
		{
			indegree[j]--;
			if(indegree[j]==0)
				sta.push(j);
		}
	}
	if(top == N)
		return res;
	res.clear();
	return res;
}

int main()
{
	int N = 4;
	vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
	vector<int> res(findOrder(N,prerequisites));
	for(auto i : res)
		cout << i << " ";
	cout << endl;
	return 0;
}