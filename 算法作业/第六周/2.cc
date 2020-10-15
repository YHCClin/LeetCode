#include <bits/stdc++.h> 
#define M 305

using namespace std;

// ����dp��ϱ���
int n,m,x; 
int dp[M][M];// dp[x][j] ��ʾ��xΪ����������ѡ��j����Ʒ���ܻ�õ�����ֵ 
int son[M][M],cnt[M],v[M];// cnt[x] ��ʾ�γ�x�Ķ����� , v[x] ��ʾ��x����Ʒ�ļ�ֵ 


void dfs(int x){
    dp[x][0]=0;
    int p=cnt[x];
    for(int i=0;i<p;i++){//����������ϵ�x����Ʒ�ļ�ֵ 
        int k=son[x][i];
        dfs(k);
        for(int t=m;t>=0;t--)//��������ѭ��
            for(int l=t;l>=0;l--)
                dp[x][t]=max(dp[x][t],dp[x][t-l]+dp[k][l]);
    }
    if(x!=0)//�����Ϊ0�ڵ㣬Ҳ�����������ĸ��ڵ㣬��ô��Ҫ���������Ʒ�ļ�ֵ 
        for(int i=m;i>0;i--)
            dp[x][i]=dp[x][i-1]+v[x];
}


int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x,&v[i]);
        son[x][cnt[x]++]=i;		//��x�Ķ��ӽڵ�
    }
    dfs(0);// �Ӹ��ڵ㿪ʼ 
    printf("%d\n",dp[0][m]);
    return 0;
}
