#include <iostream>
#include <vector>
#include <set>
using namespace std;
// 并查集思想，结果及为联通分量数减一

int get_root(int a, vector<int> &parantOf) {
  while(parantOf[a] != a)
    a = parantOf[a];
    return a;
}
void Union(int a, int b, vector<int> &parantOf){
  int a_root = get_root(a, parantOf);
  int b_root = get_root(b, parantOf);
  if(a_root != b_root)
    parantOf[a_root] = b_root;
}

int CountSet(vector<int> &parantOf) {
  int cnt = 0;
  int n = parantOf.size();
  for(int i = 0;i < n;i++)
    if(parantOf[i] == i) cnt++;
  return cnt;
}
int makeConnected(int n, vector<vector<int>> &connections) {
  vector<int> parantOf(n,0);
  for(int i = 0;i < n;i++) {
    parantOf[i] = i;
  }
  for(auto v : connections)
  {
    Union(v[0],v[1],parantOf);
  }
  return CountSet(parantOf)-1;
}
