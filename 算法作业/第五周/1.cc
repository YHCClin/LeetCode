#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define MAX 20

using namespace std;

typedef long long ll; 

// 数位dp 
int a[MAX]; 
ll table[MAX];


ll dfs(int pos,int i, int j,bool lead,bool limit)
{
    if(pos==-1) return 1;
    if(!limit && !lead) {// 如果非没有前导0并且没有上限
    	if(j == -1) return table[pos+1];// pre2 还没选，只选了pre1（lead为false隐含了已经选了pre1） , 结果与上一位一样 
    	else return pow(2,pos+1);// 两个数都已经选了，那么后面就是这两个数的排列组合了为2^(剩余长度) 
	}
	int up=limit ? a[pos]:9;// 计算上限，根据前一位是否到达上限判断 
    ll ans=0;
    for(int c=0;c<=up;c++) {
        if(i == -1 || c == i || i == 0) ans += dfs(pos-1,c,j,lead && (c==0),limit && (c==up));// 至多选了一个 
    	else if(j == -1 || c == j) ans += dfs(pos-1,i,c,lead && (c==0),limit && (c==up));
    }
    return ans;
}

ll solve(ll x)
{
    int pos=0;
    while(x)
    {
        a[pos++]=x%10;
        x/=10;  
    }
    // 预处理table数组
	memset(table,0,sizeof(table));
	table[0] = 1;
	for(int i = 1;i < MAX; i++){
		table[i] = 10;
		for(int j = i - 1;j >= 0;j--){
			if(j < i - 1) table[i] += 9;
			table[i] += (table[j]-1);
		}
 	}
	return dfs(pos-1,-1,-1, true,true)-1;// 减去一个全为0的情况
}

int main()
{  
    ll n;
    scanf("%lld",&n);
    printf("%lld\n",solve(n));
}
