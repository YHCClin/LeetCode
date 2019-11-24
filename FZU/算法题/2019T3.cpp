#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
    连接所有岛屿
    算法思路：
        图的最小生成树问题，可使用 Prim 或者 Kruskal 算法
        这里使用 Prim 算法
*/

class MGraph {
    public:
        MGraph(vector<vector<int>>& es, int n_) : edges(es), n(n_) {}
        vector<vector<int>> edges;      // 边表
        int                     n;      // 顶点数
};

int Prim(MGraph &g, int v0)
{
    int lowcost[g.n], vset[g.n], v;
    int i, j, k, min_;
    v = v0;
    for(i = 0;i < g.n;++i)                  // 初始化
    {
        lowcost[i] = g.edges[v0][i];
        vset[i] = 0;
    }

    vset[v0] = 1;                           // v0 并入生成树中
    int Cost = 0;                           // 总费用
    for(i = 0;i < g.n-1;++i)
    {
        min_ = INT_MAX;
        for(j = 0;j < g.n;++j)
            if(vset[j] == 0 && lowcost[j] < min_)
            {
                min_ = lowcost[j];
                k = j;                      // k 指向刚并入的节点
            }
        vset[k] = 1;                        // k 并入生成树
        v = k;
        Cost += min_;                        // 更新费用

        for(j = 0;j < g.n;++j)              // 更新 lowcost 数组
        {
            if(vset[j] == 0 && g.edges[v][j] < lowcost[j])
            {
                lowcost[j] = g.edges[v][j];
            }
        }
    }
    return Cost;
}

int main()
{
    vector<vector<int>> edges = {
        {INT_MAX,5,1,2,INT_MAX},
        {5,INT_MAX,3,INT_MAX,4},
        {1, 3, INT_MAX,  6,  2},
        {2,INT_MAX,6,INT_MAX,3},
        {INT_MAX,4,2,3,INT_MAX},  
    };
    MGraph Mg(edges,5);
    cout << Prim(Mg, 0) << endl;

}