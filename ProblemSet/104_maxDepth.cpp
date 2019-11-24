#include "Include_all.h"
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root)
{
	if(root)
	{
		return max(maxDepth(root->left),maxDepth(root->right))+1;
	}
	return 0;
}

int main()
{
	TreeNode* root = new TreeNode(3);
	TreeNode* a = new TreeNode(9);
	TreeNode* b = new TreeNode(20);
	TreeNode* c = new TreeNode(15);
	TreeNode* d = new TreeNode(7);

	root -> left = a;
	root -> right = b;
	b -> left = c;
	b -> right = d;

	cout << maxDepth(root);
}

/*
执行用时 :24 ms, 在所有 C++ 提交中击败了69.29%的用户
内存消耗 :19.5 MB, 在所有 C++ 提交中击败了20.12%的用户
*/