#include "Include_all.h"
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> stack1;
    stack<int> stack2;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
    	int element;
        if(stack2.empty())
        {
        	while(!stack1.empty())
        	{
        		stack2.push(stack1.top());
        		stack1.pop();
        	}
        	element = stack2.top();
        	stack2.pop();
        }
        else
        {
        	element = stack2.top();
        	stack2.pop();
        }
        return element;
    }
    
    /** Get the front element. */
    int peek() {
        if(!stack2.empty())
        {
        	return stack2.top();
        }
        else
        {
        	while(!stack1.empty())
        	{
        		stack2.push(stack1.top());
        		stack1.pop();
        	}
        	return stack2.top();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(stack1.empty() && stack2.empty())
        {
        	return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


int main()
{
	int x = 6;
	MyQueue* obj = new MyQueue();
 	obj->push(x);
 	int param_2 = obj->pop();
 	int param_3 = obj->peek();
 	bool param_4 = obj->empty();
 	cout << param_2 << " " << param_3 << " " << param_4 << endl;

 	return 0;
}
