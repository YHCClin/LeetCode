#include "Include_all.h"
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q)
{
		//若全为空树，则两树相同
		if((q==NULL && p==NULL))
		    return true;
		//结构不一，两树不同
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL))
            return false;
        //值不一，两树不同
        if(p->val != q->val)
            return false;
        //若发现左子树不同，则两树不同；否则判断右子树
        return isSameTree(p->left,q->left) ? isSameTree(p->right,q->right) : false;
}

int main()
{

	return 0;
}