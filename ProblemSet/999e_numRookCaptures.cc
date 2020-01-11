#include "Include_all.h"
using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int n = board.size();
        int x,y;
        for(int i = 0;i < n;++i)
            for(int j = 0;j < n;++j)
                if(board[i][j] == 'R')
                {
                    x = i; y = j;
                }
        int ans = 0;
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i = 0;i < 4;i++)
        {
            int tx = x, ty = y;
            tx += dir[i][0];ty += dir[i][1];
            while(tx < n && ty < n && tx >= 0 && ty >=0 && board[tx][ty]!='B')
            {
                if(board[tx][ty] == 'p')
                {
                    ans++;
                    break;
                }
                tx += dir[i][0];ty += dir[i][1];
            }
        }
        return ans;
    }
};