#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef long long ll; 
int a[20]; 
ll dp[20][10][10]; //不同题目状态不同。
ll dfs(int pos,/*state变量*/int i, int j,bool lead/*前导零*/,bool limit/*数字上界变量*/)//不是每个题都要判断前导零。
{
    //递归边界，既然是按位列举，最低位是0，那么pos==-1说明这个数我列举完了。
    if(pos==-1) return 1; /*这里一般返回1，表示你列举的这个数是合法的，那么这里就需要你在列举时必须每一位都要满足题目条件，也就是说当前列举到pos位，一定要保证前面已经列举的数字是合法的。 不过具体题目不同或者写法不同的话不一定要返回1 */ 
    //第二个就是记忆化(在此前可能不同题目还能有一些剪枝)
    if(!limit && !lead && dp[pos][i][j]!=-1) return dp[pos][i][j];
    /*常规写法都是在没有限制的条件记忆化，这里与下面记录状态是对应，具体为什么是有条件的记忆化后面会讲*/
    int up=limit ? a[pos]:9;//根据limit判断列举的上界up;这个的例子前面用213讲过了。
    ll ans=0;
    //开始计数。
    for(int c=0;c<=up;c++)//行举，然后把不同情况的个数加到ans就可以了。
    {
        if((!c)&&lead) ans+=dfs(pos-1,i,j/*状态转移*/,lead && c==0,limit && c==a[pos]);
        //有前导0但当前位不是前导0，当前位就是最高位
		else if(c&&lead) ans+=dfs(pos-1,c,j/*状态转移*/,lead && c==0,limit && c==a[pos]);
		else if(c == i || c == j) ans+=dfs(pos-1,i,j/*状态转移*/,lead && c==0,limit && c==a[pos]); //最后两个变量传参都是这样写的。
        /*这里还算比较灵活，不过做几个题就觉得这里也是套路了。 
        大概就是说，我当前数位列举的数是i，然后根据题目的约束条件分类讨论。 
        去计算不同情况下的个数，还有要根据state变量来保证i的合法性，比如题目。 
        要求数字上不能有62连续出现，那么就是state就是要储存前一位pre，然后分类， 
        前一位如果是6那么这意味就不能是2，这里一定要储存列举的这个数是合法*/
    }
    //计算完，记录状态。
    if(!limit && !lead) dp[pos][i][j]=ans; 
    /*这里对应的记忆化，在一定条件下时记录，保证一致性，当然如果约束条件不需要考虑lead，这里就是lead就完全不用考虑了*/
    return ans;
}  
ll solve(ll x)
{  
    int pos=0;
    while(x)//把数字都分解出来。
    {
        a[pos++]=x%10; //个人老是喜欢编号为[0，pos)，看不惯的就按自己习惯来，反正注意数字边界就行。
        x/=10;  
    }
    ll ans = 0;
    for(int i = 0;i < 10;i++)
        for(int j = 0;j < 10;j++)
            ans += dfs(pos-1/*从最高位开始列举*/,/*一系列状态 */0,0, true,true); //刚开始最高位都是有限制并且有前导零的，显然比最高位还要高的一位视为0嘛。
    return ans;
} 
int main()
{  
    ll n;
    scanf("%lld",&n);
    {  
        //初始化dp阵列为-1，这里还有更加优美的优化，后面讲。
        printf("%lld\n",solve(n));
    }
    getchar();
}  