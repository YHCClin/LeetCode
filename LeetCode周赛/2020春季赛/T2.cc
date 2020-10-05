#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void helper(vector<vector<int>> &mat, int cur_node,int &cnt, int deep, int k) {
        if(deep > k) return;
        if(deep == k && cur_node == mat.size()-1){
            cnt++;
            return;
        }
        else {
            for(int i = 0;i < mat.size();++i) {
                if(mat[cur_node][i]){
                    helper(mat,i,cnt,deep+1,k);
                }
            }
        }
        
    }
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        for(auto p : relation) {
            matrix[p[0]][p[1]] = 1;
        }
        int ans = 0;
        helper(matrix,0,ans,0,k);
        return ans;
    }
};