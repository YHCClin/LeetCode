#include "Include_all.h"
using namespace std;

/*括号生成*/
void generate(vector<string>& res, unordered_map<char, int>& map, vector<char> sta, int n, char cur)
{
	sta.push_back(cur); map[cur]--;
	if (sta.size() == 2 * n)
	{
		string combine(sta.begin(), sta.end());
		res.push_back(combine);
	}
	if (sta.empty()) {generate(res, map, sta, n, '(');}
	else
	{
		if (sta.back() == '(' && map['('] != 0)
		{
			generate(res, map, sta, n, '(');
		}
		if (sta.back() == '(' && map[')'] != 0)
		{
			generate(res, map, sta, n, ')');
		}
	}

}
vector<string> generateParenthesis(int n)
{

}

int main()
{
	int n = 3;
	vector<string> res(generateParenthesis(n));
	for (auto i : res)
	{
		cout << i << endl;
	}
	return 0;
}