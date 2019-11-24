#include "Include_all.h"
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* detectCycle(ListNode *head)
{
	if(head == NULL) return NULL;
	ListNode *p = head;
	vector<ListNode*> set;
	while(p != NULL)
	{
		if(find(set.begin(),set.end(),p)==set.end())
		{
			set.push_back(p);
			p = p -> next;
		}
		else
			return p;
	}
	return NULL;
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

	cout << detectCycle(h) -> val << endl; 
	return 0;
}

/*
执行用时 :176 ms, 在所有 C++ 提交中击败了5.42%的用户
内存消耗 :10.4 MB, 在所有 C++ 提交中击败了13.35%的用户
*/