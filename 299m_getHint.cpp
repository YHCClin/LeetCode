#include "Include_all.h"
using namespace std;

string getHint(string secret, string guess) {
	int n = secret.size();
	int A = 0,B = 0;
	unordered_map<char,int> smap;
	for(int i = 0;i < n;++i) {smap[secret[i]]++;if(secret[i] == guess[i]) A++;}
	for(int i : guess)
	{
		if(smap.find(i) != smap.end() && smap[i]>0)
		{
			B++;
			smap[i]--;
		}
	}
	B = B - A;
	string res = to_string(A) + 'A' + to_string(B) + 'B';
	return res;
}

int main()
{
	string secret = "1807";
	string guess = "7810";
	cout << getHint(secret, guess) << endl;
}