#include "Include_all.h"
using namespace std;
/*********************超时解法***********************/
int needChange(string str)
{
	int Alphmap[26] = {0};
	string newStr = "";
	for(int i = 0;i < str.size();i++)
	{
		Alphmap[str[i]-'a']++;
		cout << (char)(str[i]-'a') << ':' <<Alphmap[str[i]-'a'] << endl;
	}
	for(char i = 0;i < 26;i++)
	{
		if(Alphmap[i]%2!=0)
			newStr += 'a'+i;
	}
	
	int n = newStr.length(),res = 0;
	int i = 0,j = n-1;
	while(i < j)
	{
		if(newStr[i] != newStr[j]) res++;
		i++;
		j--;
	}
	return res;
}
vector<bool> canMakePaliQueries_(string s, vector<vector<int>>& queries) {
	vector<bool> res(queries.size(), false);
	for(int i = 0;i < queries.size();i++)
	{
		int need = needChange(s.substr(queries[i][0],queries[i][1]-queries[i][0]+1));
		if(queries[i][2] >= need) res[i] = true;
	}
	return res;
}
/*********************正确解法***********************/
vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries){
	int n = s.size();
	//初始化字符串的前缀和数组
	vector<vector<int>> prefix(26, vector<int>(n+1,0));
	for(int i = 0;i < 26;i++)
		for(int j = 0;j < n;j++){
			prefix[i][j+1] = prefix[i][j] + (s[i]=='a'+i ? 1 : 0);
		}

	vector<bool> res;
	for(vector<int>& querie : queries){
		int left = querie[0], right = querie[1]+1,k = querie[2];
		int odd_count = 0; //统计奇数个的字符个数
		//计算子串中的各个字符的个数
		for(int i = 0;i < 26;i++){
			if((prefix[i][right]-prefix[i][left]) % 2 != 0)
				odd_count++;
		}
		res.push_back(odd_count <= 2*k + 1);
	}
	return res;
}

int main()
{
	string s ="abcda";
	vector<vector<int>> queries = {{3,3,0},{1,2,0},{0,3,1},{0,3,2},{0,4,1}};
	//vector<vector<int>> queries = {{3,3,0},{1,2,0},{0,3,1},{0,3,2},{0,4,1}};
	vector<bool> res(canMakePaliQueries(s,queries));
	for(auto i : res)
		cout << i << " ";
	cout << endl;
	return 0;
}

