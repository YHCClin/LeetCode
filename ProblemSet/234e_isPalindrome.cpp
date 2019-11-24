#include "Include_all.h"
using namespace std;

struct ListNode
{	
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head)
{
	//回文链表，即正序与反序遍历序列相同
	if(head == NULL) return true;
	ListNode *p = head;
	stack<int> sta;
	int item;
	while(p)
	{
		sta.push(p -> val);
		p = p -> next;
	}
	p = head;
	while(p)
	{
		if(!(sta.empty()))
		{
			item = sta.top();
			sta.pop();
		}
		if(item != p -> val)
			return false;
		p = p -> next;
	}
	return true;
}

int main()
{
	ListNode *head = new ListNode(1);
	ListNode *head1 = new ListNode(2);
	ListNode *head2 = new ListNode(2);
	ListNode *head3 = new ListNode(1);

	head -> next = head1;
	head1 -> next = head2;
	head2 -> next = head3;
	head3 -> next = NULL;
	
	cout << isPalindrome(head) << endl;

	return 0;
}