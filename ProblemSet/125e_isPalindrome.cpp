#include "Include_all.h"
using namespace std;

bool isPalindrome(string &s)
{
	int len = s.size();
        int i = 0,j = len -1,k = 0;
        
        int flag = 0;
        while(k < len)
        {
            if(isalpha(s[k]))
            {
                flag++;
                s[k] = tolower(s[k]);
            }
            k++;
        }
        
        if (flag == 0)
        {
            return true;
        }
        else if(flag==1)
        {
        	return true;
        }
        while(i < j)
        {
            while(!isalpha(s[i]) && i<j)
            {
                i++;
            }
            while(!isalpha(s[j]) && i<j)
            {
                j--;
            }
            if(isalpha(s[i]) && isalpha(s[j]))
            {
                cout << s[i] << s[j] << endl;
                if(s[i]==s[j])
                {
                    i++;
                    j--;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
}

int main()
{
	string s = "OP";
	cout << s << endl;
	cout << isPalindrome(s) << endl;
	return 0;
}