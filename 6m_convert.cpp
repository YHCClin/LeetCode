#include "Include_all.h"
using namespace std;

string convert(string s, int numRows) {
        //我有一个大胆的想法
		//有限状态自动机实现
        string result = "";
        if(s.size()==0 || s.size()==1 || s.size()==2)
            return s;
        if(numRows==1)
            return s;
        if(numRows==2)
        {
            for(int i=0;i < s.size();i+=2)
                result += s[i];
            for(int j = 1;j < s.size();j+=2)
                result += s[j];
            return result;
        }
		int len = s.size();
		int x = numRows;
		int y = len*(x-1)/(2*x-2);
		char charGraph[numRows][y];
		for(int i = 0;i < numRows;i++)
			for(int j = 0;j < y;j++)
			{
				charGraph[i][j] = '.';
			}
		int i = 0,j = 0;
		int k = 0;
		const int DOWN = 0;
		const int LEAN = 1;
		int STARUS = DOWN;
		while(k < s.size())
		{
			switch(STARUS)
			{
				case DOWN:
					while(k < s.size())
					{
						if(i==numRows-1)
						{
							charGraph[i][j]=s[k];
							STARUS = LEAN;
							j++;
							i--;
							k++;
							break;
						}
						charGraph[i][j] = s[k];
						i++;
						k++;
					}
					break;
				case LEAN:
					while(k < s.size())
					{
						if(i==0)
						{
							STARUS = DOWN;
							break;
						}
						charGraph[i][j] = s[k];
						j++;
						i--;
						k++;
					}
					break;
			}
		}
		for(int i = 0;i < numRows;i++)
		{
			for(int j = 0;j < y;j++)
			{
				cout << charGraph[i][j] << " ";
			}
			cout << endl;
		}
		for(int i = 0;i < numRows;i++)
			for(int j = 0;j < y;j++)
			{
				if(charGraph[i][j]!='.')
					result+=charGraph[i][j];
			}
		return result;
    }
int main()
{
	string s = "ABCDE";
	cout << convert(s,3) << endl;
	return 0;
}