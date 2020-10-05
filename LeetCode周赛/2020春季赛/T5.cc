#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Node {
    double sum, single;
    Node() : sum(0.0), single(0.0) {}
    Node operator + (const Node &b) const {
        Node ret;
        Node left = *this, right = b;

        ret.sum = left.sum + right.sum; // 总时间

        // 计算并行后时间
        if(left.single > right.sum) {
            ret.single = left.single - right.sum;
            return ret;
        }

        if(right.single > left.sum) {
            ret.single = right.single - left.sum;
            return ret;
        }
        return ret;
    }

    double calc() {
        return 1.0 * sum / 2.0 + 1.0 * single / 2.0;
    }
};

class Solution {
public:
    Node dfs(TreeNode *rt) {
        if(!rt) return Node();
        Node ret = dfs(rt->left) + dfs(rt->right);
        ret.sum += rt->val;
        ret.single += rt->val;
        return ret;
    }
    
    double minimalExecTime(TreeNode *root) {
        return dfs(root).calc();
    }
};