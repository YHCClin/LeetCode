#include "Include_all.h"
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
{
	int n_push = pushed.size();
	int n_pop = popped.size();

	//定义一个栈来模拟入栈出栈操作
	stack<int> sta;
	//定义两个队列存放vector
	queue<int> q_pushed;
	queue<int> q_popped;
	for(int m = 0;m < n_push;m++)
	{
		q_pushed.push(pushed[m]);
		q_popped.push(popped[m]);
	}
	int count = 0;
	while(!q_popped.empty())
	{
		if(!sta.empty() && sta.top()==q_popped.front())
		{
			sta.pop();

			q_popped.pop();
			continue;
		}
		if(!q_pushed.empty())
		{
			sta.push(q_pushed.front());
			q_pushed.pop();
		}
		count++;
		if(count >= 2*n_pop)
		{
			break;
		}
	}

	if(sta.empty())
	{
		return true;
	}
	else
		return false;
}

int main()
{
	vector<int> pushed{1,2,3,4,5};
	vector<int> popped{4,3,5,1,2};
	cout << validateStackSequences(pushed,popped) << endl;
	return 0;
}