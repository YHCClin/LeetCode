#include "Include_all.h"
using namespace std;

// 动态规划 hash[i,j] 表示以 i 结尾的最长序列为 j

class Solution {
public:
    
    int longestSubsequence(vector<int>& arr, int difference) {
        int res = 1;
        unordered_map<int,int> hash;
        for(auto i : arr)
        {
        	// 看是否能与之前的序列衔接上
            hash[i] = max(hash[i],hash[i-difference]+1);
            res = max(res,hash[i]);
        }
        return res;
    }
};