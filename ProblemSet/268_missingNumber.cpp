#include "Include_all.h"
using namespace std;
//先排序，在寻找（效果最差）
int missingNumber_(vector<int>& nums)
{
	sort(nums.begin(),nums.end());
    int i;
    for(i = 0;i < nums.size();++i)
    {
        if(i != nums[i])
        {
            return i;
        }
    }
    return i;
}

//先求和，再以目标值减去（效果最好）
int missingNumber(vector<int>& nums)
{
	int sum = 0,aim = 0;
	int i;
	for(i = 0;i <= nums.size();++i)
	{
		aim += i; 
	}
	for(i = 0;i < nums.size();++i)
	{
		sum += nums[i];
	}
	return aim - sum;
}

//异或运算（也很差）
int missingNumber__(vector<int>& nums)
{
	int i;
	int ans=nums.size(); 
	for(i=0;i < nums.size();++i)
	{
		ans = ans^nums[i];
		ans = ans^i;
	}
	return ans;
}

int main()
{
	vector<int> v{9,6,4,2,3,5,7,0,1};
	cout << missingNumber(v) << endl;
	return 0;
}