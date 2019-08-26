#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1,ListNode* l2)
{
	if(l1==NULL)
	{
		return l2;
	}
	else if(l2==NULL)
	{
		return l1;
	}
	else if(l1->val < l2->val)
	{
		//l1的头元素较小，将l1的头元素添加到结果中
		l1->next = mergeTwoLists(l1->next,l2);
		return l1;
	}
	else
	{
		//l2的头元素较小或等于l1头元素，将l2的头元素添加到结果中
		l2->next = mergeTwoLists(l1,l2->next);
		return l2;
	}
}

int main()
{
	ListNode *l1 = (ListNode*)malloc(sizeof(ListNode));
	ListNode *l11 = (ListNode*)malloc(sizeof(ListNode));
	ListNode *l12 = (ListNode*)malloc(sizeof(ListNode));

	ListNode *l2 = (ListNode*)malloc(sizeof(ListNode));
	ListNode *l21 = (ListNode*)malloc(sizeof(ListNode));
	ListNode *l22 = (ListNode*)malloc(sizeof(ListNode));

	l1->val = 1;
	l1->next = l11;
	l11->val = 2;
	l11->next = l12;
	l12->val = 4;
	l12->next = NULL;

	l2->val = 1;
	l2->next = l21;
	l21->val = 3;
	l21->next = l22;
	l22->val = 4;
	l22->next = NULL;

	ListNode *ans = mergeTwoLists(l1,l2);
	for(ListNode *p = ans;p != NULL;p=p->next)
	{
		cout<< p->val;
		if(p->next != NULL)
			cout << "->";
	}
	cout << endl;
	return 0;
}