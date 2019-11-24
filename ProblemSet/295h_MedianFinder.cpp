#include "Include_all.h"
using namespace std;

class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {
	}
	
	//插入过程中维持两堆元素个数的动态平衡
	void addNum(int num) {
		//如果两堆元素个数相同
		if(smaller.size()==bigger.size())
		{
			if(!bigger.empty() && bigger.top()>=num)
			{
				cout << "Push num " << num <<" into bigger" << endl;
				bigger.push(num);
			}
			else
			{
				cout << "Push num " << num <<" into smaller" << endl;
				smaller.push(num);
			}
		}
		//小顶堆>大顶堆
		else if(smaller.size() < bigger.size())
		{
			if(bigger.top()>num)
			{
				cout << "Push bigger's top " << bigger.top() <<" into smaller" << endl;
				smaller.push(bigger.top());
				cout << "Pop bigger's top'" << bigger.top() <<" from bigger" << endl;
				bigger.pop();
				cout << "Push num " << num <<" into bigger" << endl;
				bigger.push(num);
			}
			else
			{
				cout << "Push num " << num <<" into smaller" << endl;
				smaller.push(num);
			}
		}
		//大顶堆>小顶堆
		else
		{
			if(smaller.top() < num)
			{
				cout << "Push smaller's top " << smaller.top() <<" into bigger" << endl;
				bigger.push(smaller.top());
				cout << "Pop smaller's top " << smaller.top() <<" from smaller" << endl;
				smaller.pop();
				cout << "Push num " << num <<" into smaller" << endl;
				smaller.push(num);
			}
			else
			{
				cout << "Push " << num <<" into bigger" << endl;
				bigger.push(num);
			}
		}
	}
	
	//该函数返回中位数
	double findMedian() {
		if(smaller.size()==bigger.size())
		{
			return (smaller.top()+bigger.top())/2.0;
		}
		else if(smaller.size()>bigger.size())
		{
			return smaller.top();
		}
		else
			return bigger.top();
	}
private:
	//实现两个堆得动态平衡
	priority_queue<int,vector<int>,greater<int>> smaller; //小顶堆
	priority_queue<int,vector<int>,less<int>> bigger; //大顶堆
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


int main()
{
	vector<int> nums = {1,5,46,4,6,3,34,5,67,34,53,23,22,12,8,67,55,66};
	MedianFinder* obj = new MedianFinder();
	for(auto i : nums)
		obj->addNum(i);
	double param_2 = obj->findMedian();
	cout << param_2 << endl;
	return 0;
}