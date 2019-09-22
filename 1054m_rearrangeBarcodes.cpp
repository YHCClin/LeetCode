#include "Include_all.h"
using namespace std;

struct item{
	int val;
	int numOfval;
};
struct lessbynum{
	bool operator()(const item& a,const item& b)
	{
		return a.numOfval < b.numOfval;
	}
};

vector<int> rearrangeBarcodes(vector<int>& barcodes)
{
	int n = barcodes.size();
	vector<int> res(n);
	priority_queue<item,vector<item>,lessbynum> Hip;
	map<int,int> hashmap;
	for(auto i : barcodes)
	{
		hashmap[i]++;
	}
	for(auto i : hashmap)
	{
		item it;
		it.val = i.first;
		it.numOfval = i.second;
		Hip.push(it);
	}
	int curVal = Hip.top().val;
	int curNum = Hip.top().numOfval;
	for(int i = 0;i < 2;i++)
	{
		for(int j = i;j < n;j+=2)
		{
			res[j] = curVal;
			curNum--;
			if(curNum == 0 && Hip.size() > 1)
			{
				Hip.pop();
				curVal = Hip.top().val;
				curNum = Hip.top().numOfval;
			}
		}

	}
	/*
	while(!Hip.empty())
	{
		cout << Hip.top().val << ": " << Hip.top().numOfval << endl;
		Hip.pop();
	}
	*/
	return res;
}

int main()
{
	vector<int> barcodes = {7,7,7,8,5,7,5,5,5,8};
	vector<int> res(rearrangeBarcodes(barcodes));
	for(auto i : res)
		cout << i << " ";
	cout << endl;
	return 0;
}