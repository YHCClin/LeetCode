#include "Include_all.h"

using namespace std;

double findMedianSortedArrays(vector<int>& arrayA, vector<int>& arrayB)
{
    int m = arrayA.size();
    int n = arrayB.size();

    // 如果数组A的长度大等于数组B，则交换数组
    if(m > n)
    {
        vector<int> temp(arrayA);
        arrayA = arrayB;
        arrayB = temp;
        int tmp = m;
        m = n;
        n = m;
    }

    int start = 0;
    int end = m;
    int mid = (m + n + 1) / 2;
    while(start <= end)
    {
        int i = (start + end) / 2;
        int j = mid - i;
        if(i < end && arrayB[j-1] > arrayA[i])
        {
            // i 偏小了，需要右移
            start = i + 1;
        }
        else if (i > start && arrayA[i-1] > arrayB[j])
        {
            // i 偏大了，需要左移
            end = i - 1;
        }
        else
        {
            int maxLeft;
            if(i == 0)
            {
                maxLeft = arrayB[j - 1];
            }
            else if ( j == 0)
            {
                maxLeft = arrayA[i -1];
            }
            else
            {
                maxLeft = max(arrayA[i - 1], arrayB[j - 1]);
            }
            if( (m + n) % 2 == 1)
            {
                // 如果数组长度是奇数，中位数就是左半部分的最大值
                return maxLeft;
            }
            int minRight;
            if(i == m)
            {
                minRight = arrayB[j];
            }
            else if (j == n)
            {
                minRight = arrayA[i];
            }
            else
            {
                minRight = min(arrayB[j], arrayA[i]);
            }
            // 如果数组长度是偶数，取左侧最大值和右侧最小值的平均值
            return ( maxLeft + minRight ) / 2.0;
        }
    }
    return 0.0;
}

int main()
{
    vector<int> arrayA = {3,5,6,7,8,12,20};
    vector<int> arrayB = {1,10,17,18};
    cout << findMedianSortedArrays(arrayA, arrayB) << endl;
}