#include "Include_all.h"
using namespace std;

bool isIsomorphic(string s,string t)
{
	if(s.size() != t.size()) return false;
	int n = s.size();
	unordered_map<char,char> charmap; 
	{
		if(charmap.find(s[i])!=charmap.end())
		{
			if(charmap[s[i]] != t[i])
				return false;
		}
		else
		{
			if(charmap.find(t[i])==charmap.end())
			{
				charmap[s[i]] = t[i];
			}
			else
			{
				if(charmap[t[i]] != s[i])
					return false;
			}
		}
	}
	return true;
}

int main()
{
	string s = "bar";
	string t = "foo";
	cout << isIsomorphic(s, t) << endl;
	return 0;
}