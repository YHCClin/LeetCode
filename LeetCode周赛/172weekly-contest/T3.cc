/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
// 删除叶节点
using namespace std;
class Solution {
public:
    void helper(TreeNode* root,TreeNode *parent,int tg, bool &flag)
    {
        if(root)
        {
            if(root->left && !root->left->left && !root->left->right && root->left->val == tg)
            {
                root->left = NULL;
                flag = true;
            }
            if(root->right && !root->right->left && !root->right->right && root->right->val == tg)
            {
                root->right = NULL;
                flag = true;
            }
            helper(root->left,root,tg,flag);
            helper(root->right,root,tg,flag);
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool flag = true;
        while(flag)
        {
            flag = false;
            helper(root,NULL,target,flag);
        }
        if(root->val == target && !root->left && !root->right)
            root = NULL;
        return root;
    }
};
