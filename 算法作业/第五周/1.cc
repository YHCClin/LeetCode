#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define MAX 20

using namespace std;

typedef long long ll; 

// ��λdp 
int a[MAX]; 
ll table[MAX];


ll dfs(int pos,int i, int j,bool lead,bool limit)
{
    if(pos==-1) return 1;
    if(!limit && !lead) {// �����û��ǰ��0����û������
    	if(j == -1) return table[pos+1];// pre2 ��ûѡ��ֻѡ��pre1��leadΪfalse�������Ѿ�ѡ��pre1�� , �������һλһ�� 
    	else return pow(2,pos+1);// ���������Ѿ�ѡ�ˣ���ô��������������������������Ϊ2^(ʣ�೤��) 
	}
	int up=limit ? a[pos]:9;// �������ޣ�����ǰһλ�Ƿ񵽴������ж� 
    ll ans=0;
    for(int c=0;c<=up;c++) {
        if(i == -1 || c == i || i == 0) ans += dfs(pos-1,c,j,lead && (c==0),limit && (c==up));// ����ѡ��һ�� 
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
    // Ԥ����table����
	memset(table,0,sizeof(table));
	table[0] = 1;
	for(int i = 1;i < MAX; i++){
		table[i] = 10;
		for(int j = i - 1;j >= 0;j--){
			if(j < i - 1) table[i] += 9;
			table[i] += (table[j]-1);
		}
 	}
	return dfs(pos-1,-1,-1, true,true)-1;// ��ȥһ��ȫΪ0�����
}

int main()
{  
    ll n;
    scanf("%lld",&n);
    printf("%lld\n",solve(n));
}
