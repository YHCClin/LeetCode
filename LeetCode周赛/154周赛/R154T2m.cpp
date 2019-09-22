#include "Include_all.h"
using namespace std;

inline void Reverse(string &s,int i ,int j)
{
	if(j - i <= 0) return;
	while(i < j)
	{
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}

string reverseParentheses(string s)
{
	stack<int> indexStack;
	for(int i = 0;i < s.size();i++)
	{
		if(s[i] == '(') indexStack.push(i);
		if(s[i] == ')')
		{
			int ind = indexStack.top();
			Reverse(s,ind,i);
			indexStack.pop();
		}
	}
	string res = "";
	for(auto i : s)
	{
		if(i != '(' && i != ')') res += i;
	}
	return res;
}

int main()
{
	string s = "(ed(et(oc))el)";
	cout << reverseParentheses(s) << endl;
	return 0;
}