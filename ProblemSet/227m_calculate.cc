#include "Include_all.h"
using namespace std;

map<char, int> priority = {{'+',1},{'-',1},{'*',2},{'/',2}};
string toBackExp(string s)
{
	string sr = "";
	stack<char> ops;	// 操作符栈
	int n = s.size();
	for(int i = 0;i < n;i++)
	{
		if(s[i] == ' ') continue;
		else if(s[i]>='0' && s[i]<='9')
		{
			sr += s[i];
		}
		else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			if(!ops.empty())
			{
				while(!ops.empty() && priority[ops.top()] >= priority[s[i]])
				{
					sr += ops.top();
					ops.pop();
				}
				ops.push(s[i]);
				continue;
			}
			else
			{
				ops.push(s[i]);
			}
		}
	}
	cout << "remains " << ops.size() << endl;
	while(!ops.empty()) 
	{
		sr += ops.top();
		ops.pop();
	}
	return sr;
}

int calculate(string s)
{
	string bs = toBackExp(s);
	stack<int> sta;
	int n = bs.size();
	for(int i = 0;i < n;i++)
	{
		if(bs[i] >= '0' && bs[i] <= '9')
		{
			sta.push(bs[i]-'0');
		}
		else
		{
			int a = sta.top();
			sta.pop();
			int b = sta.top();
			sta.pop();
			int ans;
			switch(bs[i])
			{
				case '+':
					ans = a + b;
					break;
				case '-':
					ans = b - a;
					break;
				case '*':
					ans = a * b;
					break;
				case '/':
					ans = b/a;
					break;
			}
			sta.push(ans);
		}
	}
	return sta.top();
}

int main()
{
	string exp = "3 + 5*2/3+6*2/2";
	cout << calculate(exp) << endl;
	return 0;
}