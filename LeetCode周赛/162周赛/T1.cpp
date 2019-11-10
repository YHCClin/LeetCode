#include "Include_all.h"

int matrix[55][55];
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        memset(matrix,0,sizeof(matrix));
        for(auto i : indices)
        {
            int row = i[0];
            int col = i[1];
            for(int j = 0;j < m;j++) matrix[row][j]++;
            for(int j = 0;j < n;j++) matrix[j][col]++;
        }
        int ret = 0;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                if(matrix[i][j] % 2 == 1)
                    ret ++;
        return ret;
    }
};