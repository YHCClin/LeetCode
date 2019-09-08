#include "Include_all.h"
using namespace std;

vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
		vector<pair<string,string>> paras;
		for(auto s : phrases)
		{
			int i = 0,j = s.size()-1;
			string beg = "",end = "";
			while((i < s.size() && j >= 0) && (s[i]!=' ' || s[j]!=' '))
			{
				if(s[i]!=' ')
				{
					beg += s[i];
					i++;
				}
				if(s[j]!=' ')
				{
					end = s[j] + end;
					j--;
				}
				//cout << 1 << endl;
			}
			cout << beg << " " << end << endl;
			paras.push_back(make_pair(beg,end));
		}
		set<string> res;
		
		int n = paras.size();
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n;j++)
			{
				if(paras[i].second == paras[j].first && i != j)
					res.insert(phrases[i] + phrases[j].substr(paras[i].second.size(),phrases[j].size()-paras[i].second.size()));
			}
		}
		//sort(res.begin(),res.end());
		vector<string> result(res.begin(),res.end());
		return result;
	}

int main()
{
	vector<string> phrases = {"mission statement",
				"a quick bite to eat",
				"a chip off the old block",
				"chocolate bar",
				"mission impossible",
				"a man on a mission",
				"block party",
				"eat my words",
				"bar of soap"};
	vector<string> phrases_ = {"a","b","a"};
	vector<string> res(beforeAndAfterPuzzles(phrases));
	for(auto i : res)
		cout << i << endl;
	return 0;
}