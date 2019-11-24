#include "Include_all.h"
using  namespace std;

string reverseStr(string s,int k)
{
	return s;
}

 string reverseVowels(string s) {
        int n = s.size();
        vector<char> vowel{'a','e','i','o','u'};
        int i = 0;
        int j = n-1;
        char temp;
        while(i < j)
        {
            while( i < j && !count(vowel.begin(),vowel.end(),s[i])) i++;
            while( i < j && !count(vowel.begin(),vowel.end(),s[j])) j--;
            if(i < j)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            }
        }
        return s;
    }
int main()
{
	string s = "leetcode";
	cout << reverseVowels(s) << endl;
	return 0;
}