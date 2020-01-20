#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
// 序列化 + 哈希
using namespace std;
struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 序列化函数
void serialize(TreeNode *root,vector<char> seria){
  if(root){
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
      TreeNode *p = que.front();
      que.pop();
      if(p) seria.push_back('0' + p->val);
      else {seria.push_back('#');continue;}
      que.push(p->left);
      que.push(p->right);
    }
  }
}
void dfs(TreeNode* root, map<TreeNode*,vector<char>>& serias){
  if(root){
    vector<char> s;
    serialize(root,s);
    serias[root] = s;
    dfs(root->left,serias);
    dfs(root->right,serias);
  }
}
vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
  map<TreeNode*,vector<char>> hmap;
  dfs(root,hmap);
  set<vector<char>> st;
  vector<TreeNode*> ans;
  for(auto iter = hmap.begin();iter != hmap.end();iter++){
    auto curnode = iter->first;
    int n = st.size();
    st.insert(iter->second);
    if(n == st.size()) ans.push_back(curnode);
  }
  return ans;
}

int main(){
  // 创建测试样例
  vector<TreeNode*> tree(7);
  for(int i = 0;i < 7;i++) tree[i] = new TreeNode(0);
  tree[0]->val = 1;
  tree[1]->val = 2;
  tree[2]->val = 3;
  tree[3]->val = 4;
  tree[4]->val = 2;
  tree[5]->val = 4;
  tree[6]->val = 4;
  tree[0]->left  = tree[1];
  tree[0]->right = tree[2];
  tree[1]->left  = tree[3];
  tree[2]->left  = tree[4];
  tree[2]->right = tree[5];
  tree[4]->left  = tree[6]; 

  vector<TreeNode*> ans(findDuplicateSubtrees(tree[0]));
  cout << ans.size() << endl;
}
