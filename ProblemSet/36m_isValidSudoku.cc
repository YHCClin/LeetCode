#include "Include_all.h"
using namespace std;

class Solution {
public:
    vector<pair<int,int> > rec = {make_pair(0,0),make_pair(0,3),make_pair(0,6),make_pair(3,0),make_pair(3,3),make_pair(3,6),make_pair(6,0),make_pair(6,3),make_pair(6,6)};
    unordered_map<char, int> table;
    bool isValidSudoku(vector<vector<char>>& board) {
        // 每个 3x3 是否满足
        
        for(int k = 0;k < 9;++k)
        {
            table.clear();
            for(int i = rec[k].first;i < rec[k].first+3;i++)
            {
                for(int j = rec[k].second; j < rec[k].second+3;j++)
                {
                    if(board[i][j] != '.')
                    {
                        table[board[i][j]]++;
                        if(table[board[i][j]] > 1)
                        {
                            return false;
                        }
                    }
                }
            }
        }
        
        // 判断行
        for(int i = 0;i < 9;++i)
        {
            table.clear();
            for(int j = 0;j < 9;++j)
            {
                if(board[i][j] != '.')
                {
                    table[board[i][j]]++;
                    if(table[board[i][j]] > 1)
                        return false;
                }
            }
        }
        // 判断列
        for(int i = 0;i < 9;++i)
        {
            table.clear();
            for(int j = 0;j < 9;++j)
            {
                if(board[j][i] != '.')
                {
                    table[board[j][i]]++;
                    if(table[board[j][i]] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};