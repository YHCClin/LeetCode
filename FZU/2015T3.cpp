#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/*  求强连通分量： Tarjan算法
    Tarjan 算法， 以Robert Tarjan的名字命名的算法
    该算法用来在线性时间内求解图的连通性问题
*/

class Ssc{
public:
    void Tarjan(int);
    Ssc(int n_, vector<vector<int>> &g) : n(n_) {         // InitializeMG
        graph = g;
        dfn = vector<int>(n,0);
        low = vector<int>(n,0);
        scc = vector<bool>(n,false);
        time = 0;
        sscnum = 0;
    }
    vector<vector<int>>   Sscs;     // 所有连通分量
    vector<vector<int>>  graph;     // 有向图的邻接矩阵
    int                      n;     // 顶点总数
    vector<int>  dfn;               // 时间戳数组
    vector<int>  low;               // 最小时间戳数组（能够追溯到的最早栈中节点时间戳）
    vector<bool> scc;               // 在栈内标记数组
    int         time,               // 时间
              sscnum;               // 连通分量数
    stack<int>           stk;       // 遍历栈
};



void Ssc::Tarjan(int root)
{
    if( dfn[root] ) return;                     // 访问过了，直接返回
    dfn[root] = low[root] = ++time;
    stk.push(root);                             // 入栈
    scc[root] = true;
    
    for(int v = 0;v < n;v++)                    // 遍历 root 所指节点
    {
        if(!dfn[v] && graph[root][v])           // v 还未被访问过
        {
            Tarjan(v);
            low[root] = min(low[root], low[v]);
        }
        else if(scc[v] && graph[root][v])       // 如果 v 还在栈内
        {
            low[root] = min(low[root], dfn[v]);
        }
    }

    if(low[root] == dfn[root])                  // 后代不能找到更浅的节点了
    {
        sscnum ++;                              // 记数
        vector<int> sc;                         // 保存当前连通分量
        while(true)                             // 依次退栈至 root
        {
            int x = stk.top();
            scc[x] = false;
            stk.pop();
            sc.push_back(x);
            if(x == root) break;
        }
        Sscs.push_back(sc);
    }
}


int main()
{
    vector<vector<int>> graph = {
        {0,1,1,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,1,1,0},
        {1,0,0,0,0,1},
        {0,0,0,0,0,1},
        {0,0,0,0,0,0},
    };
    Ssc S(6, graph);
    S.Tarjan(0);
    int index = 1;
    for(auto i : S.Sscs)
    {
        cout << "SSC (" << index++ << ") : "; 
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "The Number of SSC : " << S.sscnum << endl;
    return 0;
}