#include <bits/stdc++.h>
using namespace std;

/*
    算法思想： 暴力枚举
*/
vector<int> SaddleNumber(vector<vector<int>>& arr)
{
    int m = arr.size();
    int n = arr[0].size();
    vector<int> res;
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            int cur = arr[i][j];
            bool maxf = true, minf = true;
            for(int h = 0;h < m;h++)
                if(cur < arr[i][h])
                    maxf = false;
            for(int h = 0;h < n;h++)
                if(cur > arr[h][j])
                    minf = false;
            if(maxf && minf)
                res.push_back(arr[i][j]);
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> arr = {
        {9,2,3,4},
        {1,8,3,4},
        {1,2,7,4},
        {1,2,3,4}
    };
    vector<int> ans = SaddleNumber(arr);
    for(auto i : ans)
        cout << i << " ";
        cout << endl;
    return 0;
}