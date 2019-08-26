#include "Include_all.h"
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
	if(head == NULL) return false;

	//定义两个结点指针，一个快一个慢
	ListNode *quik = head->next;
	ListNode *slow = head;

	while(quik != NULL && quik != slow)
	{
		quik = quik -> next;
		//细化表尾判断
		if(quik == NULL) return false;
		quik = quik -> next;
		slow = slow -> next;
	}
	if(quik == slow)
		return true;
	return false;
}

int main()
{
	ListNode *h = new ListNode(3);
	ListNode *h1 = new ListNode(2);
	ListNode *h2 = new ListNode(0);
	ListNode *h3 = new ListNode(-4);

	h -> next = h1;
	h1 -> next = h2;
	h2 -> next = h3;
	h3 -> next = h1;

	cout << hasCycle(h) << endl;
	return 0;
}

