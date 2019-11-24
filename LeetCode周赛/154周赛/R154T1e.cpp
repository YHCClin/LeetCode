#include "Include_all.h"
using namespace std;

int maxNumberOfBalloons(string text)
{
	int n = text.size();
	if(n<7) return 0;
	unordered_map<char,int> charmap = {{'b',0},{'a',0},{'l',0},{'o',0},{'n',0}};
	for(auto i : text)
	{
		if(charmap.find(i)!=charmap.end())
		{
			charmap[i]++;
		}
	}
	vector<int> alpnum;
	for(auto iter = charmap.begin(); iter !=charmap.end();iter++)
	{
		if(iter->first == 'a' || iter->first == 'b' || iter->first == 'n')
		{
			alpnum.push_back(iter->second);
		}
		else
		{
			alpnum.push_back((iter->second)/2);
		}
	}
	int res = INT_MAX;
	for(auto i : alpnum)
	{
		if(i < res) res = i;
	}
	return res;

}

int main()
{
	string text = "leetcode";
	cout << maxNumberOfBalloons(text) << endl;
	return 0;
}