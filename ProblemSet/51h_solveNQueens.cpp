#include "Include_all.h"
using namespace std;

// 回溯法

// 方向数组
int dx[8] = {-1,1,0,0,-1,-1,1,1};
int dy[8] = {0,0,-1,1,-1,1,-1,1};

// 放置皇后并标记可被攻击位置
void setQueen(vector<vector<bool>>& board,int x,int y)
{
	int n = board.size();
	board[x][y] = false;
	for(int i=0;i<8;i++)
	{
		int x_ = x;
		int y_ = y;
		for(int j=0;;j++)
		{
			x_ = x_ +dx[i];
			y_ = y_ +dy[i];
			if(x_>=0 && x_<n && y_>=0 && y_<n)
				board[x_][y_] = false;
			else break;
		}
	}
}
//递归生成结果generate(在第Q行放置，可放置位置标记，当前可能结果，结果集合)
void generate(int Q,int N,vector<vector<bool>> &board,vector<string> &ans,vector<vector<string>> &res)
{
	if(Q==N){res.push_back(ans); return;}
	
	// 尝试第Q行的每一列
	for(int i = 0;i < N;i++)
	{
		if(board[Q][i])
		{
			vector<vector<bool>> temp_board = board; // 还原时用
			// 放置皇后
			ans[Q][i] = 'Q';
			setQueen(board,Q,i);
			generate(Q+1,N,board,ans,res);
			// 回溯还原
			board = temp_board;
			ans[Q][i] = '.';
		}
	}
}
vector<vector<string>> solveNQueens(int n)
{
	vector<vector<string>> res;
	vector<vector<bool>> board(n,vector<bool>(n,true));
	string row = "";
	for(int i = 0;i < n;i++) row+='.';
	vector<string> ans(n,row);
	// 从第0行开始放置皇后
	generate(0,n,board,ans,res);
	return res;
}

int main()
{
	vector<vector<string>> res(solveNQueens(4));
	//cout << res.size() << endl;
	for(auto i : res)
	{
		for(auto j : i)
		{
			cout << j << endl;
		}
		cout << endl;
	}
	return 0;
}