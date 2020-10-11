#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,f[2005][2005];
int head[2005],next[2005],w[2005];
int dfs(int x){
    if (head[x]==-1) return 0;
    int sum=0;
    for (int i=head[x];i!=-1;i=next[i]){
        int t=dfs(i);
        sum+=t+1;
        for (int j=sum;j>=0;j--){//注意，一定要是降序
            for (int k=0;k<=t;k++)
                if (j-k-1>=0) f[x][j]=max(f[x][j],f[x][j-k-1]+f[i][k]);
        }
    }
    return sum;
}
int main(){
    scanf("%d%d",&n,&m);
    memset(f,0,sizeof(f));
    memset(head,-1,sizeof(head));
    for (int i=1;i<=n;i++){
        int a;
        scanf("%d%d",&a,&w[i]);
        next[i]=head[a];
        head[a]=i;
    }
    for (int i=1;i<=n;i++) f[i][0]=w[i];
    f[0][0]=0;
    dfs(0);
    printf("%d",f[0][m]);
    return 0;
}
