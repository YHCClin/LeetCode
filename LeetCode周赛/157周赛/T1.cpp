#include "Include_all.h"
using namespace std;

// 如果砝码在奇(偶)数位，那么它可以0代价地移到任意一个奇(偶)数位
// 因此只需统计数组中的奇数偶数的个数，那么只要贪心选择最终移动的位置（奇数位或偶数位）
// 使得代价最小就好了

class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int odd = 0;
        for(int i = 0;i < chips.size();i++)
        {
            if(chips[i]%2==1) odd++;
        }
        int nodd = chips.size()-odd;
        if(odd >= nodd)
        {
            return nodd;
        }
        else
            return odd;
    }
};

int main()
{

	reutrn 0;
}