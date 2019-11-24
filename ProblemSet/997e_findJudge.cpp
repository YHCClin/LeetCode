#include "Include_all.h"
using namespace std;

int findJudge(int N, vector<vector<int>>& trust)
{
	int n = trust.size();
	unordered_map<int,int> indegree,outdegree;
	for(int i = 0;i < n;++i)
	{
		indegree[trust[i][1]]++;
		outdegree[trust[i][0]]++;
	}
	for(int i = 1;i <= N;++i)
	{
		if(outdegree[i]==0 && indegree[i]==N-1)
			return i;
	}
	return -1;
}

int main()
{
	vector<vector<int>> trust = {{1,2},{2,3}};
	cout << findJudge(4,trust) << endl;
	return 0;
}