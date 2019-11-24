#include "Include_all.h"
using namespace std;

struct item{
		int val;
		int numOfval = 0;
		item(int v) : val(v) {}
	};
struct lessbynum {
	bool operator()(const item& a,const item& b){
		return a.numOfval < b.numOfval;
	}
};
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int,int> hash;
		for(int i : nums)
		{
			if(hash.find(i) != hash.end())
			{
				hash[i]++;
			}
			else
			{
				hash[i] = 0;
			}
		}
		priority_queue<item,vector<item>,lessbynum> hip;
		for(auto iter = hash.begin();iter != hash.end();iter++)
		{
			item it(iter->first);
			it.numOfval = iter->second;
			hip.push(it);
		}
		vector<int> res;
		int m = 0;
		while(m < k)
		{
			res.push_back(hip.top().val);
			hip.pop();
			m++;
		}
		return res;
	}

int main()
{
	vector<int> nums = {1};
	int k = 1;
	vector<int> res(topKFrequent(nums,k));
	for(auto i : res)
		cout << i << " ";
	cout << endl;
}