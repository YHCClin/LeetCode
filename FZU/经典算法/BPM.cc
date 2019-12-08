#include<stdio.h>
#include<string.h>
int n1, n2, m, ans;
int result[101];//记录V2中的点匹配的点的编号
bool state[101];//记录V2中的每个点是否被搜索过
bool data[101][101];//邻接矩阵true代表有边相连
void init()
{
    int t1, t2;
    memset(data, 0, sizeof(data));
    memset(result, 0, sizeof(result));
    ans = 0;
    scanf("%d%d%d", &n1, &n2, &m);
 
    for(int i = 1; i <= m; i++)
    {
        scanf("%d%d", &t1, &t2);
        data[t1][t2] = true;
    }
 
    return;
}
bool match(int a)
{
    for(int i = 1; i <= n2; i++)
    {
        if(data[a][i] == 1 && !state[i]) //如果节点i与a相邻并且未被查找过
        {
            state[i] = true; //标记i为已查找过
 
            if(result[i] == 0 //如果i未在前一个匹配M中
                || match(result[i])) //i在匹配M中，但是从与i相邻的节点出发可以有增广路
            {
                result[i] = a; //记录查找成功记录
                 
                return true;//返回查找成功
            }
        }
    }
 
    return false;
}
int main()
{
    init();
 
    for(int i = 1; i <= n1; i++)
    {
        memset(state, 0, sizeof(state)); //清空上次搜索时的标记
        if(match(i))
        {
            ans++;    //从节点i尝试扩展
        }
    }
 
    printf("%d\n", ans);
    return 0;
}