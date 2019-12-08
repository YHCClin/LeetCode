#include "Include_all.h"
#include <string.h>
using namespace std;
#define maxn 0x7f7f

class BPM { 							 // 二分图的最大奇数匹配
public:
	int n, m, e;						 // 左右顶点个数, 边数
	vector<vector<bool>> G;	     		 // G[x][y] == 1,表示存在边 x - y
	int *left; 				  			 // left[i] 为右边（Y 集合）第i个顶点的匹配顶点编号
	bool *T;						 	 // T[i] = true 表示第i个顶点已经被标记已匹配

	BPM() 
	{
		cin >> n >> m >> e;
		T = new bool[maxn];
		left = new int[maxn];
		G = vector<vector<bool>>(maxn,vector<bool>(maxn,false));
		for(int i = 0; i < e; i++)
		{
			int t1, t2;
			cin >> t1 >> t2;
			G[t1][t2] = true;
		}
		memset(T, false, sizeof(T));
		memset(left, -1, sizeof(left));
	}

	bool match(int u)					 // 匈牙利算法
	{
		for(int v = 0; v < m ; v++)		 // 遍历右边 Y 集合中的顶点
		{
			if(G[u][v] && !T[v])
			{
				T[v] = true;
				if(left[v] == -1 || match(left[v]))	// left[v] != -1, left[v] 是 v 的匹配边
				{
					// 若 v 未匹配就将它与 u 匹配(相当于找到了一条增广路 u -> v)，否则通过 v 的匹配点继续找未匹配点
					left[v] = u;
					return true;
				}
			}
		}
		return false;
	}

	int solve() 							// 求最大匹配
	{
		int ans = 0;			            // 匹配数
		for(int u = 0; u < n; u++) 			// 遍历左边顶点寻找增广路
		{
			memset(T, false, sizeof(T));
			if(match(u))
			{
				cout << "--" << endl; 
				ans++; 			// 找到一条增广路
			}
		}
		return ans;
	}
};

int main()
{
	vector<vector<int>> G = {
		{0,0,0,0,1,0,1,0},
		{0,0,0,0,1,0,0,0},
		{0,0,0,0,1,1,0,0},
		{0,0,0,0,0,0,1,1},
		{1,1,1,0,0,0,0,0},
		{0,0,1,0,0,0,0,0},
		{1,0,0,1,0,0,0,0},
		{0,0,0,1,0,0,0,0},
	};
	BPM Solution();
	cout << Solution.solve() << endl;
}