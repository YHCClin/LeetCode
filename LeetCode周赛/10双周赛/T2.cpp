#include "Include_all.h"
using namespace std;


 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    void helper(TreeNode *root, vector<int> &series)
    {
        if(!root) return;
        helper(root -> left,series);
        series.push_back(root -> val);
        helper(root -> right,series);
    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        vector<int> r1,r2;
        helper(root1,r1);
        helper(root2,r2);
        int m = r1.size();
        int n = r2.size();
        for(int i= 0;i < m;i++)
            for(int j = 0;j < n;j++)
            {
                if(r1[i] + r2[j] == target)
                    return true;
            }
        return false;
    }
};