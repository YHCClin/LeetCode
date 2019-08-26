#include "Include_all.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head,int x)
{
	//给个头结点
	ListNode *realhead = new ListNode(-1);
	realhead -> next = head;
	//两个链表的头结点
	ListNode *less = new ListNode(-1);
	ListNode *ltail = less; //less链表的尾指针
	ListNode *more = new ListNode(-1);
	ListNode *mtail = more; //more链表的尾指针
	
	//用来指向刚摘下的结点
	ListNode *r;

	while(realhead -> next)
	{
		if(realhead -> next -> val < x)
		{
			//摘下结点
			r = realhead -> next;
			realhead -> next = r -> next;
			r -> next = NULL;
			//插入链表
			ltail -> next = r;
			ltail = ltail -> next;
		}
		else
		{
			r = realhead -> next;
			realhead -> next = r -> next;
			r -> next = NULL;

			mtail -> next = r;
			mtail = mtail -> next;
		}
	}
	ltail -> next = more -> next;
	head = less -> next;
	return head;
}

int main()
{
	ListNode *head = new ListNode(1);
	ListNode *head1 = new ListNode(4);
	ListNode *head2 = new ListNode(3);
	ListNode *head3 = new ListNode(2);
	ListNode *head4 = new ListNode(5);
	ListNode *head5 = new ListNode(2);
	

	head -> next = head1;
	head1 -> next = head2;
	head2 -> next = head3;
	head3 -> next = head4;
	head4 -> next = head5;
	head5 -> next = NULL;
	ListNode *p = partition(head,3);
	while(p)
	{
		if(p -> next)
			cout << p -> val << "->";
		else
			cout << p -> val << endl;

		p = p -> next;
	}
}