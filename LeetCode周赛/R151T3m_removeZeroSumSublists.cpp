#include "Include_all.h"
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

	inline int SumInIJ(vector<int>& nums,int i,int j)
	{
		int sum = 0;
		if(i==j)
			return nums[i];
		else
		{
			for(;i <= j;++i)
			{
				if(nums[i]!=INT_MAX)
					sum += nums[i];
			}
		}
		return sum;
	}
	
    ListNode* removeZeroSumSublists(ListNode* head) {
    	vector<int> list_; 
        ListNode *p = head;
        while(p)
        {
        	list_.push_back(p->val);
        	p = p -> next;
        }
        int i = 0,j = 0;
        while(i <= j && j < list_.size())
        {
        	if(j < list_.size() && list_[j]>0)
        	{
        		j++;
        		if(j < list_.size() && SumInIJ(list_,i,j)==0)
        		{
        			while(i <= j)
        			{
        				list_[i] = INT_MAX;
        				i++;
        			}
        			j = j+1;
        			i = 0;
        		}
        	}
        	else
        	{
        		i++;
        		if(j < SumInIJ(list_,i,j)==0)
        		{
        			while(i <= j)
        			{
        				list_[i] = INT_MAX;
        				i++;
        			}
        			j = j+1;
        			i=0;
        		}
        	}
        }
        //建立链表
        ListNode *h = new ListNode(0);
        ListNode *tail = h;
        for(int k = 0;k < list_.size();k++)
        {
        	if(list_[k] != INT_MAX)
        	{
        		ListNode *r = new ListNode(list_[k]);
        		tail -> next = r;
        		tail = tail -> next;
        	}
        }
        return h->next;
    }



int main()
{
	ListNode* head = new ListNode(1);
	ListNode* head1 = new ListNode(2);
	ListNode* head2 = new ListNode(3);
	ListNode* head3 = new ListNode(-3);
	ListNode* head4 = new ListNode(-2);
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