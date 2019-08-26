#include "Include_all.h"
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrderBottom(TreeNode* root)
{
	queue<TreeNode*> que;
	TreeNode *q;
	vector<vector<int>> ans;
	if(root != NULL)
	{
		que.push(root);
		
		while(!que.empty())
		{
			//队列的当前长度,即该层的结点个数
			int len = que.size();
			//存储当前层的数组
			vector<int> level;

			for(int i = 0;i < len;i++)
			{
				q = que.front();
				que.pop();

				//逐一压入
				level.push_back(q->val);

				if(q->left != NULL)
				{
					que.push(q->left);
				}
				if(q->right != NULL)
				{
					que.push(q->right);
				}
			}
			ans.push_back(level);
		}
	}
	return ans;
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



	vector<vector<int>> ans = levelOrderBottom(root);

	for(auto i : ans)
	{
		for(auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}