#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int> nums, int target)
{
	#根据题意，不要求返回插入后的数组，故可不插入，返回位置即可。因此可以不考虑一些元素移动的问题，也无需利用迭代器啥的。
	int mid = 0;
	int beg = 0;
	int end = nums.size()-1;

	while(beg < end)
	{
		mid = beg + (end - beg) / 2;
		if(target > nums[mid])
		{
			beg = mid + 1;
		}
		else if(target < nums[mid])
		{
			end = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	if(target <= nums[beg])
	{
		return beg;
	}
	return end + 1;
}

int main()
{
	std::vector<int> nums{1,3,5,6};
	cout << searchInsert(nums,5) << endl;
	return 0;
}