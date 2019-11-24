#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//这里要注意的是，每一个状态dp[i]都是当前数组的最大连续子序列和的值，
//而不是当前数组的所有值能组成的最大和。这一点决定了状态转移方程。
int maxSubArray(vector<int>& nums)
{
	if(nums.size()==0) return 0;

	int n = nums.size();
	int dp[n];
	dp[0] = nums[0];
	for(int i = 1;i < n;++i)
	{
		//状态转移方程
		dp[i] = max(dp[i-1]+nums[i],nums[i]);
	}
	//找到最大连续子序列和
	int ans=dp[0];
	for(auto k : dp)
	{
		if(k > ans)
			ans = k;
	}
	return ans;
}

int main()
{
	std::vector<int> v{-2,1,-3,4,-1,2,1,-5,4};
	cout << maxSubArray(v) << endl;
	return 0;
}