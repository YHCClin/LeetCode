#include "Include_all.h"
using namespace std;

//建立hash链表
struct node
{
	int date;
	node *next;
	node(int d) : date(d), next(nullptr) {}
}NODE;
struct HashList
{
	//顺序表
	std::vector<node*> list;
	HashList(int num) {
		for(int i = 0;i < num;i++)
		{
			list.push_back(nullptr);
		}
	}
};
//散列函数
int hash(int num, int k)
{
	return num % k;
}
//插入函数(头插法)
void insert(int val,int k,HashList& hs)
{
	int pos = hash(val,k);
	NODE* nd = new NODE(val);
	nd -> next = hs.list[pos];
	hs.list[pos] = nd;
}

//查找函数
bool find(int val,HashList& hs)
{
	int pos = hash(val);
	NODE* p = hs.list[pos];
	while(p)
	{
		if(p -> date == val)
		{
			return true;
		}
		p = p -> next;
	}
	return false;
}
//暴力解法(超时)
bool containsNearbyDuplicate_(vector<int>& nums,int k)
{
	int i,j;
	int n = nums.size();

	for(i = 0;i < n;i++)
	{
		for(j = i+1;j < n;j++)
		{
			if(nums[i]==nums[j] && j-i<=k)
				return true;
		}
	}
	return false;
}

//unorderd_set解法
bool containsNearbyDuplicate(vector<int>& nums,int k)
{
	unordered_set<int> hs;
	for(int i = 0;i < nums.size();++i)
	{
		if(hs.find(nums[i])!=hs.end()) return true;
		hs.insert(nums[i]);
		if(hs.size() > k)
			hs.erase(nums[i-k]);
	}
	return false;
}
int main()
{
	vector<int> nums{1,2,3,1};
	HashList h(10);
	for(int i = 0;i < h.list.size();i++)
	{
		cout << h.list[i] << endl;
	}
	cout << containsNearbyDuplicate(nums,3) << endl;
	return 0;
}