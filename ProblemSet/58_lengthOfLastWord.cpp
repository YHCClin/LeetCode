#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int lengthOfLastWord(string s)
{
	int length = 0;
	string word,last_w;
	istringstream words(s);
	while(words >> word)
	{
		last_w = word;
	}
	return word.size();
}

int main()
{
	cout << lengthOfLastWord("h") << endl;
	return 0;
}