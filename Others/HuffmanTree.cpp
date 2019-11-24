#include "Include_all.h"
using namespace std;

template <typename T>
class TreeNode {
	public:
		TreeNode(T c) : data(c) { }
		int getf() const { return f;}
	private:
		TreeNode *left = nullptr;
		TreeNode *right = nullptr;
		T data;
		int f = 0;
};

TreeNode *subTree(TreeNode *left, TreeNode *right)
{
	TreeNode *root = new TreeNode('#');
	root->left = left;
	root->right = right;
	root->data = left->data + right->data;
	return root;
}

TreeNode *creatHuffmanTree(string &str)
{
	priority_queue<TreeNode*,vector<TreeNode*>,>
}

int main()
{

}