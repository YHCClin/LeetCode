#include "Include_all.h"
using namespace std;

//向后冒泡,时间复杂度O(n^2)很慢,空间复杂度O(1)
void moveZeroes_(vector<int>& nums)
{
	int i,j,flag;
	int n = nums.size();
	for(i = n-1;i >= 0;--i)
	{
		flag = 0;
		for(j = 1;j <= i;++j)
		{
			if(nums[j-1]==0 && nums[j]!=0)
			{
				nums[j-1] = nums[j-1]^nums[j];
				nums[j] = nums[j-1]^nums[j];
				nums[j-1] = nums[j-1]^nums[j];

				flag = 1;
			}
		}
		if(flag == 0)
		{
			return;
		}
	}
}
//双指针法，将0位以非0位填充
void moveZeroes(vector<int>& nums)
{
	int i=0,j=0,temp;                    //i指向0，j指向非0,且i小于j
	int n = nums.size();
	while(i < n && j < n)
	{
		while(i < n && nums[i]!=0) i++;
		while(j < n && (nums[j]==0 || j < i)) j++;
		if(nums[i]==0 && nums[j]!=0 && (i < n && j < n))
		{
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
	}
}

int main()
{
	vector<int> nums{0,1,0,3,9,0,0,8,12,0};
	moveZeroes(nums);
	for(auto i : nums)
	{
		cout << i << "  ";
	}
	cout << endl;
	return 0;
}