#include "Include_all.h"
using namespace std;

// 括号生成，回溯法

class Solution {
public:
    void generate(vector<string> &res,string cur,int left,int right,int n)
    {
        if(cur.size() == 2*n)
        {
            res.push_back(cur);
            return;
        }
        // 只要还有左括号就可以填入
        if(left < n) generate(res,cur+'(',left+1,right,n);
        // 要填又括号必须保证已经填入的左括号的数量大于已经填入的右括号数量，这样才能正常配对
        if(right < left) generate(res,cur+')',left,right+1,n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur = "";
        generate(res,cur,0,0,n);
        return res;
    }
};