#include "Include_all.h"
using namespace std;

int main()
{
	string str;
	string answer;
	while(true)
	{
		cin >> str;
		for(int i = 0;i < str.size();i++)
		{
			if(str[i]=='吗')
			{
				str[i] = ' ';
			}
			if(str[i] == '?')
			{
				str[i] = '!';
			}
		}
		cout << str << endl;
	}
}