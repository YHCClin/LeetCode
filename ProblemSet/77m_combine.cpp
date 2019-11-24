#include <bits/stdc++.h>

/* 1-n 可以构成的 k 个数的组合 */
class Solution {
public:
    vector<vector<int>> res;

    void dfs(int n, int k, int start, vector<int> &path) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        for (int i = start; i <= n - (k - path.size()) + 1/*最多再选个数*/; ++i) { // 保证每种组合都是升序的，防止重复
            path.push_back(i);
            dfs(n, k, i + 1, path);
            path.pop_back(); // 回溯
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        if (n <= 0 || k <= 0 || k > n) {
            return res;
        }

        vector<int> path;
        dfs(n, k, 1, path);
        return res;
    }
};