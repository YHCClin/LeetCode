#include "Include_all.h"
using namespace std;
void generate(vector<int>& nums,vector<int>& item,int k,vector<vector<int>>& result)
{
	//递归出口
	if(k >= nums.size())
	{
		return;
	}
	//选择nums[k]
	item.push_back(nums[k]);
	result.push_back(item);
	//继续生成子集
	generate(nums,item,k+1,result);
	//不选择nums[k]
	item.pop_back();
	//继续生成子集
	generate(nums,item,k+1,result);
}
vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> result;
	vector<int> item;
	result.push_back(item);

	generate(nums,item,0,result);
	return result;
}

//位运算法
vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> result;
	//子集个数
	int set_num = 1 << nums.size();
	//下面循环中的i表示所有可能集合中的一种
	for(int i = 0;i < set_num;i++)
	{
		vector<int> item;
		for(int j = 0;j < nums.size();j++)
		{
			if(i & (1 << j))
			{
				item.push_back(nums[j]);
			}
		}
		result.push_back(item);
	}
	return result;
}

int main()
{

	return 0;
}