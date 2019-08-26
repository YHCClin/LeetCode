#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s)
{
	unordered_map<char,char> set = {{')','('},{']','['},{'}','{'}};
	int num = s.size();
	stack<char> sta;
	for(int i = 0;i < num;i++)
	{
		char c = s[i];
		if(c == '(' || c == '[' || c == '{')
		{
			sta.push(c);
		}
		if(c == ')' || c == ']' || c == '}')
		{
			if(!sta.empty() && set[c]==sta.top())
			{
				sta.pop();
			}
		}
	}
	if(sta.empty())
	{
		return true;
	}
	return false;
}

int main()
{
	string s = "[](){()}";
	cout << isValid(s) << endl;
	return 0;
}