#include "Include_all.h"

//实现异或门（和）
char XOR(char a,char b)
{
	if(a == b)
	{
		return '0';
	}
	else
		return '1';
}
//与门的实现（进位）
char AND(char a,char b)
{
	if(a=='1' && b=='1')
	{
		return '1';
	}
	else
		return '0'
}
//半加器实现
vector<char> HalfAdd(vector<char> input,char carry)
{
	input[0] = XOR(a,b);
	input[1] = AND(a,b);
	HalfAdd()
	return input;
}
//全加器实现

string addBinary(string a, string b)
{
	if(a.size() > b.size())
	{
		b = b.insert(0,a.size()-b.size(),'0');
	}
	if(a.size() < b.size())
	{
		a = a.insert(0,b.size()-a.size(),'0');
	}
	map<char,int> set = {{'1',1},{'0',0}};
	int i = 0,j = 0;

	vector<char> xor_ans;
	vector<char> and_ans;
	for(;i < a.size();++i)
	{
		xor_ans.push_back(XOR(a[i],b[i]));
		and_ans.push_back(AND(a[i],b[i]));
	}

	for()



	
}


int main()
{
	
}