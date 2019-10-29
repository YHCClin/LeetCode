#include "Include_all.h"
using namespace std;
// Manacher 算法

int p[2005];
string longestPalindrome(string s) {
	string new_s = "$#";
	int n = s.size();
	for(int i = 0; i < n ; i++)
	{
		new_s += s[i];
		new_s += '#';
	}
	cout << new_s << endl;
	int len = new_s.size();
	int max_len = -1;
	int id;
	int mx = 0;
	int max_index = 0;
	string ans = "";
	for(int i = 1;i < len;i++)
	{
		if(i < mx)
		{
			p[i] = min(p[2*id-i],mx-i);
		}
		else
		{
			p[i] = 1;
		}
		
		while(new_s[i-p[i]] == new_s[i+p[i]]) p[i]++;
		if(mx < i + p[i])
		{
			id = i;
			mx = i + p[i];
		}
		if(p[i]-1 > max_len)
		{
			max_len = p[i]-1;
			max_index = i;
		}
	}
	cout << new_s[max_index] << endl;
	string temp = new_s.substr(max_index-p[max_index]+1,2*p[max_index]-1);
	for(auto c : temp)
	{
		if(c != '#' && c != '$') ans+=c;
	}
	return ans;
}