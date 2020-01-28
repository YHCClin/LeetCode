#include <iostream>
#include <vector>
using namespace std;
/×
  遍历数组，当遇到不满足条件时有两种改变方法：
  1. 将前者变小
  2. 将后者变大

  先尝试第一种，若不满住再尝试第二种
×/
bool checkPossibility(vector<int> &nums) {
  int ct = 0;
  for(int i = 0;i < nums.size() - 1;i++)
  {
    // 前后满足不减条件，继续迭代
    if(nums[i] <= nums[i+1])
    {
      continue;
    }
    if(++ct > 1)
    {
      return false;
    }
    int temp = nums[i];
    // 尝试让nums[i]变小
    if(i > 0)
    {
      nums[i] = nums[i-1];
    }
    else
    {
      nums[i] = nums[i+1];
    }
    // 让nums[i] 变小不满足条件，故尝试让nums[i+1]变大
    if(nums[i] > nums[i+1])
    {
      nums[i] = temp;
      nums[i+1] = nums[i];
    }
  }
  return true;
}
