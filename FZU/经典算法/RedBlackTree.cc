#include <bits/stdc++.h>

#define RED true
#define BLACK false
using namespace std;
#define KeyType int
#define ValueType string

class RBNode {

	friend bool isRed(RBNode *node);
	friend RBNode* leftRotate(RBNode *node);
	friend RBNode* rightRotate(RBNode *node);
	friend void flipColor(RBNode *node);
	friend RBNode* insert(RBNode *&root, KeyType key, ValueType value);
	friend int size(RBNode *node);
	friend RBNode* search(RBNode *root, KeyType key);

public:
	RBNode(KeyType k, ValueType v, int n, bool c) : key(k), value(v), N(n), color(c), left(NULL), right(NULL) { }

private:
	KeyType key;			// 节点保存的键值
	ValueType value;		// 键值关联的值
	RBNode *left, *right;	// 左右孩子节点指针
	int N;					// 这棵子树中的节点数
	bool color;				// 节点颜色：真为红，假为黑
};

// 获得以node为根的树的节点数
int size(RBNode *node)
{
	if(node == NULL) return 0;
	return node -> N;
}

// 获得节点颜色
bool isRed(RBNode *node)
{
	if(node == NULL) return false;
	return node->color == RED;
}

// 改变节点颜色
void flipColor(RBNode *node)
{
	node -> color = RED;
	node -> left -> color = BLACK;
	node -> right -> color = BLACK;
}

// 左旋操作
RBNode* leftRotate(RBNode *node)
{
	RBNode *temp  = node -> right;
	node -> right = temp -> left;
	temp -> left  = node;
	temp -> color = node -> color;
	node -> color = RED;
	temp -> N     = node -> N;
	node -> N     = 1 + size(node->left) + size(node->right);
	return temp;	// 返回重置父节点指针
}

// 右旋操作
RBNode* rightRotate(RBNode *node)
{
	RBNode *temp  = node -> left;
	node -> left  = temp -> right;
	temp -> right = node;
	temp -> color = node -> color;
	node -> color = RED;
	temp -> N     = node -> N;
	node -> N     = 1 + size(node->left) + size(node->right);
	return temp;	// 返回重置父节点指针
}

RBNode* search(RBNode* root, KeyType key)
{
	if(root == NULL) return NULL;
	else
	{
		if(root -> key == key) return root;
		else if(root -> key < key)
		{
			return search(root -> left, key);
		}
		else
		{
			return search(root -> right, key);
		}
	}
}


RBNode* insert(RBNode *&root, KeyType key, ValueType value)
{
	if(root == NULL)
		return new RBNode(key, value, 1, RED);

	if(key < root->key) 	 	 	root -> left  = insert(root->left, key, value);
	else if(key > root->key) 	root -> right = insert(root->right, key, value);
	else 											root -> value = value;

	// 应对三种情况的操作
	if(isRed(root->left) && !isRed(root->left))				root = leftRotate(root);	
	if(isRed(root->left) && isRed(root->left->left))	root = rightRotate(root);
	if(isRed(root->left) && isRed(root->right))							 flipColor(root);

	root -> N = size(root->left) + size(root->right) + 1;
	return root;
}

int main()
{

	return 0;
}