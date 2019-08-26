#include <iostream>
#include <string>
#include <map>
using namespace std;

string Say(string pre)
{
		int count = 0;
		int num;
		char temp = pre[0];
		char temps;
		string next = "";
		for(int j = 0;j <= pre.size();j++)
		{
			if(pre[j]==temp)
			{
				count++;
			}
			else
			{
				num = count;
				temps = temp;
				temp = pre[j];
				count=1;
				next += to_string(num)+temps;
			}
		}
		return next;
}

string countAndSay(int n)
{
	string pre = "1";
	if(n==1) return pre;
	for(int i = 0;i < n;i++)
	{
		pre = Say(pre);
	}
	return pre;
}

int main()
{
	cout << countAndSay(4) << endl;
	return 0;
}