#include <bits/stdc++.h>
using namespace std;
// 回溯法， 超时
class Solution {
public:
    //dp[i][j] = arr[i][j] + min{dp[i-1][k]}, 其中k={0...n-1, k!=j}
    int bestx = 99999;
    int x = 0;
    int n;
    void backtrack(int k, int lastc, vector<vector<int>> &arr)
    {
        if(k >= n)
        {
            if(x < bestx) bestx = x;
        }
        else
        {
            for(int i = 0;i < n;i++)
            {
                int llastc = lastc;
                if(i != lastc)
                {
                    x += arr[k][i];
                    lastc = i;
                    backtrack(k+1,i,arr);
                    x -= arr[k][i];
                    lastc = llastc;
                }
            }
        }
    }
    int minFallingPathSum(vector<vector<int>>& arr) {
        // 回溯法
        this->n = arr.size();
        int lastc = -1;
        backtrack(0, lastc, arr);
        return bestx;
    }
};

// 动态规划
class SolutionDp {
public:
    int dp[205][205];
    //dp[i][j] = arr[i][j] + min{dp[i-1][k]}, 其中k={0...n-1, k!=j}
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        for(int i = 0;i < n;i++)
        {
            dp[0][i] = arr[0][i];
        }
        for(int i = 1;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                int mn = INT_MAX;
                for(int k = 0;k < n; k++)
                {
                    if(k != j && dp[i-1][k] < mn)
                        mn = dp[i-1][k];
                }
                dp[i][j] = arr[i][j] + mn;
            }
        }
        int res = INT_MAX;
        for(int i = 0;i < n;i++)
            if(res > dp[n-1][i])
                res = dp[n-1][i];
        return res;
    }
};