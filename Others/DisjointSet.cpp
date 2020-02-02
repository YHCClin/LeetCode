#include <bits/stdc++.h>
#define VERTS 6
using namespace std;

int get_root(int x,vector<int>& parent)
{
	int x_root = x;
	while(parent[x_root] != x_root)
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

bool quary(int x, int y, vector<int>& parent)
{
    int x_root = get_root(x, parent);
    int y_root = get_root(y, parent);
    if(x_root == y_root)
        return true;        // x 与 y 有联系
    return false;           // x 与 y 无联系
}

int main()
{
	vector<int> parent(VERTS);
	for(int i = 0;i < parent.size();i++) parent[i] = i;
	vector<int> rank(VERTS,0);
	vector<vector<int>> edges = {{0,1},{1,2},{1,3},
								{4,5}};
	for(int i = 0;i < 4;i++)
	{
		int x = edges[i][0];
		int y = edges[i][1];
		union_verts(x,y,parent,rank);
	}
	cout << "Boy 1 and Girl 5 will fall in love: " << (quary(1,5,parent) ? "Yes" : "No") << endl;
	cout << "Boy 2 and Girl 3 will fall in love: " << (quary(2,3,parent) ? "Yes" : "No") << endl;
	return 0;
}