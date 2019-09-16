#include "Include_all.h"
using namespace std;

//滑窗法+哈希
void initialMap(unordered_map<char,int>& charmap,stirng s,int len)
{
	for(int i = 0;i < len;i++)
		 charmap[]
}
vector<int> findAnagrams(string s,string p)
{
	vector<int> res;
	if(p.size() > s.size()) return res;
	unordered_map<char,int> pmap;
	unordered_map<char,int> smap;
	for(auto i : p) pmap[p[i]]++;
	int i = 0,j = p.size()-1;
	//初始化smap
	for(int k = 0;k < j;k++) smap[s[k]]++;
}

int main()
{

	return 0;
}