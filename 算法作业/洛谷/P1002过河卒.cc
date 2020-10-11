#include <cstdio>
#include <cstring>
#include <iostream>
#define N 25
using namespace std;

typedef long long ll;

bool board[N][N];
int dp[N][N]; // dp[i][j] 表示到点[i][j] 有几种可能 

void init(int x, int y){
	memset(board,true,sizeof(board));
	memset(dp,0,sizeof(board));
	board[x][y] = false;
	int p[8][2] = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
	for(int i = 0;i < 8;++i) {
		int nx = x+p[i][0];
		int ny = y+p[i][1];
		if(nx<0 || nx>=N || ny<0 || ny>=N) continue;
		board[nx][ny] = false;
	}
	bool flag1 = false;
	bool flag2 = false;
	for(int i = 0;i < N;i++){
		if(!board[0][i]) break;
		else dp[0][i] = 1;
	}
	for(int i = 0;i < N;i++){
		if(!board[i][0]) break;
		else dp[i][0] = 1;
	}
}

ll solve(int x, int y){
	for(int i = 1;i <= x;++i)
		for(int j = 1;j <= y;++j){
			if(board[i][j]){
				ll l=0, u=0;
				if(board[i][j-1]) l = dp[i][j-1];
				if(board[i-1][j]) u = dp[i-1][j];
				dp[i][j] = l + u;
			}
		}
	return dp[x][y];
}

int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	init(c,d);
	
	for(int i = 0;i < N;i++){
		for(int j = 0;j < N;j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
	
	printf("%lld\n",solve(a,b));
	return 0;
}


