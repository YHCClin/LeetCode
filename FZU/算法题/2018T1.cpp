#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int HeroNumeric(vector<int> &nums)
{
	int n = nums.size();
	stack<int> sta;
	for(int i = 0;i < n;i++)
	{
		if(sta.empty()) sta.push(nums[i]);
		else
		{
			if(nums[i] != sta.top())
			{
				sta.pop();
				if(sta.empty())
					sta.push(nums[i]);
			}
			else
				sta.push(nums[i]);
		}
	}
	return sta.top();
}


int main()
{
	vector<int> nums = {1,2,1,2,2,1,1}; // Hero is 7
	cout << HeroNumeric(nums) << endl;
	return 0;
}