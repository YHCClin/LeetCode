#include "Include_all.h"
using namespace std;
class Solution {
public:
    int n;// 候选数组长度
    vector<bool> x; // 当前解
    int csum = 0; // 当前和
    set<vector<int>> res;//全部解
    int tar;
    int targ;
    void backtrack(int k, vector<int> &arr)
    {
        if(tar == 0)
        {
            vector<int> item;
            for(int i = 0;i < n;i++)
            {
                if(x[i])
                {
                    item.push_back(arr[i]);
                }
            }
            res.insert(item);
        }
        else
        {
            if(tar - arr[k] >= 0)
            {
                x[k] = true;
                tar -= arr[k];
                backtrack(k+1,arr);
                x[k] = false;
                tar += arr[k];
                backtrack(k+1,arr);
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        n = candidates.size();
        x = vector<bool>(n,false);
        tar = target;
        targ = target;
        backtrack(0,candidates);
        vector<vector<int>> ans;
        ans.assign(res.begin(),res.end());
        return ans;
    }
};

int main()
{   vector<int> a = {2,5,2,1,2};
    vector<int> arr = {14,6,25,9,30,20,33,34,28,30,16,12,31,9,9,12,34,16,25,32,8,7,30,12,33,20,21,29,24,17,27,34,11,17,30,6,32,21,27,17,16,8,24,12,12,28,11,33,10,32,22,13,34,18,12};
    Solution S;
    vector<vector<int>> ans(S.combinationSum2(a, 5));
    for(auto i : ans)
    {
        for(auto j : i)
            cout << j << "  ";
        cout << endl;
    }
    return 0;
}