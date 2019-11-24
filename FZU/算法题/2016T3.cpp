#include <bits/stdc++.h>
using namespace std;

//class LessThanByTime;
class Machine{
	friend class LessThanByTime;
	public:
		Machine() : time(0) {}
		operator int() const { return time;}
		int time;		// 执行时间
		int id;			// 机器编号
};
//自定义排序规则
class LessThanByTime{
public:
	bool operator()(const Machine& a,const Machine& b)
	{
		return a.time > b.time;//小顶堆(>),大顶堆(<)
	}
};

int optDistribution(vector<int> &tasks, int m)
{
	int optTime = 0;
	int n = tasks.size();
	if(n <= m) // 机器有冗余，每个任务直接分配一台机器
	{
		optTime = tasks[0];
		for(auto i : tasks)
			if(i > optTime)
				optTime = i;
		return optTime;
	}
	else
	{
		Machine X;
		priority_queue<Machine, vector<Machine>, LessThanByTime> Q;
		// 初始化
		for(int i = 0;i < m;i++)
		{
			X.id = i;
			X.time = 0;
			Q.push(X);
		}
		// 分配 n 个任务
		for(int i = 0;i < n;i++)
		{
			Machine Ma = Q.top(); // 每次选出执行时间最小的机器分配任务
			Q.pop();
			Ma.time += tasks[i];
			Q.push(Ma);
		}
		// 最优运行时间为最大的机器运行时间
		while(!Q.empty())
		{
			optTime = Q.top();
			Q.pop();
		}
	}
	return optTime;
}

int main()
{
	vector<int> tasks = {2,3,2,4,6,3,3,2,3,8};
	cout << optDistribution(tasks,6) << endl;
}