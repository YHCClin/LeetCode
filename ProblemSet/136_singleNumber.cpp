#include "Include_all.h"
using namespace std;

//利用一个数与一个相同的数做偶数次异或运算不改变该数的值
int singleNumber(vector<int>& nums)
{
	int ans = nums[0];
	int i = 1;
	int n = nums.size();
	while(i < n)
	{
		//异或运算
		ans = ans^nums[i];
		++i;
	}
	return ans;
}

int main()
{
	vector<int> v{4,1,2,1,2};
	cout << singleNumber(v) << endl;
	return 0;
}