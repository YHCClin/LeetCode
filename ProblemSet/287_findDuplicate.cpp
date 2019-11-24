#include "Include_all.h"
using namespace std;

/*
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。
假设只有一个重复的整数，找出这个重复的数。

题目要求O(1)空间复杂度，这里先不管，解出来再说
*/

int findDuplicate(vector<int>& nums)
{
	int n = nums.size();
	int cnt;
	std::vector<int> num_cnt(n+1,0);
	for(int i = 0;i < n;++i)
	{
		num_cnt[nums[i]]++;
		if(num_cnt[nums[i]]>=2)
		{
			return nums[i];
		}
	}
	return 0;

}

int main()
{
	std::vector<int> v{3,1,3,4,2};
	cout << findDuplicate(v) << endl;
	return 0;
}