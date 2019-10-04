#include "Include_all.h"
using namespace std;

//define priority of operat


/*middle to back*/



string MB(string exp)
{
	map<char,int> operators;
	operators['+'] = 0;
	operators['-'] = 0;
	operators['*'] = 1;
	operators['/'] = 1;
	operators['('] = -1;

	int n = exp.size();
	string res = "";
	stack<char> opt;
	for(int i = 0; i < n; i++)
	{
		if(exp[i]>='0' && exp[i]<='9')
		{
			res+=exp[i];
		}
		else if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/')
		{
			if(opt.empty())
			{
				opt.push(exp[i]);
			}
			else
			{
				while(!opt.empty())
				{
					if( operators[exp[i]] > operators[opt.top()] )
					{
						opt.push(exp[i]);
						break;
					}
					else
					{
						res+=opt.top();
						opt.pop();
					}
				}
				if(opt.empty()) opt.push(exp[i]);
			}
		}
		else if(exp[i]=='(')
		{
			opt.push(exp[i]);
		}
		else if(exp[i]==')')
		{
			while(opt.top()!='(')
			{
				res+=opt.top();
				opt.pop();
			}
			opt.pop();
		}
	}
	while(!opt.empty())
	{
		res+=opt.top();
		opt.pop();
	}
	return res;
}

int main()
{
	string exp = "((1+2/3*(3-9))+(3-4))/(5-3)";
	cout << MB(exp) << endl;
	return 0;
}