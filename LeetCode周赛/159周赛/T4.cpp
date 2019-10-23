#include "Include_all.h"
using namespace std;

/*
	动态规划：
	首先创建一个数组，记录以结束时间为升序的工作序号。
	即创建数组 idx=[0,1,2,...,n-1]，并以 endTime[i] 为cmp函数排序。

	考虑以dp[i]表示以第i份工作结束时间作为结束时间时，可以获得的最大报酬。
	则有 dp[idx[i]]=max(dp[idx[i-1]],dp[idx[j]]+profit[idx[i]],profit[idx[i]])
	即以第idx[i]个工作的结束时间作为结束时间的情况下，可以获得最大报酬的情况分为3种：
	1.不选择这份工作，那么 dp[idx[i]] = dp[idx[i-1]]
	2.选择这份工作，如果以startTime[idx[i]]为结束时间的情况下，可以获得的报酬不为0，那么
	dp[idx[i]] = dp[idx[j]] + profit[idx[i]],这里的 j 为使得 endTime[idx[j]]<=startTime[idx[i]] 的所有j中的最大值。
	这里的 j 可以通过二分的方式求得。
	3.选择这份工作，但是第2种情况中的j不存在，dp[idx[i]]=prifit[idx[i]]
*/
#define MAX 20005
int *idx;
bool cmp(int &a,int &b)
{
	return idx[a] < idx[b];
}
int jobScheduling(vector<int> &s,vector<int> &t,vector<int> &profit)
{
	int id[s.size()] = {0};
	idx = id;
	for(int i = 0; i < s.size(); i++) idx[i] = i;
	sort(idx,idx+s.size(),cmp);
	int dp[s.size()] = {0};
	dp[idx[0]] = profit[idx[0]];
	//有空再写吧。。。。。。。。
}

