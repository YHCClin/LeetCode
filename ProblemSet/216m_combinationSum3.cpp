#include "Include_all.h"
using namespace std;

void function(int k,int n,int beg,vector<vector<int>>& ans,vector<int>& res)
{
	if(k<0 || n<0) return;
	if(k==0 && n==0)
	{
		ans.push_back(res);
	}
	for(int i = beg;i<10;++i)
	{
		res.push_back(i);
		function(k-1,n-i,i+1,ans,res);
		res.pop_back();
	}
}

vector<vector<int>> combinationSum(int k,int n)
{
	vector<vector<int>> ans;
	vector<int> res;
	function(k,n,1,ans,res);
	return ans;
}


int main()
{

	for(auto i : combinationSum(3,7))
	{
		for(auto j : i)
		{
			cout << j << "\t";
		}
		cout << endl;
	}
	return 0;
}