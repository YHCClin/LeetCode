#include <iostream>
#include <vector>
using namespace std;

//递归法：（1）第一次爬一级剩余n-1级。（2）第一次爬两级剩余n-2级。
int climbStairs(int n)
{
	if(n==1) return 1;
	if(n==2) return 2;
	return climbStairs(n-1)+climbStairs(n-2);
}

//动态规划：
int dp_climbstairs(int n)
{
	if(n==1) return 1;
	if(n==2) return 2;

	std::vector<int> dp;
	dp.push_back(1);
	dp.push_back(2);
	for(int i = 2;i < n;i++)
	{
		dp.push_back(dp[i-1]+dp[i-2]);
	}
	return dp[n-1];
}

//更低空间复杂度(直接递推斐波那契数列)：
int low_space_climb(int n)
{
	if(n==1) return 1;
	if(n==2) return 2;

	int a=1,b=2;
	int c;
	int temp;
	for(int i = 2;i < n;++i)
	{
		c = a + b;
		temp = a;
		a = b;
		b = c;
	}
	return c;
}

int main()
{
	cout << "Rec:" << climbStairs(4) << endl;
	cout << "Dp:" << dp_climbstairs(4) << endl;
	cout << "Dp_lowSpace:" << low_space_climb(4) << endl;
	return 0;
}