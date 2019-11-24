#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//generate test data
void generatList(vector<ListNode*>& lists,vector<vector<int>>& list)
{
	if(list.size()!=lists.size()) return;
	for(int i = 0; i < lists.size();i++)
	{
		ListNode* p = lists[i];
		for(int j = 0; j < list[i].size();j++)
		{
			if(p == NULL) { lists[i] = new ListNode(list[i][j]); p = lists[i];}
			else
			{
				p -> next = new ListNode(list[i][j]);
				p = p -> next;
			}
		}
		p -> next = NULL;
	}
}
/*----------------------------------------------------------------
算法思想：
	将当前所有表头结点推入最小堆（优先级队列）中，每次pop一个最小的并更
	新（push）进一个新的头节点，直到堆为空。
----------------------------------------------------------------*/

ListNode* mergeKLists(vector<ListNode*>& lists)
{
	//定义优先级队列，对pair默认对第一个元素按从小到大排序（大顶堆）
	//因此push进队列时可将对应链表节点的val值取相反数，输出时还原，间接实现了小顶堆
	priority_queue<pair<int,int>,vector<pair<int,int>>> Q;

	//初始化优先级队列，将lists中的元素下标与
	for(int i=0;i<lists.size();i++)
	{
		if(lists[i] != NULL)
		{
			Q.push(make_pair(-lists[i]->val,i));
		}
	}
	//定义头节点
	ListNode *head = new ListNode(-1),*p = head;
	while(!Q.empty())
	{
		//实现摘下链表头节点的操作
		p -> next = new ListNode(-Q.top().first);
		p = p -> next;
		int i = Q.top().second;
		ListNode *r = lists[Q.top().second];
		lists[Q.top().second] = lists[Q.top().second] -> next;
		delete(r);
		Q.pop();
		if(lists[i]!=NULL)
			Q.push(make_pair(-lists[i]->val, i));
	}
	return head -> next;
}

int main()
{
	vector<ListNode*> lists(3);
	vector<vector<int>> list = {{1,4,5},{1,3,4},{2,6}};
	generatList(lists,list);
	ListNode* head = mergeKLists(lists);
	ListNode *p = head;
	while(p)
	{
		cout << p -> val << endl;
		p = p -> next;
	}
	return 0;
}