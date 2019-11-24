#include "Include_all.h"
using namespace std;
int threeSumClosest(vector<int>& nums,int target)
{
	int res = nums[0]+nums[1]+nums[2] ,n = nums.size();
	int sum = 0;
	sort(nums.begin(),nums.end());
	for(int i = 0;i < n;++i)
	{
		int start = i+1,end = n-1;
		while(start < end)
		{
			sum = nums[i]+nums[start]+nums[end];
			//gap = abs(sum - target);
			if(abs(target - sum) < abs(target - ans))
				res = sum;
			if(sum == target)
			{
				return sum;
			}
			else if(sum < target)
			{
				start++;
			}
			else
				end--;
		}
	}
	return res;
}
int main()
{
	vector<int> nums = {-1,2,1,-4};
	cout << threeSumClosest(nums,2) << endl;
	return 0;
}