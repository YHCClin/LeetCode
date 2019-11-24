#include "Include_all.h"
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head)
{
	if(head == NULL) return head;
	
	ListNode *p = head -> next;
	head -> next = NULL;
	ListNode *q;
	while(p)
	{
		q = p -> next;
		p -> next = head;
		head = p;
		p = q;
	}
	return head;
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

	head = reverseList(head);

	ListNode *p = head;
	while(p)
	{
		cout << p -> val <<" ";
		p = p -> next;
	}
	cout << endl;
	return 0;
}

/*
8 ms
, 在所有 C++ 提交中击败了
99.45%
的用户
*/