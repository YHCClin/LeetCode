#include "Include_all.h"
using namespace std;
int Stoi(string s)
{
	int res = 0;
	int n = s.size();
	for(int i = 0; i < n;i++)
	{
		res = res*10 + (int)(s[i]-'0');
	}
	return res;
}

int numDecodings(string s)
{
	if(s.size()==1)
	{
		if(s[0]=='0') return 0;
		if(s[0] != '0') return 1;
	}
	//if(s.find('0') != string::npos) return 0;
	if(s.size()>=2)
	{
		if(Stoi(s.substr(0,2)) <= 26 && Stoi(s.substr(0,2))>0 && Stoi(s.substr(0,2))%10!=0)	
			return numDecodings(s.substr(1,s.size()-1)) + numDecodings(s.substr(2,s.size()-2));
		else if(Stoi(s.substr(0,2))==0 || Stoi(s.substr(0,2)) <= 26 && Stoi(s.substr(0,2))>0 && Stoi(s.substr(0,2))%10==0)
			return numDecodings(s.substr(2,s.size()-2));
		else if(Stoi(s.substr(0,2))>0)
			return numDecodings(s.substr(1,s.size()-1));
	}

	return 1;
}

int main()
{
	string code = "0010";
	cout << numDecodings(code) << endl;
	return 0;
}