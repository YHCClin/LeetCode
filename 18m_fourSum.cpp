#include <iostream>
#include <vector>
using namespace std;

int fourSum(vector<int>& nums,int target)
{
	int n = nums.size();
	int a=0,b=0,c=0,d=0;
	vector<vector<int>> res;
	for( ;a < n-3;a++)
		for(b = a+1;b < n-2;b++)
			for(c = b+1;c < n-1;c++)
				for(d = c+1;c < n;d++)
				{
					if(nums[a]+nums[b]+nums[c]+nums[d]==target)
					{
						vector<int> cur = {nums[a],nums[b],nums[c],nums[d]};
						res.push_back(cur);
					}
				}
	for(auto re : res)
	{
		for(int m = 0;m < re.size();m++)
		{
			cout << re[n] << " ";
		}
		cout << endl;
	}
	
	return 0;
}
int main()
{
	vector<int> nums = {1,0,-1,0,-2,2};
	fourSum(nums,0);
	return 0;
}