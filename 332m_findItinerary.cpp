#include "Include_all.h"
using namespace std;

void EulerDFS(map<string, vector<string>>& Mgraph,vector<string>& res,string Start,int n)
{
	res.push_back(Start);
	if(res.size() == n+1) return;
	int i;bool flag = true;
	for(int j = 0;j < Mgraph[Start].size();j++)
		if(Mgraph[Start][j] != "--")
			flag = false;
	if(flag) 
	{
		res.pop_back();
		return;
	}
	for(i = 0;i < Mgraph[Start].size();i++)
	{
		if(Mgraph[Start][i] != "--")
		{
			string next = Mgraph[Start][i];
			Mgraph[Start][i] = "--";
			EulerDFS(Mgraph,res,next,n);
			Mgraph[Start][i] = next;
			//res.pop_back();
		}
	}
}

vector<string> findItinerary_(vector<vector<string>>& tickets)
{
	map<string, vector<string>> Mgraph;
	for(auto e : tickets)
	{
		Mgraph[e[0]].push_back(e[1]);
	}
	for(auto &i : Mgraph)
		sort(i.second.begin(), i.second.end());
	vector<string> res;
	//res.push_back("JFK");
	EulerDFS(Mgraph,res,"JFK",tickets.size());
	vector<string> result(res.begin(), res.begin()+tickets.size()+1);
	return result;
}

void dfs(map<string, map<string, int>>& m, map<string, map<string, int>>& vis, vector<string>& cur, int n, vector<string>& res) {
        // 如果已经找到一个结果，直接返回
        if(res.size()==n) return;
        if(cur.size()==n) {
            res = cur;
            return;
        }
        // 没有以当前机场为起点的机票，中止搜索
        if(m.find(cur.back())==m.end()) return;
        // 遍历
        for(auto it: m[cur.back()]) {
            string stop = it.first;
            // 根据机票数量判断是否可以继续搜索
            if(vis[cur.back()][stop]==it.second) continue;
            vis[cur.back()][stop]++;
            cur.push_back(stop);
            dfs(m, vis, cur, n, res);
            cur.pop_back();
            vis[cur.back()][stop]--;
            // 如果已经找到一个结果，直接返回
            if(res.size()==n) return;
        }
    }

vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 两个机场间可能有多张机票，所以value用int来计数
        // map保证value有序，可以保证第一个搜索结果即为最终结果
        map<string, map<string, int>> m, vis;
        for(auto t: tickets) m[t[0]][t[1]]++;
        vector<string> res, cur;
        // 添加起始点
        cur.push_back("JFK");
        dfs(m, vis, cur, tickets.size()+1, res);
        return res;
    }
int main()
{
	vector<vector<string>> tickets__ = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
	vector<vector<string>> tickets_ = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
	vector<vector<string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
	vector<string> res(findItinerary(tickets));
	for(auto i : res)
		cout << i << " ";
	cout << endl;
	return 0;
}