#include "Include_all.h"
using namespace std;

/*
	由于子文件夹字符串肯定长于父文件夹，故排序字符串数组，
	以第一个文件为当前根目录（入结果数组）向后遍历，若当前遍历到的文件是当前根目录的子文件夹就跳过它
	若不是则更新它为根目录（入结果数组）继续遍历，如此往复直到遍历完成。
 */

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        if(n == 0 || n == 1) return folder;
        vector<string> res;
        sort(folder.begin(),folder.end());
        string root = folder[0];
        int root_len = root.size();
        res.push_back(root);
        for(int i = 1;i < n;i++)
        {
            if(folder[i].size() > root_len && folder[i].substr(0,root_len) == root && !isalpha(folder[i][root_len]))
                continue;
            else
            {
                root = folder[i];
                root_len = root.size();
                res.push_back(root);
            }
        }
        return res;
    }
};