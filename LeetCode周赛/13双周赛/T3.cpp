#include <bits/stdc++.h>
using namespace std;

// 并查集思想
class Solution {
public:
	//并查集找到所有的的近义词集团，dfs构造句子
	map<string, vector<string>>syn;
	vector<string>ret;
	map<string, string> parent;
	string find_(string x)
	{
		return parent[x] == "" ? x : find_(parent[x]);
	}
	void union_(string x, string y)
	{
		string x_root = find_(x), y_root = find_(y);
		if (x_root == y_root) return;
		parent[x_root] = y_root;
	}
	void dfs(vector<string>& str, int cur)
	{
		if (cur == str.size())
		{
			string ans;
			ans += str.front();
			for (int i = 1; i < str.size(); i++)
				ans += " " + str[i];
			ret.push_back(ans);
			return;
		}
		string s = find_(str[cur]);//备份一下父亲
		for (int i = 0; i < syn[s].size(); i++)
		{
			str[cur] = syn[s][i];
			dfs(str, cur + 1);
			str[cur] = s;
		}
	}
	vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
		text += ' ';
		string tmp;
		vector<string>str;
		for (auto& it : synonyms)
			union_(it[0], it[1]);
		for (int i = 0; i < text.size(); i++)
			if (text[i] == ' ')
			{
				union_(tmp, tmp);//给还没有父亲的单词找个爹
				str.push_back(tmp);
				tmp = "";
			}
			else
				tmp += text[i];
		for (auto& it : parent)
			syn[find_(it.first)].push_back(it.first);//将所有连通块内的单词绑定在他们的父亲身上
		dfs(str, 0);
		return ret;
	}
};

int main()
{
	vector<vector<string>> synonyms = {{"happy", "joy"}, {"sad", "sorrow"}, {"joy", "cheerful"}};
	string text = "I am happy today but was sad yesterday";
	Solution S;
	vector<string> res(S.generateSentences(synonyms, text));
	for (auto st : res) cout << st << endl;
	return 0;
}