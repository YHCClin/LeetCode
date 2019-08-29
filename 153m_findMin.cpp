#include "Include_all.h"
using namespace std;

//常规方法
int findMin_v1(vector<int>& nums)
{
	int min = nums[0];
	int pre = nums[0];
	for(auto i : nums)
	{
		if(i < pre)
			return i;
		pre = i;
	}
	return min;
}
//二分搜索
int findMin(vector<int>& nums)
{
	int beg = 0,end = nums.size()-1;
	int mid = 0;
	while(beg < end)
	{
		mid = (beg + end)/2;
		if(nums[mid] > nums[end])
		{
			beg = mid;
		}
		else
		{
			end = mid;
		}
		if(abs(beg-end)<=1)
			return min(nums[beg],nums[end]);

	}
	return nums[mid];
}
int main()
{
	vector<int> nums = {3,4,5,1,2};
	cout << findMin(nums) << endl;
	return 0;
}