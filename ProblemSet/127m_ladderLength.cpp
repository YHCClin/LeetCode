#include "Include_all.h"
using namespace std;

inline bool isNearly(string& a,string& b)
{
	int n = a.length();
	int unEquals = 0;
	for(int i=0;i<n;i++)
		if(a[i]!=b[i]) unEquals++;
	if(unEquals > 1) return false;
	return true;
}

void InitializeMG(vector<vector<int>>& M,vector<string>& wordList)
{
	int n = wordList.size();
	for(int i = 0;i < n-1;i++)
	{
		for(int j = i+1;j < n;j++)
		{
			if(isNearly(wordList[i], wordList[j]))
			{
				M[i].push_back(j);
				M[j].push_back(i);
			}
		}
	}
}

int ladderLength(string beginWord, string endWord,vector<string>& wordList)
{
	wordList.insert(wordList.begin(),beginWord);
	vector<vector<int>> M(wordList.size());
	InitializeMG(M,wordList);
	int k = 0;
	for(auto i : M)
	{
		cout << wordList[k++] << " : ";
		for(auto j : i)
			cout << wordList[j] << " ";
		cout << endl;
	}
	
	int res = 1;
	//BFS
	queue<int> que;
	vector<bool> visited(wordList.size(),false);
	que.push(0);
	visited[0] = true;
	bool flag = false;
	while(!que.empty())
	{
		res++;
		int size = que.size();
		for(int i = 0; i < size;++i)
		{
			int cur = que.front();
			que.pop();
			for(int j = 0;j < M[cur].size();++j)
			{
				if(!visited[M[cur][j]])
				{
					if(wordList[M[cur][j]]==endWord) {flag = true;}
					que.push(M[cur][j]);
					visited[M[cur][j]] = true;
				}
			}
		}
		if(flag) break;
	}
	if(flag) return res;
	return 0;
}

int main()
{
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList = {"hot","dot","dog","lot","log"};
	cout << ladderLength(beginWord,endWord,wordList) << endl;
	return 0;
}