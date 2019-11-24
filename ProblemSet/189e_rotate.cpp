#include "Include_all.h"
using namespace std;

void reverse(vector<int>& nums,int beg,int end)
{
	int i = beg,j = end;
	int temp;
	while(i < j)
	{
		temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;

		i++;
		j--;
	}
}
void rotate(vector<int>& nums,int k)
{
	int n = nums.size();
	int k_ = k%n;           //这一步很重要
	reverse(nums,n-k_,n-1);
	reverse(nums,0,n-k_-1);
	reverse(nums,0,n-1);
}


int main()
{
	vector<int> nums{1,2,3,4,5,6,7};
	rotate(nums,8);

	for(auto i : nums)
	{
		cout << i << "  ";
	}
	cout << endl;
	return 0;
}