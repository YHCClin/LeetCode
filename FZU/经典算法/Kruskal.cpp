#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    克鲁斯卡尔算法无向连通图的最小生成树
    数据结构： 并查集(AdjointSet)、图的邻接矩阵
*/

class Road {
    public:
        Road(int _a, int _b, int _w) : a(_a), b(_b), weight(_w) {}
        int a, b;           // 边的两端顶点编号
        int weight;         // 边权值
};

class MGraph {
    public:
        MGraph(vector<vector<int>>& edges){
            for(size_t i = 0;i < edges.size();i++)
            {
                for(size_t j = i+1;j < edges.size();j++)
                {
                   if(edges[i][j] != INT_MAX)
                   {
                       roads.push_back(Road(i, j, edges[i][j]));
                   }
                }
            }
            n  = edges.size();
            en = roads.size();
        }
        int n;               // 节点数
        int en;              // 边数
        vector<Road> roads;  // 边数组
};

bool Less(const Road &a, const Road &b)         // 排序比较函数
{
    return a.weight < b.weight;
}

int get_root(int a, vector<int>& ParantOf)      // 寻根函数
{
    while(ParantOf[a] != -1) a = ParantOf[a];
    return a;
}

int Kruskal(MGraph& M)                          // 克鲁斯卡尔算法
{
    vector<int> ParantOf(M.n, -1);              // 并查集数组
    int cost = 0;                               // 总费用
    sort(M.roads.begin(),M.roads.end(),Less);   // 按 weight 排序
    for(int i = 0;i < M.en;i++)                 // 遍历边数组
    {
        int a = get_root(M.roads[i].a, ParantOf);
        int b = get_root(M.roads[i].b, ParantOf);
        if( a != b )
        {
            ParantOf[a] = b;                    // 集合相并
            cost += M.roads[i].weight;          // 更新费用
        }
    }
    return cost;
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
    MGraph M(edges);
    cout << Kruskal(M) << endl;
    return 0;
}