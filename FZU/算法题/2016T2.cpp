#include <bits/stdc++.h>
using namespace std;

class TreeNode{
	public:
		int val;
		TreeNode *left, *right;
		TreeNode(int val_) : val(val_), left(NULL), right(NULL) {}
};

// 后序遍历非递归
vector<int> postorderTraversal(TreeNode* root, int x) {
	vector<int> ancestors;
	TreeNode* p=root; // 遍历指针
	TreeNode* r=NULL; // 标记最近访问过的节点
	stack<TreeNode*> sta;
	while(p || !sta.empty())
	{
		if(p)
		{
			// 一直向左
			sta.push(p);
			p = p->left;
		}
		else // 左子树为空
		{
			p=sta.top();
			if(p->right && p->right!=r)	// 右子树存在且未被访问过
			{
				p = p->right;			// 转向右子树
				sta.push(p);			// 压入栈中
				p=p->left;				// 转向左子树
			}
			else						// 右子树不存在 或 已被访问过
			{
				p=sta.top();			// 出栈访问
				sta.pop();
				if(p -> val == x)
				{
					ancestors.assign(sta.begin(), sta.end());
					return ancestors;
				}
				r=p;					// 记录最近访问节点
				p=NULL;					// 重置 p 指针
			}
		}
	}
	return ancestors;
}
vector<int> findAncestor(TreeNode *root)
{
	vector<int> ancestors(postorderTraversal(root));
	return ancestors;
}

int main()
{
	vector<int> ancestors = findAncestor(root);
	return 0;
}