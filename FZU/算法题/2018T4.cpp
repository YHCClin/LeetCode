#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
void generate(vector<int>& nums,vector<int>& item,int k,int &sum,int M, vector<vector<int>>& result)
{
	//递归出口
	if(k >= nums.size())
	{
		return;
	}
	//选择nums[k]
	sum += nums[k];
	item.push_back(nums[k]);
	if(sum == M)
		result.push_back(item);
	//继续生成子集
	generate(nums,item,k+1,sum,M,result);
	//不选择nums[k]
	sum -= item.back();
	item.pop_back();
	//继续生成子集
	generate(nums,item,k+1,sum,M,result);
}

// 迭代解法
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<vector<int>> ret = {{}};
	if(nums.empty()) return ret;
	sort(nums.begin(), nums.end());     // 排序
	int start = 0;
	for (int i = 0; i < nums.size(); ++i) {
		int len = ret.size();
		if (i>0 && nums[i]!=nums[i-1])
			start = 0;          // 新数字，全部遍历
		for(int j = start; j < len; ++j){
			vector<int> tmp = ret[j];
			tmp.push_back(nums[i]);
			ret.push_back(tmp);
		}
		start = ret.size() - (len - start); // 重复数字,从上一轮新添加的部分开始
	}
	return ret;
}

int main()
{
	vector<int> nums = {1,2,3,4,3,4,3,4,3,2,4,43,45,5,3,2,3,4,6,43,3,6};
	int M = 7;
	vector<vector<int>> res;
	vector<int> item;
	int sum = 0;
	generate(nums,item,0,sum,M,res);
	// 去重
	vector<vector<int>> sets;
	for(auto i : res)
	{
		sort(i.begin(),i.end());
		if(find(sets.begin(),sets.end(),i) == sets.end())
			sets.push_back(i);
	}
	for(auto i : sets)
	{
		for(auto j : i)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}