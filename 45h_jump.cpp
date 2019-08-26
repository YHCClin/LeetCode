#include "Include_all.h"
using namespace std;

int jump(vector<int>& nums) {
        if(nums.size()<2) return 0;
        //index数组记录从第i位置最远可以跳到第index[i]位置上
        vector<int> index(nums.size());
        for(int i = 0;i < nums.size();++i)
        {
            index[i] = i + nums[i];
        }
        //jump指针遍历nums，表示当前所处位置
        int jump = 0;
        //当前位置最远可以跳到哪里
        int current_max_pos = index[0];
        //当前可选跳跃位置的下一次跳跃最远可跳到哪里
        int max_pos = index[0];
        //结果（最少跳跃次数）
        int res = 1;
        
        for(;jump < nums.size();++jump)
        {
        	//遍历完可选跳跃位置，必须选择一个位置跳跃过去
            if(jump > current_max_pos)
            {
                res++;
                //跳跃到下一次可以到达的最远的位置的位置，更新当前可跳到的最远位置
                current_max_pos = max_pos;
            }
            //更新可选范围内的下一跳可跳至的最远位置
            if(index[jump] > max_pos)
            {
                max_pos = index[jump];
            }
        }
        return res;
        
    }

int main()
{
	cout << "hello world" << endl;
	return 0;
}