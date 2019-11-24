#include "Include_all.h"
using namespace std;

//hashMap
int firstMissingPositive(vector<int>& nums)
{
	unordered_set<int> set;
	for(int i : nums)
	{
		set.insert(i);
	}
	int num = 1;
	while(true)
	{
		if(set.count(num++) == 0)
			return --num;
	}
	return num;
}

int main()
{
	vector<int> nums = {3,4,-1,1};
	cout << firstMissingPositive(nums) << endl;
	return 0;
}