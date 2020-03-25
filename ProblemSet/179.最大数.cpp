/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */
#include "Include_all.h"
using namespace std;

// @lc code=start
class Solution {
public:
struct comp{
	bool operator()(const string& a,const string& b)
	{
        string s1 = a + b;
        string s2 = b + a;
        return s1 < s2;
		//小顶堆(>),大顶堆(<)
	}
};
    // to_string(int) 函数
    string largestNumber(vector<int>& nums) {
        priority_queue<string,vector<string>,comp> bigger;
        int n = nums.size();
        bool flag = false;
        for(int i = 0;i < n;i++)
        {
            if(nums[i] != 0) flag = true;
            bigger.push(to_string(nums[i]));
        }
        string ans = "";
        while(!bigger.empty())
        {
            ans += bigger.top();
            bigger.pop();
        }
        if(flag)
            return ans;
        return "0";
    }
};
// @lc code=end

