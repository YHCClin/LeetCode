#include "Include_all.h"
using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* removeZeroSumSublists(ListNode* head) {
		//建立前缀和与节点的映射
        unordered_map<int, ListNode*> prefixSum;
        // 因为头结点也有可能会被消掉，所以这里加一个虚拟节点作为头结点
        ListNode* dummy = new ListNode(0), *p = dummy;
        dummy->next = head;
        
        prefixSum[0] = p;
        int cur = 0;
        while (p = p->next) {
            cur += p->val;
            if (prefixSum.find(cur) != prefixSum.end()/*如果出现相同（之前出现过）的前缀和*/) {
                prefixSum[cur]->next = p->next;       /*就让之前出现过的前缀和对应的节点的next指针指向当前节点的下一个节点*/
            } else { /*否者，建立当前前缀和与节点的映射关系*/
                prefixSum[cur] = p;
            }
        }
        
        return dummy->next;//返回虚头节点的next指针（实际头节点）
    }

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* head1 = new ListNode(2);
	ListNode* head2 = new ListNode(-3);
	ListNode* head3 = new ListNode(3);
	ListNode* head4 = new ListNode(1);
	//ListNode* head5 = new ListNode(1);

	head -> next = head1;
	head1 -> next = head2;
	head2 -> next = head3;
	head3 -> next = head4;

	head = removeZeroSumSublists(head);
	ListNode *p=head;
	/*
	for(auto i : list_)
	{
		cout << i << " ";
	}
	cout << endl;
	*/
	while(p)
	{
		if(p -> next != NULL)
			cout << p -> val << " --> ";
		else 
			cout << p -> val << endl;
		p = p -> next;
	}
	return 0;
}