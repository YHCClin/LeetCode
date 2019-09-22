#include "Include_all.h"
using namespace std;
//简单暴力枚举，超时
vector<int> findNumOfVaildWords_TL(vector<string>& words, vector<string>& puzzles)
{
	vector<int> res;
	for(auto i : puzzles)
	{
		int charcounter[26] = {0};
		for(auto j : i)
		{
			charcounter[j-'a']++;
		}
		int ans = 0;
		for(auto k : words)
		{
			bool flag = true;
			unordered_set<char> chset;
			for(auto m : k)
			{
				chset.insert(m);
				if(chset.size()>7)
				{
					flag = false;
					break;
				}
			}
			if(flag)
			{
				if(chset.find(i[0])==chset.end())
					continue;
				else
				{
					auto iter = chset.begin();
					bool flags = true;
					for(;iter != chset.end();iter++)
					{
						if(charcounter[(*iter)-'a'] <= 0)
						{
							flags = false;
							break;
						}
					}
					if(flags) ans++;
				}
			}
		}
		res.push_back(ans);
	}
	return res;
}
//暴力枚举，位运算，还是超时
vector<int> findNumOfVaildWords_BTL(vector<string>& words, vector<string>& puzzles)
{
	vector<int> res;
	vector<int> binOfpuzzles;
	for(auto i : puzzles)
	{
		//生成谜面的二进制数
		int puzzle = 0;
		
		for(auto j : i)
		{
			puzzle = puzzle | (1 << (j-'a'));
		}
		binOfpuzzles.push_back(puzzle);
	}
	vector<int> binOfwords;
	for(auto& k : words)
	{
		//生成谜底的二进制数
		int word = 0;
		int cnt = 0;
		for(auto& m : k)
		{
			word = word | (1 << (m-'a'));
		}
		binOfwords.push_back(word);
	}
	int n = 0;
	for(auto& i : binOfpuzzles)
	{
		int ans = 0;
		for(auto& j : binOfwords)
		{
			if(i == j) ans++;
			else if(i < j) continue;
			else if((((1 << (puzzles[n][0]-'a')) & j) != 0)) //如果word中包含puzz的第一个字母
			{
				bool flag = true;
				for(int k = 0;k < 26;k++) //判断是否符合第二条件
				{
					if( ((int)((1 << k)&i) == 0) && ((int)((1 << k)&j) != 0) ) //word中存在而puzz中不存在
					{
						flag = false;
						break;
					}
				}
				if(flag) ans++;
			}
		}
		res.push_back(ans);
		n++;
	}
	return res;
}
//位运算+哈希
vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
	//v用来保存含有'a'+i字母的word的二进制数
	vector<int> hashV[26];
	for (auto& i : words) {
		unordered_set<char> s(i.begin(), i.end());
		int tmp = 0;
		//生成一个谜底word的二进制数
		for (int ii = 0; ii < 26; ii++)
			if (s.count('a' + ii))
				tmp = tmp^(1 << ii);
		//
		for (char j : s)
			hashV[j - 'a'].push_back(tmp);
	}
	//结果数组ans
	vector<int> ans;
	//
	for (auto& i : puzzles) {
		int at = i[0] - 'a';//记录首字母
		unordered_set<char> s(i.begin(), i.end());
		int tmp = 0;
		//生成一个谜面的二进制数
		for (int ii = 0; ii < 26; ii++)
			if (s.count('a' + ii))
				tmp ^= 1 << ii;
		ans.push_back(0);
		for (int j : hashV[at]) //hashV[at]中保存的是包含puzzle首字母的word的二进制数
			if ((j & tmp) == j) //j & tmp 会得到它们共同拥有的字符的二进制数，
				ans.back()++;   //若其值与(j)不相等则表示word中含有puzzle中不含的字符
	}
		return ans;
}
int main()
{
	vector<string> words = {"aaaa","asas","able","ability","actt","actor","access"};
	vector<string> puzzles = {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
	vector<int> res(findNumOfValidWords(words,puzzles));
	for(auto i : res)
	{
		cout << i << "  ";
	}
	cout << endl;
	return 0;
}