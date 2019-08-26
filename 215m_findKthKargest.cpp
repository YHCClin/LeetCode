#include "Include_all.h"
using namespace std;

int findKthLargest(vector<int>& nums, int k)
{
	priority_queue<int,vector<int>,greater<int>> Q;
	int n = nums.size();
	for(int i = 0;i < n; ++i)
	{
		if(Q.size() < k)
		{
			Q.push(nums[i]);
		}
		else if(Q.top() < nums[i])
		{
			Q.pop();
			Q.push(nums[i]);
		}
	}
	return Q.top();
}

int main()
{
	vector<int> nums{3,2,1,5,6,4};
	cout << findKthLargest(nums,2) << endl;
}