#include <bits/stdc++.h>
using namespace std;

/*
	将数组排序后再建立单链表
 */

// 链表节点定义
class ListNode{
public:
	int val;
	ListNode *next;
	ListNode(int val_) : val(val_), next(NULL) {}
};
// 快速排序
int _Partition(vector<int> &a, int p, int r)
{
	int i = p, j = r+1;
	int x = a[p]; // 确定主元
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

void QuickSort(vector<int> &a, int p, int r)
{
	if(p < r)
	{
		int q = _Partition(a, p, r);

		QuickSort(a, p, q-1);
		QuickSort(a, q+1, r);
	}
}

ListNode* creatList(vector<int>& arr)
{
	ListNode *h = new ListNode(-1);
	QuickSort(arr, 0, arr.size()-1);
	ListNode *cur = h;
	for (int i = 0; i < arr.size();i++)
	{
		ListNode *newNode = new ListNode(arr[i]);
		cur -> next = newNode;
		cur = cur -> next;
	}
	return h->next;
}

int main()
{
	vector<int> arr = {1,2,3,4,45,5,6};
	ListNode *head = creatList(arr);
	ListNode *p = head;
	while(p)
	{
		if(p -> next)
			cout << p -> val << " --> ";
		else cout << p -> val;
		p = p -> next;
	}
	cout << endl;
}