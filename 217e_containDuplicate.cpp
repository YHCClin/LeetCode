#include "Include_all.h"
using namespace std;

//先排序后遍历,时间复杂度至少为nlog2(n)
bool containsDuplicate_(vector<int>& nums) {
		if(nums.size() == 0 || nums.size() == 1)
		{
			return false;
		}
		sort(nums.begin(),nums.end());
		int temp = nums[0];
		for(int i = 1;i < nums.size();i++)
		{
			if(temp == nums[i])
			{
				return true;
			}
			else
			{
				temp = nums[i];
			}
		}
		return false;
	}

//hashMap解法
bool containsDuplicate(vector<int>& nums)
{
	unordered_set<int> set;
	for(int i = 0;i < nums.size();i++)
	{
		set.insert(nums[i]);
	}
	if(set.size() < nums.size())
	{
		return true;
	}
	else
		return false;
}
int main()
{
	vector<int> set{1,2,4,3,1};
	cout << containsDuplicate(set) << endl;
	return 0;
}