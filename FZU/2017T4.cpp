#include <bits/stdc++.h>
using namespace std;

/*  动态规划：
 *	令 dp[i][j] 表示上端接线柱 i 与下端接线柱 j 之间的最大不相交子集数
 *
 * 	1. 若 i 与 j 之间无连线则 i 与 j 前的最大子集为 i-1 与 j 前或 i 与 j-1前得最大子集数
 * 	即： dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
 * 	2. 若 i 与 j 相连则 i 与 j 前得最大子集数为 i-1 与 j-1 前得最大子集数加 1
 * 	即： dp[i][j] = dp[i-1][j-1] + 1;
 */

int dp[100][100];

int maxUnintersection(int pi[], int n)
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(j == pi[i-1])								// i j 相连
				dp[i][j] = dp[i-1][j-1] + 1;
			else											// i j 不相连
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	return dp[n][n];
}


int main()
{
	int pi[10] = {8, 7, 4, 2, 5, 1, 9, 3, 10, 6};
	cout << maxUnintersection(pi, 10) << endl;
	for(int i = 0; i <= 10;i++)
	{
		for(int j = 0; j <= 10;j++)
		{
			cout << dp[i][j] << "  ";
		}
		cout << endl;
	}
}