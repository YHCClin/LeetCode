#include "Include_all.h"
using namespace std;

typedef struct NODE {
		int val;
		NODE *next;
		NODE(int val_) : val(val_), next(NULL) {}
	}node;

class MyLinkedList {
public:
	NODE *Head = NULL;
    /** Initialize your data structure here. */
    MyLinkedList() {
    	Head = new NODE(0);
    	tail = Head;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
    	if(index < 0 || index > Head->val - 1) return -1;
    	NODE *p = Head;
    	while(index >= 0)
    	{
    		p = p->next;
    		index--;
    	}
        return p -> val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
    	Head -> val += 1;
        NODE *newNode = new NODE(val);
        newNode -> next = Head -> next;
        Head -> next = newNode;
        setTail();
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Head -> val += 1;
        NODE *newNode = new NODE(val);
        tail -> next = newNode;
        tail = newNode;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index < 0 || index > Head->val-1 ) return;
        Head -> val += 1;
        NODE *p = Head;
        while(index > 0)
        {
        	p = p -> next;
        	index--;
        }
  		NODE *newNode = new NODE(val);
  		newNode -> next = p->next;
  		p -> next = newNode;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
    	if(index < 0 || index > Head->val - 1 ) return;
        NODE *p = Head;
        while(index > 0)
        {
        	p = p -> next;
        	index--;
        }
        p -> next = p -> next -> next;
        setTail();
    }
    void setTail()
    {
    	while(tail->next != NULL)
    	{
    		tail = tail->next;
    	}
    }
private:
	NODE *tail = NULL;
};

class ListsNode
{
public:
    int val;
    ListsNode* next;
    ListsNode* pre;
    ListsNode(int v, ListsNode* n, ListsNode* p):val(v),next(n),pre(p){}
};


class MyLinkedList {
public:
    ListsNode* root;
    ListsNode* trail;
    int size;
        
    /** Initialize your data structure here. */
    MyLinkedList() {
        root=nullptr;
        trail=nullptr;
        size=0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int temp=0;
        ListsNode* cur=root;
        while(cur!=nullptr)
        {
            if(temp==index)
            {
                return cur->val;
            }
            cur=cur->next;
            temp++;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if(root!=nullptr)
        {
            ListsNode* newNode=new ListsNode(val, root, nullptr);
            root->pre=newNode;
            root=newNode;         
        }
        else
        {
            root=new ListsNode(val, nullptr,nullptr);
            trail=root;
        }
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(trail!=nullptr)
        {
            ListsNode* newNode = new ListsNode(val, nullptr, trail);
            trail->next=newNode;
            trail=newNode;
        }
        else
        {
            trail=new ListsNode(val, nullptr, nullptr);
            root=trail;
        }
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index<=0)
        {
            addAtHead(val);
            return;
        }
        if(index==size)
        {
            addAtTail(val);
            return;
        }
       
        int temp=0;
        ListsNode* pre=nullptr;
        ListsNode* cur=root;
        while(cur!=nullptr)
        {
            if(temp==index)
            {
                ListsNode* newNode=new ListsNode(val, cur, pre);
                if(pre!=nullptr)
                {
                    pre->next=newNode;
                }
                cur->pre=newNode;
                size++;
                return;
            }
            pre=cur;
            cur=cur->next;
            temp++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        int temp=0;
        ListsNode* pre=nullptr;
        ListsNode* cur=root;
        if(index==0)
        {
            ListsNode* old=root;
            root=root->next;
            if(root!=nullptr)
            {
                root->pre=nullptr;
            }
            delete old;
            size--;
            return;
        }
        if(index==size-1)
        {
            ListsNode* old=trail;
            trail=trail->pre;
            if(trail!=nullptr)
            {
                trail->next=nullptr;
            }
            delete old;
            size--;
            return ;
        }
        while(cur!=nullptr)
        {
            if(temp==index)
            {
                ListsNode* old=cur;
                if(pre!=nullptr)
                {
                    pre->next=cur->next;
                }
                if(cur->next!=nullptr)
                {
                    cur->next->pre=pre;
                }
                delete old;
                size--;
                return;
            }
            pre=cur;
            cur=cur->next;
            temp++;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
/*
["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead",
	"addAtTail","get","addAtHead","addAtIndex","addAtHead"]
[[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]
*/
int main()
{
	/*
	MyLinkedList* obj = new MyLinkedList();
	int param_1 = obj->get(2);
	obj->addAtHead(1);
	obj->addAtTail(2);
	obj->addAtIndex(1,3);
	obj->deleteAtIndex(2);
	*/
	MyLinkedList* linkedList = new MyLinkedList();
	linkedList->addAtHead(7);
	linkedList->addAtHead(2);
	linkedList->addAtHead(1);
	linkedList->addAtIndex(3,0);
	linkedList->deleteAtIndex(2);
	linkedList->addAtHead(6);
	linkedList->addAtTail(4);   //链表变为1-> 2-> 3
	cout << linkedList->get(4) << endl;            //返回2
	linkedList->addAtHead(4);
	linkedList->addAtIndex(5,0);
	linkedList->addAtHead(6);
	NODE *p = linkedList->Head-> next;
	while(p)
	{
		if(p->next)
			cout << p -> val << " -> ";
		else
			cout << p -> val << endl;
		p = p -> next;
	}
	return 0;
}