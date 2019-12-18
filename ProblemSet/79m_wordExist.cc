#include "Include_all.h"
using namespace std;

// 超时解法
class SolutionTL {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    
    void dfs(vector<vector<char>> &board, string word, int k, int x, int y, bool &res)
    {
        if(k >= word.size())
        {
            res = true;
        }
        else
        {
            for(int i = 0;i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && nx < board.size() && ny>=0 && ny < board[0].size() && board[nx][ny] == word[k])
                {
                    char temp = board[nx][ny];
                    board[nx][ny] = '-';
                    dfs(board, word, k+1, nx, ny,res);
                    board[nx][ny] = temp;
                }
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        for(int i = 0;i < board.size(); i++)
        {
            for(int j = 0;j < board[0].size();j++)
            {
                if(board[i][j] == word[0])
                {
                    char temp = board[i][j];
                    board[i][j] = '-';
                    dfs(board, word, 1, i, j, res);
                    if(res) return res;
                    board[i][j] = temp;
                }
            }
        }
        return res;
    }
};

// AC解法
class SolutionAC {
public:
    bool helper(vector<vector<char>>& board, string& word, int i,int j,int length){
        if(i>=board.size()||j>=board[0].size()||i<0||j<0||length>=word.size()||word[length]!=board[i][j]){
            return false;
        }
        if(length==word.size()-1&&word[length]==board[i][j]){
            return true;
        }
        char temp=board[i][j];
        board[i][j]='-';//找到之后随便修改一个值
        bool flag=helper(board,word,i,j+1,length+1)||helper(board,word,i,j-1,length+1) \
                        ||helper(board,word,i+1,j,length+1)||helper(board,word,i-1,j,length+1);
        board[i][j]=temp;//遍历之后再给恢复
        return flag;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                    if(helper(board,word,i,j,0))
                        return true;
            }
        }
        return false;
    }
};