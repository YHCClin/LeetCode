#include "Include_all.h"
using namespace std;

string reverseOnlyletters(string s)
{
	int i = 0,j = s.size()-1;
	char ch;
	while(i < j)
	{
		while(i < j && !isalpha(s[i])) i++;
		while(i < j && !isalpha(s[j])) j--;
		if(i < j && isalpha(s[i]) && isalpha(s[j]))
		{
			ch = s[i];
			s[i] = s[j];
			s[j] = ch;
			i++;
			j--;
		}
	}
	return s;
}

int main()
{
	string s = "a-bc-def-ghij";
	cout << reverseOnlyletters(s) << endl;
	return 0;
}