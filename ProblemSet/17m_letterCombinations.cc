#include "Include_all.h"
using namespace std;

class Solution {
public:
    unordered_map<char, string> table{
            {'0', " "}, {'1',"*"}, {'2', "abc"},
            {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
            {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
            {'9',"wxyz"}};  
    void dfs(string &dig, string item, vector<string>& ans, int k)
    {
        if(k >= dig.size())
        {
            ans.push_back(item);
            return;
        }
        else
        {
            string temp = item;
            for(int i = 0;i < table[dig[k]].size();++i)
            {
                item += table[dig[k]][i];
                dfs(dig,item,ans,k+1);
                item = temp;// 回溯还原
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        string item = "";
        int n = digits.size();
        vector<string> ans;
        if(n == 0) return ans;
        dfs(digits, item,ans, 0);
        return ans;
    }
};