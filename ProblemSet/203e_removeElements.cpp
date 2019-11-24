#include "Include_all.h"
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x) ,next(NULL) {}
};

//附加头结点，让逻辑变得清晰
ListNode* removeElements(ListNode* head,int val)
{
	ListNode *h = new ListNode(-1);
	h -> next = head;
	ListNode *p = h;
	ListNode *q = h -> next;

	while(q != NULL)
	{
		if(q -> val == val)
		{
			p -> next = q -> next;
			q = p -> next;
		}
		else
		{
			p = p -> next;
			q = p -> next;
		}
	}
	return h->next;
}

int main()
{
	ListNode *head = new ListNode(6);
	ListNode *head1 = new ListNode(1);
	ListNode *head2 = new ListNode(2);
	ListNode *head3 = new ListNode(6);
	ListNode *head4 = new ListNode(3);
	ListNode *head5 = new ListNode(4);
	ListNode *head6 = new ListNode(5);
	ListNode *head7 = new ListNode(6);

	head -> next = head1;
	head1 -> next = head2;
	head2 -> next = head3;
	head3 -> next = head4;
	head4 -> next = head5;
	head5 -> next = head6;
	head6 -> next = head7;
	head7 -> next = NULL;






	ListNode *p = removeElements(head,6);
	while(p)
	{
		if(p -> next)
		{
			cout << p->val << " -> ";
		}
		else
			cout << p->val << endl;
		p = p->next;
	}
	return 0;
}