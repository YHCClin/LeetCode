#include "Include_all.h"
using namespace std;

bool canFinish(int N, vector<vector<int>> &prerequisites)
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
	for(auto i : indegree)
	{
		if(i.second == 0)
			sta.push(i.first);
	}
	int top = 0;
	while(!sta.empty())
	{
		int course = sta.top();
		cout << course << endl;
		sta.pop();
		top++;
		for(auto j : Mgraph[course])
		{
			indegree[j]--;
			if(indegree[j]==0)
				sta.push(j);
		}
	}
	if(top==N)
		return true;
	return false;
}

int main()
{
	int N = 2;
	vector<vector<int>> prerequisites = {{1,0},{0,1}};
	cout << canFinish(N,prerequisites) << endl;
	return 0;
}