#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> x;// 当前解
  vector<int> bx;// 当前最优解
  int cost = 0;
  int bcost = INT_MAX;
  int n;// 城市数量
  vector<vector<int>> grap;// 矩阵
  vector<string> codes;
  Solution(vector<vector<int>> &r, vector<string> &c, int n_){
    grap = vector<vector<int>>(n,vector<int>(n,0));
    int rn = r.size();
    for(int i = 0;i < rn;i++){
      grap[r[0]][r[1]] = r[2];
      grap[r[1]][r[0]] = r[2];
    }
    codes = c;
  }
  
  void backtrack(int k){
    if(k == n-1){
      if(grap[x[k-1]][x[k]] != 0 && (cost+grap[x[k-1]][x[k]] < bcost)){
        for(int j = 0;j < n;j++){
          bx[j] = x[j];
        }
        bcost = cc+grap[x[k-1]][x[k]];
      }
    }
    else
    {
      for(int j = k;j < n;j++){
        // 是否可进入x[j]子树
        if(grap[x[k-1]][x[j]] != 0 && cost+grap[x[k-1]][x[j]] < bcost){
          swap(x[k],x[j]);
          cost += grap[x[j-1]][x[j]];
          backtrack(k+1);
          cost -= grap[x[j-1]][x[j]];
          swap(x[k],x[j]);
        }
      }
    }
  }
  string happy(){
    backtrack(0);
    string ans = "";
    for(auto i : bx){
      ans += codes[i];
    } 
    return ans;
  }
};
// 旅行商人问题

int main(){
  
  return 0;
}
