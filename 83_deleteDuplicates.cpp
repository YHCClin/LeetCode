#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//一般的方法(双指针法)：
ListNode* deletDuplicates(ListNode* head)
{
	if(head==NULL || head->next==NULL) return head;
	int temp = head->val;
	ListNode* p = head;
	ListNode* cur = p -> next;
	while(cur)
	{
		if(cur -> val == temp)
		{
			p -> next = cur -> next;
			cur = p -> next;
		}
		else
		{
			temp = cur -> val;
			p = cur;
			cur = p -> next;
		}
	}
	return head;
}
//更为简单的方法(单指针法)：
ListNode* deletDuplicates_simple(ListNode* head)
{
	if(head==NULL || head->next==NULL) return head;
	ListNode* p = head;
	while(p->next)
	{
		if(p->next->val == p->val)
		{
			p->next = p->next->next;
		}
		else
		{
			p = p -> next;
		}
	}
	return head;
}

int main()
{

	return 0;
}