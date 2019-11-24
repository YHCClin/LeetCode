#include "Include_all.h"
using namespace std;

class BPM { // 二分图的最大奇数匹配
	int n, m, G[maxn][maxn]; // 左右顶点个数，G[x][y] == 1,表示存在边 x - y
	int left[maxn]; // left[i] 为右边第i个顶点的匹配顶点编号
	bool T[maxn]; // T[i] = true 表示第i个顶点已经被标记

	void init( int n, int m) { this->n = n; this->m = m; _zero(G);}
	bool match(int u)
	{
		for(int v = 0; v < m ; v++)
		{
			if(G[u][v] && !T[v])
			{
				T[v] = true;
				if(left[v] == -1 || match(left[v])) // 若 v 未匹配就将它与u匹配，否则通过v的匹配点继续找未匹配点
				{
					left[v] = u;
					return true;
				}
			}
		}
		return false;
	}

	int solve() // 求最大匹配
	{
		memset(left, -1, sizeof(left));
		int ans = 0;
		for(int u = 0; u < n; u++) // 遍历左边顶点寻找增广路
		{
			_zero(T);
			if(match(u)) ans++; // 找到一条增广路
		}
		return ans;
	}
}