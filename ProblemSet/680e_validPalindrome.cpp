#include "Include_all.h"
using namespace std;

bool validPalindrome(string s)
{
	int n = s.size();
	int i = 0,j = n-1;
	bool flag = false;
	while(i < j)
	{
		if(s[i] != s[j])
		{
			flag = true;
			break;
		}
		i++;j--;
	}
	int a = i,b = j;
	int c = i,d = j;
	int cnt = 0;
	if(flag)
	{
		a++;
		while(a < b)
		{
			if(s[a] != s[b])
			{
				cnt++;
				break;
			}
			a++;b--;
		}
		d--;
		while(c < d)
		{
			if(s[c] != s[d])
			{
				cnt++;
				break;
			}
			c++;d--;
		}
		if(cnt == 2) return false;
	}
	return true;

}

int main()
{
	string s = "abc";
	cout << validPalindrome(s) << endl;
	return 0;
}