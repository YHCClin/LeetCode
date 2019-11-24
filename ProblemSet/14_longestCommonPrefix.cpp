#include <iostream>
#include <string>
#include <vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs)
{
	if(strs.empty())
	{
		return "";
	}
	int num = strs.size();
	string min_str = strs[0];
	//找到最短字符串
	for(int i=1;i < num;++i)
	{
		if(strs[i].size() < min_str.size())
		{
			min_str = strs[i];
		}
	}
	string ans = "";
	//将各字符串与最短字符串各位置一一比对
	for(int j=0,i;j < min_str.size();++j)
	{
		for(i=0;i < num;++i)
		{
			if(strs[i][j] != min_str[j])
			{
				return ans;
			}
		}
		ans += min_str[j];
	}
	return ans;
}
int main()
{
	vector<string> strs;
	strs.push_back("hello");
	strs.push_back("helyg");
	strs.push_back("heelj");
	cout << longestCommonPrefix(strs) << endl;
	return 0;
}