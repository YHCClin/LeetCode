#include "Include_all.h"
using namespace std;

string reverseWords(string s)
{
	stack<string> words;
	string word;
	istringstream is(s);
	while(is >> word)
		words.push(word);
	string res = "";
	int n = words.size();
	while(!words.empty())
	{
		res += words.top()+' ';
		words.pop();
	}
	return res.substr(0,res.size()-1);
}

int main()
{
	string s = " hello woerd sdjf! sdjf   sdfjsjd  ";
	cout << reverseWords(s) << endl;
	return 0;
}