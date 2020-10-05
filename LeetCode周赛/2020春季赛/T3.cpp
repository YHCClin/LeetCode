#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
class Solution {
    int increase[10005][3];
public:
    vector<int> getTriggerTime(vector<vector<int>>& inc, vector<vector<int>>& req) {
        int c = 0, r = 0, h = 0;
        int n = req.size();
        int m = inc.size();
        vector<int> ans(n,-1);
        memset(increase,0,sizeof(increase));
        for (int d = 0; d < m; d++) {
            auto x = inc[d];
            for (int q = 0; q < 3; q++)
               increase[d + 1][q] = increase[d][q] + x[q];
        }
        for(int k = 0;k < n;k++) {
            int i = 0,j = m;
            int cur = -1;
            while(i <= j) {
                int mid = (i + j)/2;
                if(increase[mid][0]>=req[k][0] && increase[mid][1]>=req[k][1] && increase[mid][2]>=req[k][2]){
                    cur = mid;
                    j = mid - 1;
                }
                else {
                    i = mid + 1;
                }
            }
            ans[k] = cur;
        }
        return ans;
    }
};