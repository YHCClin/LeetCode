#include "Include_all.h"
using namespace std;

// 暴力判断会超时，故递推，由前推出后

class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        // 已知的前几个步进数
        vector<int> all = {0,1,2,3,4,5,6,7,8,9,10};
        int i = 1;
        vector<int> res;
        // 循环递推
        while(true)
        {
            if(all[i]%10 >=1)
            {
                all.push_back(all[i]*10 + all[i]%10-1);
                if(all[i]%10+1 < 10)
                    all.push_back(all[i]*10 + all[i]%10+1);
                if(all[i]*10 + all[i]%10+1 >= high) break;
            }
            else if(all[i]%10 == 0)
            {
                all.push_back(all[i]*10 + 1);
                if(all[i]*10 + all[i]%10+1 >= high) break;
            }
            i++;
        }
        int n = all.size();
        // 去重
        set<int> ans;
        for(int j = 0;j < n;j++)
        {
            if(all[j]>=low && all[j]<=high)
                ans.insert(all[j]);
        }
        res.assign(ans.begin(),ans.end());
        return res;
    }
};