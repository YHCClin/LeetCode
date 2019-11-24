#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


/*
    最近的 k 个石墩：
        双指针 + 贪心
    算法思路：
        将 n 个石墩建模为一个一维数组，数组中 distance[i] 表示编号为 i 的石墩距离最左侧石墩的距离
        因此不难发现，石墩 i 与 j 的距离 dist = | distance[j] - distance[i] |
*/

vector<int> k_proximalStone(vector<int>& distance, int a, int k)
{
    // k < n
    int n = distance.size();
    vector<int> kStones;
    int i = 1, j = n-2;
    if(a == 0) { while(i++ <= k) kStones.push_back(i); return kStones; }
    if(a == n-1) {while(k--) kStones.push_back(j--); return kStones; }

    int left = a - 1, right = a + 1;
    while(left >= 0 && right < n)
    {
        int dis_l = distance[a] - distance[left];
        int dis_r = distance[right] - distance[a];
        if(dis_l < dis_r){ kStones.push_back(left--); k--;}
        else { kStones.push_back(right++); k--;}
    }
    while(k > 0 && left >= 0) {kStones.push_back(left--); k--;}
    while(k > 0 && right < n) {kStones.push_back(right++); k--;}
    return kStones;
}

int main()
{
    vector<int> distance = {1,2,3,4,7,12,18,20};
    /*
            0*1*2*3**4*****5******6**7   ans = {4,6,7,3,2};
    */
    vector<int> ans(k_proximalStone(distance, 5, 5));
    for(auto i : ans)
        cout << i << " ";
    cout << endl;
}