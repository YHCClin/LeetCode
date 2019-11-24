#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

class VNode {
    public:
        VNode(int _data, int ind) : num(0), indegree(ind) {}
        int       num;               // 编号
        int  indegree;               // 入度
};

class MGraph {
    public:
        MGraph(vector<vector<int>>& _edges) : edges(_edges) {
            n = edges.size();
            inDegree = vector<int>(n, 0);
            for(int i = 0;i < n;i ++)
            {
                for(int j = 0;j < n;j ++)
                {
                    if(edges[i][j] != 0)
                        inDegree[j]++;
                }
            }
        }
        vector<vector<int>> edges;               // 邻接矩阵
        int                     n;               // 节点数
        vector<int> inDegree;                    // 顶点入度数组
};

bool TopSort(MGraph M)
{
    vector<int> Series;
    stack<int> stk;                           // 遍历栈
    int n = 0;                                  // 记数
    for(int i = 0; i < M.n;i++)
    {
        if(M.inDegree[i] == 0)
            stk.push(i);
    }
    while(!stk.empty())
    {
    //    cout << "-" << endl;
        int v = stk.top();
        stk.pop();
        Series.push_back(v);
        ++n;
        for(int i = 0; i < M.n; i++)
        {
            if(M.edges[v][i] != 0)
                (M.inDegree[i])--;
            if(M.inDegree[i] == 0)
                stk.push(i);
            for(auto j : M.inDegree)
                cout << j << " ";
                cout << endl;
        }
    }
    if(n == M.n)
    {
        for(auto i : Series)
            cout << i << "  ";
        cout << endl;
        return true;
    }
    return false;
}

int main()
{
    vector<vector<int>> edges = {
        {0,1,1,1,0,0,0},
        {0,0,1,0,1,0,0},
        {0,0,0,0,1,1,0},
        {0,0,0,0,0,1,0},
        {0,0,0,0,0,0,1},
        {0,0,0,0,1,0,1},
        {0,0,0,0,0,0,0},
    };
    MGraph M(edges);
    cout << TopSort(M) << endl;
    return 0;
}