#include <bits/stdc++.h>
using namespace std;

/*
    算法思路：
        首先要明确的是纸牌的底数是可见的，否则应该无解吧？
        贪心，两摞纸牌一共有四张备选牌，Alice 每次只拿最大的那张；
        将两摞纸牌建模成两个数组
        每次 Alice 选最大之后 Bob 选最小的，尽量把较大的牌留给 Alice 即可
    算法实现：
        分别用双指针指向两个数组的头尾（牌堆的上下），由外向内选取纸牌
*/

// 选最大牌
int *maxPointto(int *i, int *j, int *p, int *q)
{
    int *max1, *max2;
    if(*i > *j) max1 = i;
    else max1 = j;
    if(*p > *q) max2 = p;
    else max2 = q;
    return *max1 > *max2 ? max1 : max2;
}
// 选最小牌

int *minPointto(int *i, int *j, int *p, int *q)
{
    int *min1, *min2;
    if(*i < *j) min1 = i;
    else min1 = j;
    if(*p < *q) min2 = p;
    else min2 = q;
    return *min1 < *min2 ? min1 : min2;
}


int maxScore(int *pokers_1, int *pokers_2, int n)
{
    int *i = pokers_1, *j = pokers_1 + n - 1;
    int *p = pokers_2, *q = pokers_2 + n - 1;
    int Alice = 0;
    while(i < j && p < q)
    {
        // Alice 先，先挑最大牌
        int *_max = maxPointto(i, j, p, q);
        Alice += *_max;
        if(_max == i) i++;
        else if(_max == j) j--;
        else if(_max == p) p++;
        else if(_max == q) q--;

        // Bob 再选最小值
        int *_min = minPointto(i, j, p, q);
        if(_min == i) i++;
        else if(_min == j) j--;
        else if(_min == p) p++;
        else if(_min == q) q--;
    }
    // 剩下的牌
    while(i < j)
    {
        int *_max = *i > *j ? i : j;
        Alice += *_max;
        if(_max == i) i++;
        else if(_max == j) j--;

        int *_min = *i < *j ? i : j;
        if(_min == i) i++;
        else if(_min == j) j--;
    }
    while(p < q)
    {
        int *_max = *p > *q ? p : q;
        Alice += *_max;
        if(_max == p) p++;
        else if(_max == q) q--;

        int *_min = *p < *q ? p : q;
        if(_min == p) p++;
        else if(_min == q) q--;
    }

    return Alice;
}

int main()
{
    int pokers_1[3] = {1,2,3};
    int pokers_2[3] = {2,3,4};
    cout << "Alice can get : " << maxScore(pokers_1, pokers_2, 3) << endl; // Alice can get : 10
}

// 这么简单的思路写成了一坨屎， 太多重复代码, 也许用优先级队列会比较好实现