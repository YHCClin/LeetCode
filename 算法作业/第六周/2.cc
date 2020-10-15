#include <bits/stdc++.h> 
#define M 305

using namespace std;

// 树型dp结合背包
int n,m,x; 
int dp[M][M];// dp[x][j] 表示以x为根的子树中选择j件商品所能获得的最大价值 
int son[M][M],cnt[M],v[M];// cnt[x] 表示课程x的儿子数 , v[x] 表示第x件商品的价值 


void dfs(int x){
    dp[x][0]=0;
    int p=cnt[x];
    for(int i=0;i<p;i++){//先算出不加上第x件商品的价值 
        int k=son[x][i];
        dfs(k);
        for(int t=m;t>=0;t--)//背包倒序循环
            for(int l=t;l>=0;l--)
                dp[x][t]=max(dp[x][t],dp[x][t-l]+dp[k][l]);
    }
    if(x!=0)//如果不为0节点，也就是整颗树的根节点，那么还要加上这件商品的价值 
        for(int i=m;i>0;i--)
            dp[x][i]=dp[x][i-1]+v[x];
}


int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x,&v[i]);
        son[x][cnt[x]++]=i;		//存x的儿子节点
    }
    dfs(0);// 从根节点开始 
    printf("%d\n",dp[0][m]);
    return 0;
}
