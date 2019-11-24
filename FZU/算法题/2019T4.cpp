#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

/*
    合并土堆
    算法思路：
            不难发现当合并路径为一棵霍夫曼二叉树时可得最小的力气花费
            故可每次选取两个最小重量的堆进行合并
            用优先级队列实现这一思想
*/

int minPowerCost(vector<int>& piles)
{
    int n = piles.size();
    priority_queue<int, vector<int>, greater<int>> Q;
    // 初始化
    for(auto i : piles) Q.push(i);

    while(Q.size() >= 2)
    {
        int p1 = Q.top();
        Q.pop();
        int p2 = Q.top();
        Q.pop();
        Q.push(p1 + p2);
    }
    int cost = 0;
    if(Q.size() == 1)
    {
        cost = Q.top();
        Q.pop();
    }
    return cost;
}

int main()
{
    vector<int> piles = {2,3,5,2,3,6,3,5};
    cout << minPowerCost(piles) << endl;
}