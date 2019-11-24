#include <bits/stdc++.h>
using namespace std;

// 快速排序在平均情况下时间复杂度为 O(nlog n)
// 最坏情况下(如待排序列有序)为 O(n^2)
// 要使得在最坏情况下时间复杂度为 O(nlog n)
// 容易看到，快速排序的性能取决于划分的 对称性
// 可以每次都将问题划分为相等规模的两个子问题
// 即 T(n) = 2T(n/2) + n
// 由主定理解得 T(n) = O(nlog n)
// 因此可以用一个算法选取当前序列的中位数将其作为主元(pivot)，将子问题划分为原问题的一半规模
// 这里我们选用 线性时间选择算法选取中位数

//-----------------------------------------------------------------------------------

// 简单快速排序算法

template<class Type>
int Partition(Type a[], int p, int r)
{
	int i = p, j = r+1;
	Type x = a[p]; // 确定主元
	// 划分
	while(true)
	{
		while(a[++i] < x && i < r); // 从左往右寻找比 x 大的元素
		while(a[--j] > x);			// 从右往左寻找比 x 小的元素
		if(i >= j)
			break;
		swap(a[i], a[j]);			// 交换
	}
	
	a[p] = a[j];					// j 最终停留在一个比 x 小的数上面
	a[j] = x;						// 将主元放到最终位置
	return j;						// 返回枢轴元素下标
}

template<class Type>
void QuickSort(Type a[], int p, int r)
{
	if(p < r)						// 递归出口，只有一个元素时
	{
		int q = Partition(a, p, r); // 得到划分位置
		QuickSort(a, p, q-1);		// 排序左子序列
		QuickSort(a, q+1, r);		// 排序右子序列
	}
}
//-----------------------------------------------------------------------------------

// 随机选择快速排序算法

// 随机选择快速排序算法在当数组还没有被划分时随机第从 a[p:r] 中选择主元作为划分基准
// 从而可以期望划分是较对称的
int Random(int p, int r)
{
	return (rand() % (r-p+1))+ p;	// 生成 [p,r] 区间内的随机整数
}

template<class Type>
int RandomizedPartition(Type a[], int p, int r)
{
	int i = Random(p, r);			// 产生一个属于 [p:r] 区间的随机数
	swap(a[i], a[p]);
	return Partition(a, p, r);		// 调用划分函数
}

template<class Type>
void RandomizedQuickSort(Type a[], int p, int r)
{
	if(p < r)
	{
		int q = RandomizedPartition(a, p, r);	// 随机划分
		RandomizedQuickSort(a, p, q-1);			// 排序左子序列
		RandomizedQuickSort(a, q+1, r);			// 排序右子序列
	}
}
//-----------------------------------------------------------------------------------
// 随机线性时间选择算法
// 由于RandomizedSelect中使用了RandomizedPartition产生的划分基准是随机的
// 在这个条件下可以证明，算法RandomizedSelect可以在 O(n) 的平均时间内找出n个输入的第 k 小元素
// 但其在最坏情况下的时间复杂度为 O(n^2),比如在找最小元素时(k=1),总是在最大元素处划分
template<class Type>
 Type RandomizedSelect(Type a[], int p, int r, int k)   // 返回第 k 小的数
 {
 	if(p == r)
 		return a[p];
 	int i = RandomizedPartition(a, p, r);				// 随机划分
 	int j = i - p + 1;										// 计算前半部分子序列长度
 	if(k <= j)											// 如果 j >= k ,说明第 k 小的元素在前半部分
 		return RandomizedSelect(a, p, i, k);
 	else												// 否则, 第 k 小的元素在右半部分
 		return RandomizedSelect(a, i+1, r, k-j);		// 从右半部分中寻找第 k - j 小的元素
 }

// 下面讨论一个最坏情况下可以在 O(n) 时间内找到第 k 小的元素的线性时间选择算法
/*
 *	1. 将 n 个元素划分成 n/5 个分组， 每组 5 个元素， 除可能有一个组不是 5 个元素外。用任意一种排序算法，
 *	   将每组中的元素排好序，并去除每组的中位数，共 n/5 个。
 *	2. 递归调用 Select 函数找出这 n/5 个元素的中位数。 如果 n/5 为偶数，就找他的两个中位数中较大的一个
 *	   然后以这个元素作为划分基准。
 */
void insertSort(int a[],  int p, int r)					// 插入排序
{	
	for (int i = p+1; i <= r; i++)
	{		
		for (int j = i - 1; j >= 0 && a[j + 1] < a[j]; j--)		
		{			
			swap(a[j], a[j + 1]);		
		}	
	} 
}

template<class Type>
Type Select(Type a[], int p, int r, int k)
{
	if(r - p < 75)
	{
		insertSort(a,p,r);								// 简单插入排序
		return a[p+k-1];								// 返回中位数
	}
	for(int i = 0; i <= (r-p-4)/5; ++i)
	{
		// 将 a[p + 5 * i] 至 a[p + 5 * i + 4] 的第三小元素与 a[p + i] 交换位置
		Type x = Select(a, p, p + (r-p-4)/5, (r-p-4)/10);	// 找出中位数中的中位数，r-p-4 即为 n-5
		int m = Partition(a, p, r, x) , j = i - p + 1;
		if(k <= j)
			return Select(a, p, m, k);
		else
			return Select(a, m+1, r, k-j);
	}
}

//-----------------------------------------------------------------------------
// 三路快速排序
template<class Type>
void QuickSort3Way(Type a[], int left, int right)
{
	if(left < right)
	{
		Type x = a[right];								// 取尾元素为主元(基准)

		// i 指向序列头元素的前一个元素(不存在)
		// j 指向序列尾元素
		// p 与 i 相同
		// q 与 j 相同
		int i = left - 1, j = right, p = left - 1, q = right;
		// 开始划分
		while(1)
		{
			while( a[++i] < x );							// 从左往右找大于x的元素
			while( a[--j] > x ) if( j == left ) break;		// 从右往左找小于x的元素
			
			if(i < j)										// i j 未交错
			{
				swap(a[i], a[j]);							// 交换
				if(a[i] == x) { p++; swap( a[p], a[i] ); }	// 将与主元相等的元素交换到两侧
				if(a[j] == x) { q--; swap( a[q], a[j] ); }
			}
			else break;										// i j 交错， i 为主元最终位置
		}
		swap(a[i], a[right]);								// 将主元交换到最终位置
		j = i - 1;
		i = i + 1;
		// 此时 p，q 指向两侧与主元相等元素的最内侧元素
		/*
			如下图：x 为主元
			
			x x x x x x x a d d t g e w x d i s e s x x x x
			            |             |   |         |
			            p             j   i         q

		 */
		for(int k = left;  k <= p; k++, j--) swap( a[k], a[j] );		// 将左侧相等元素交换到主元左边
		for(int k = right - 1; k >= q; k--, i++) swap( a[i], a[k] );	// 将右侧相等元素交换到主元右边
		// 一次划分结束
		
		QuickSort3Way(a, left,  j);
		QuickSort3Way(a, i, right);
	}
}

int main()
{
	int a[28] = {1,2,5,2,7,4,7,10,65,2,3,63,78,23,61,11,8,34,6,23,23,23,23,23,23,23,23,23};
	//RandomizedQuickSort(a,0,19);
	time_t start, end;
	start = clock();
	QuickSort3Way(a, 0, 28);
	end   = clock();
	cout << 1.0 * (end - start)/CLOCKS_PER_SEC << " s " << endl;
	for(int i = 0;i < 20;i++)
		cout << a[i] << " ";
	cout << endl;
}