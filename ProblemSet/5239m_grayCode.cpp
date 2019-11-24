#include "Include_all.h"
using namespace std;

class Solution {
public:
    // 生成格雷码
    vector<int> grayCode(int n) {
        vector<int> res;
        // 从0开始生成2^(n) - 1 个格雷码数
        for (int i = 0; i < pow(2, n); ++i) {
            res.push_back((i >> 1) ^ i);
        }
        return res;
    }
    vector<int> circularPermutation(int n, int start) {
        vector<int> gray(grayCode(n));
        int pos = -1;
        vector<int> res;
        for (int i = 0; i < gray.size(); i++)
        {
            if (start == gray[i]) pos = i;
            if (pos != -1)
                res.push_back(gray[i]);
        }
        for (int i = 0; i < pos; i++)
            res.push_back(gray[i]);
        return res;
    }
};