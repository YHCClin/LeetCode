#include "Include_all.h"
using namespace std;

// 最长公共子序列，动态规划
// 状态转移方程：
// 			| 0 , 								i > 0;j=0
// c[i][j] =| c[i-1][j-1]+1 ,		 			s1[i] == s2[j]
// 			| max(c[i-1][j],c[i][j-1]) , i,j>0; s1[i] != s2[j]
// 			
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        int dp[m+1][n+1];
        for(int i = 0;i <= m;i++)
            for(int j = 0;j <= n;j++)
                dp[i][j] = 0;
        for(int i = 1;i <= m;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};