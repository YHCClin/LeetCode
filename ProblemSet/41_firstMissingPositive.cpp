#include "Include_all.h"
using namespace std;

//首先遍历一次数组把大于等于1和小于数组长度的数放到对应下标位置，再遍历一次数组判断数组对应下标位置的值是否与下边相等，若不等，则该下标为结果

//写一个交换函数
void swap(int &a,int &b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}
void swap_res(vector<int> &nums)
{
	int n = nums.size();
	int i;
	for(i = 0;i < n;)
	{
		if(nums[i] != i && nums[i]>=1 && nums[i]<n)
		{
			swap(nums[i],nums[nums[i]]);
		}
		else
			++i;
	}
}
int firstMissingPositive(vector<int>& nums)
{
	int n = nums.size(),i;
	if(n == 0) return 1;
	if(n == 1) return 1;
	for(i = 0;i < n;)
	{
		if(nums[i] != i && nums[i]>=1 && nums[i]<n)
		{
			swap(nums[i],nums[nums[i]]);
		}
		else
			++i;
	}
	for(i = 1;i<n;++i)
	{
		if(nums[i] != i)
			return i;
	}
	return i;
}

int main()
{
	vector<int> v{1};
	swap_res(v);
	for(auto i : v)
		cout << i << endl;
	cout << "ans:" <<firstMissingPositive(v) << endl;
	return 0;
}