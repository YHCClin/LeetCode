#include "Include_all.h"
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> mystack;
    queue<int> temp;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(mystack.empty())
        {
        	mystack.push(x);
        }
        else
        {
        	while(!mystack.empty())
        	{
        		temp.push(mystack.front());
        		mystack.pop();
        	}
        	mystack.push(x);
        	while(!temp.empty())
        	{
        		mystack.push(temp.front());
        		temp.pop();
        	}
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int element = mystack.front();
        mystack.pop();
        return element;
    }
    
    /** Get the top element. */
    int top() {
        return mystack.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return mystack.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */



int main()
{
	int x = 10;
	MyStack* obj = new MyStack();
	obj -> push(x);
	int param_2 = obj->pop();
	int param_3 = obj->top();
	bool param_4 = obj->empty();
	cout << param_2 << " " << param_3 << " " << param_4 << endl;
	return 0;
}