#include "Include_all.h"
using namespace std;

// 倒置字符串，做一次LCS，再做判断

class Solution {
public:
    int max3(int x, int y, int z) {
        return max(x, max(y, z));
    }
    // 最长公共子序列
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.empty() || text2.empty()) return 0;
        int M = text1.size();
        int N = text2.size();
        // dp[i][j]代表text1前i个数与text2前j个数的最大匹配值
        vector<vector<int> > dp(M + 1, vector<int>(N + 1, 0)); 
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                dp[i][j] = max3(dp[i - 1][j], dp[i][j - 1], 
                        dp[i - 1][j - 1] + (text1[i - 1] == text2[j - 1]));
            }
        }
        return dp[M][N];
    }
    
    bool isValidPalindrome(string s, int k) {
        string sr = s;
        reverse(sr.begin(),sr.end());
        int sub = longestCommonSubsequence(s,sr);
        return s.size()-sub <= k ? true : false;
    }
};