#include "Include_all.h"
using namespace std;

bool canJump(vector<int>& nums)
{
	//index数组记录从第i位置最远可以跳到第index[i]位置上
	vector<int> index(nums.size());
	for(int i = 0;i < nums.size();++i)
	{
		index[i] = i + nums[i];
	}
	//jump指针遍历nums，表示当前所处位置
	int jump = 0;
	int max_pos = index[0];
	for(;jump <= max_pos && jump < nums.size();++jump)
	{
		if(index[jump] > max_pos)
		{
			max_pos = index[jump];
		}
	}
	if(jump >= nums.size())
	{
		return true;
	}
	return false;

}

int main()
{

	return 0;
}