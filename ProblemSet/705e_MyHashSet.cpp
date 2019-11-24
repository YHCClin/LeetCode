#include "Include_all.h"
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int val) : val(val), next(NULL) {}
};

const int LEN = 100;

class MyHashSet {
public:
    /** Initialize your data structure here. */
    /*链地址法*/

    MyHashSet() {
        //挂一个头结点
        Arr = vector<Node*>(LEN, new Node(-1));
    }
    int hash(int key)
    {
        return key % LEN;
    }
    void add(int key) {
        int locate = hash(key);
        //头插法建立链表
        Node* node = new Node(key);
        node -> next = Arr[locate] -> next;
        Arr[locate]->next = node;
    }

    void remove(int key) {
        int locate = hash(key);
        Node *pre = Arr[locate];
        while(pre -> next != NULL)
        {
            bool flag = true;
            if(pre -> next -> val == key)
            {
                Node *r = pre -> next;
                pre -> next = r -> next;
                delete(r);
                flag = false;
            }
            if(flag)
                pre = pre -> next;
        }
        return;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int locate = hash(key);
        Node *p = Arr[locate] -> next;
        while(p)
        {
            if(p -> val == key)
            {
                return true;
            }
            p = p -> next;
        }
        return false;
    }
private:
    vector<Node*> Arr;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main()
{
    int key = 4;
    MyHashSet* obj = new MyHashSet();
    obj->add(key);
    obj->add(key);
    //obj->remove(key);
    bool param_3 = obj->contains(key);
    cout << param_3 << endl;
    return 0;
}