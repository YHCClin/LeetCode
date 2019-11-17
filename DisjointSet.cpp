#include <bits/stdc++.h>
#define VERTS 6
using namespace std;

int get_root(int x,vector<int>& parent)
{
	int x_root = x;
	while(parent[x_root] != -1)
	{
		x_root = parent[x_root];
	}
	return x_root;
}

int union_verts(int x, int y,vector<int>& parent,vector<int>& rank)
{
	int x_root = get_root(x,parent);
	int y_root = get_root(y,parent);
	if(x_root != y_root)
	{
		if(rank[x_root] > rank[y_root])
		{
			parent[y_root] = x_root;
		}
		else if(rank[x_root] < rank[y_root])
		{
			parent[x_root] = y_root;
		}
		else
		{
			parent[x_root] = y_root;
			rank[y_root]++;
		}
		return 1;
	}
	return 0;
}

int main()
{
	vector<int> parent(VERTS,-1);
	vector<int> rank(VERTS,0);
	vector<vector<int>> edges = {{0,1},{1,2},{1,3},
								{5,4},{3,4},{2,5}};
	for(int i = 0;i < 6;i++)
	{
		int x = edges[i][0];
		int y = edges[i][1];
		if(union_verts(x,y,parent,rank) == 0)
		{
			cout << "Cycle detected !" << endl;
			return 0;
		}
	}
	cout << " No Cycle detected !" << endl;
	return 0;
}