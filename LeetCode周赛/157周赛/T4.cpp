#include "Include_all.h"
using namespace std;

const long long MOD=1e9+7;
// a, e, i, o, u
// 0, 1, 2, 3, 4
class Solution {
public:
    // 动态规划 dp[i] 和 f[i] 表示以 i 结尾的个数
    long long dp[5], f[5];
    int countVowelPermutation(int n) {
        // 初始化dp数组
        --n; for (int i=0; i<5; i++) dp[i]=1;
        for (int j=0; j<n; ++j){
            // f 清空
            memset(f, 0, sizeof(f));
            // 以a结尾的有三个，e, i, u
            f[0]=(dp[1]+dp[2]+dp[4])%MOD;
            // 以e结尾的有两个，a, i
            f[1]=(dp[0]+dp[2])%MOD;
            // 以i结尾的有两个，e, o
            f[2]=(dp[1]+dp[3])%MOD;
            // 以o结尾的有一个，i
            f[3]=(dp[2])%MOD;
            // 以u结尾的有两个， i, o
            f[4]=(dp[2]+dp[3])%MOD;
            // 记录长度为 j 时的结果
            for (int i=0; i<5; i++) dp[i]=f[i];
        }
        long long ans=0;
        for (int i=0; i<5; i++) ans=(ans+dp[i])%MOD;
        return ans;
    }
};