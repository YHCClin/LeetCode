#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val)
{
	auto iter = nums.begin();
	while(iter != nums.end())
	{
		if(*iter == val)
		{
			nums.erase(iter);
		}
		else
		{
			iter++;
		}
	}
	return nums.size();
}

int main()
{
	std::vector<int> nums{0,1,2,2,3,0,4,2};
	cout << removeElement(nums,2) << endl;;

	return 0;
}