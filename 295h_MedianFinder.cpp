#include "Include_all.h"
using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(smaller.size()==bigger.size())
        {
        	
        }
    }
    
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
	priority_queue<int,vector<int>,greater<int>> smaller;
	priority_queue<int,vector<int>,less<int>> bigger;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


int main()
{
	MedianFinder* obj = new MedianFinder();
	obj->addNum(num);
	double param_2 = obj->findMedian();
	cout << param_2 << endl;
	return 0;
}