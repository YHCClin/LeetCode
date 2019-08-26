#include "Include_all.h"
using namespace std;

int wiggleMaxLength(vector<int>& nums)
{
	//若数组为空返回0
	if(nums.size()<1) return 0;
	int res = 1;
	const int STATUS_START = 0;
	const int STATUS_UP = 1;
	const int STATUS_DOWN = 2;
	int CURRENT_STATUS = 0;
	for(int i = 1;i < nums.size();++i)
	{
		//有限状态自动机（三个状态）
		switch(CURRENT_STATUS)
		{
			//初始状态
			case STATUS_START:
				//状态变化
				if(nums[i] < nums[i-1])
				{
					CURRENT_STATUS = STATUS_DOWN;
					res++;
				}
				else if(nums[i] > nums[i-1])
				{
					CURRENT_STATUS = STATUS_UP;
					res++;
				}
				break;
			//上升状态
			case STATUS_UP:
				//状态变化
				if(nums[i] < nums[i-1])
				{
					CURRENT_STATUS = STATUS_DOWN;
					res++;
				}
				break;
			//下降状态
			case STATUS_DOWN:
				//状态变化
				if(nums[i] > nums[i-1])
				{
					CURRENT_STATUS = STATUS_UP;
					res++;
				}
				break;
		}
	}
	return res;
}

int main()
{
	vector<int> nums{1,7,4,9,2,5};
	cout << wiggleMaxLength(nums) << endl;
	return 0;
}