#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack,string needle)
{
	auto pos = haystack.find(needle);
	if(pos == string::npos)
		return -1;
	else
		return pos;
}

int main()
{
	string haystack = "hello";
	string needle = "ll";

	cout << strStr(haystack,needle) << endl;

	return 0;
}