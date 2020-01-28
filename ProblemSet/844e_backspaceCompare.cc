#include "Include_all.h"
using namespace std;

string trans(string str)
{
	int n = str.length();
	string s = "";
	stack<char> stk;
	for(int i = 0;i < n;i++)
	{
		if(isalpha(str[i]))
		{
			stk.push(str[i]);
		}
		else
		{
			if(!stk.empty())
			{
				stk.pop();
			}
		}
	}
	while(!stk.empty()){
		s += stk.top();
		std.pop();
	}
	return s;
}

bool backspaceCompare(string S, string T)
{
	return trans(S) == trans(T);
}

