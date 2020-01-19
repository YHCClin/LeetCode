#include <iostream>
#include <vector>
using namespace std;
// 6 和 9 组成的最大数字
class Solution {
public:
    vector<int> Inttovec(int n)
    {
        vector<int> ans;
        while(n)
        {
            ans.push_back(n%10);
            n /= 10;
        }
        return ans;
    }
    int maximum69Number (int num) {
        vector<int> b(Inttovec(num));
        reverse(b.begin(),b.end());
        for(auto &i : b)
        {
            if(i == 6)
            {
                i = 9;
                break;
            }
        }
        int n = b.size();
        int ans = 0;
        int mul = 0;
        for(int i = n - 1;i >= 0;--i)
        {
            ans += b[i]*pow(10,mul);
            mul++;
        }
        return ans;
    }
};
