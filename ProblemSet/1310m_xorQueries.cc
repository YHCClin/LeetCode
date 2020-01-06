#include "Include_all.h"

/*
	前缀异或数组
 */
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = queries.size();
        vector<int> preXor(arr.size());
        preXor[0] = arr[0];
        for(int i = 1;i < arr.size();i++)
            preXor[i] = preXor[i-1] ^ arr[i];
        for(int i = 0;i < n;i++)
        {
            int L = queries[i][0];
            int R = queries[i][1];
            if(L == R) ans.push_back(arr[L]);
            else if(R - L == 1) ans.push_back(arr[L] ^ arr[R]);
            else
            {
                if(L == 0) ans.push_back(preXor[R]);
                else
                {
                    ans.push_back(preXor[R] ^ preXor[L-1]);
                }
            }
        }
        return ans;
    }
};