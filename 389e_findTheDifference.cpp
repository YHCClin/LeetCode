#include "Include_all.h"
using namespace std;

char findTheDifference(string s,string t)
{
	char ans = 0;
	string s_and_t = s+t;
	for(auto i : s_and_t)
	{
		ans ^= i;
	}
	return ans;
}

char findTheDifference_v4(string s,string t)
{
	int sum = 0;
	for(auto i : t)
		sum += i;
	for(auto i : s)
		sum -= i;
	return (char)sum;
}

char findTheDifference_v3(string s,string t)
{
	int s_arry[26] = {0};
	int t_arry[26] = {0};
	for(auto i : s)
	{
		s_arry[i-'a']++;
	}
	for(auto i : t)
	{
		t_arry[i-'a']++;
	}
	for(int i = 0;i < 26;i++)
	{
		if(s_arry[i]!=t_arry[i])
			return (char)('a'+i);
	}
	return ' ';
}
char findTheDifference_v2(string s,string t)
{
	int n = s.size();
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	char ans = t[t.size()-1];
	for(int i = 0;i < n;++i)
	{
		if(s[i] != t[i])
			return t[i];
	}
	return ans;
}
char findTheDifference_v1(string s,string t)
{
	int n = s.size();
	unordered_map<char,int> smap;
	unordered_map<char,int> tmap;

	for(auto i : s)
	{
		if(smap.find(i)!=smap.end())
		{
			smap[i]++;
		}
		else
			smap[i]=1;
	}
	for(auto j : t)
	{
		if(tmap.find(j)!=tmap.end())
		{
			tmap[j]+=1;
		}
		else
			tmap[j]=1;
	}
	for(int i = 0;i <= n;i++)
	{
		if(smap.find(t[i]) == smap.end())
			return t[i];
		else
		{
			if(smap[t[i]] != tmap[t[i]])
				return t[i];
		}
	}
	return ' ';
}

int main()
{
	string s = "abcddfs";
	string t = "abcdfeds";
	cout <<	findTheDifference(s,t) << endl;
	return 0;
}