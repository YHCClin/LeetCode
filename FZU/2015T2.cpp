#include <bits/stdc++.h>
using namespace std;

/*
    算法思想： 借鉴三路划分快速排序的划分算法
*/

void SpecialSort(vector<int> &a)
{
    int n = a.size();
    int i = -1, j = n, p = i, q = j;
    int x = 1;
	// 开始划分
	while(1)
	{
		while( a[++i] % 3 < x );							// 从左往右找大于x的元素
		while( a[--j] % 3 > x ) if( j == 0 ) break;		// 从右往左找小于x的元素
		
		if(i < j)										// i j 未交错
		{
			swap(a[i], a[j]);							// 交换
			if(a[i] % 3 == x) { p++; swap( a[p], a[i] ); }	// 将与主元相等的元素交换到两侧
			if(a[j] % 3 == x) { q--; swap( a[q], a[j] ); }
		}
		else break;										// i j 交错， i 为主元最终位置
	}
	//swap(a[i], a[right]);								// 将主元交换到最终位置
	j = i - 1;
	i = i + 1;
	// 此时 p，q 指向两侧与主元相等元素的最内侧元素
	/*
		如下图：x 为主元
		
		x x x x x x x a d d t g e w x d i s e s x x x x
		            |             |   |         |
		            p             j   i         q
	 */
	for(int k = 0;  k <= p; k++, j--) swap( a[k], a[j] );		// 将左侧相等元素交换到主元左边
	for(int k = n - 1; k >= q; k--, i++) swap( a[i], a[k] );	// 将右侧相等元素交换到主元右边
	// 一次划分结束
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    SpecialSort(arr);
    for(auto i : arr)
        cout << i << " ";
    cout << endl;
}