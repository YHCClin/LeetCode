#include "Include_all.h"
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums)
{
	vector<vector<int>> res;
	vector<int> ans;
	int n = nums.size();
	if(n == 0 || n < 3) return res;
	sort(nums.begin(), nums.end());

	for(int i = 0;i < n;i++)
	{
		if(nums[i]>0) break;
		if(i > 0 && nums[i] == nums[i-1]) continue;
		int L = i + 1;
		int R = n - 1;
		while(L < R)
		{
			int sum = nums[i] + nums[L] + nums[R];
			if(sum == 0)
			{
				ans = {nums[i],nums[L],nums[R]};
				res.push_back(ans);
				while(L<R && nums[L] == nums[L+1]) L++;
				while(L<R && nums[R] == nums[R-1]) R--;
				L++;
				R--;
			}
			else if(sum < 0) L++;
			else if(sum > 0) R--;
		}
	}
	return res;
}

int main()
{
	vector<int> nums = {-2,3,43,-3,6,1,3,0,4};
	vector<vector<int> > res(threeSum(nums));
	for(auto i : res)
	{
		for(int j = 0;j < i.size();j++)
		{
			cout << i[j] << " ";
		}
		cout << endl;
	}
	return 0;
}