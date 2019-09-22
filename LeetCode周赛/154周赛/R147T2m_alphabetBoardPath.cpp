#include "Include_all.h"
using namespace std;

unordered_map<char,pair<int,int>> Alphmap;
void initialMap()
{
	char beg = 'a';
	for(int i=0;i < 6;i++)
	{
		for(int j = 0;j < 5;++j)
		{
			Alphmap[beg++] = make_pair(i,j);	
			cout << '[' << i << ',' << j << ']' << " ";
		}
		cout << endl;
	}
}
inline bool isEqual(pair<int,int> p1,pair<int,int> p2)
{
	if(p1.first == p2.first)
		return true;
	return false;
}
string alphabetBoardPath(string target) {
	initialMap();
	string res = "";
	int n = target.length();
	char cur = 'a';
	for(int i = 0;i < n;++i)
	{
		
		if(target[i] != 'z')
		{
			if(cur != target[i])
			{
				int x_gap = Alphmap[target[i]].first - Alphmap[cur].first;
				int y_gap = Alphmap[target[i]].second - Alphmap[cur].second;
				if(abs(x_gap)!=0)
				{
					if(x_gap < 0)
					{
						for(int j = 0;j < abs(x_gap);j++)
						{
							res+='U';
						}
					}
					else
					{
						for(int j = 0;j<abs(x_gap);j++)
						{
							res+='D';
						}
					}
				}
				if(abs(y_gap)!=0)
				{
					if(y_gap<0)
					{
						for(int j = 0;j<abs(y_gap);j++)
						{
							res+='L';
						}
					}
					else
					{
						for(int j = 0;j<abs(y_gap);j++)
						{
							res+='R';
						}
					}
				}
			}
			res+='!';
			cur = target[i];
		}
		else
		{
			//equal 'z'
			int y_gap = Alphmap[target[i]].second - Alphmap[cur].second;
			int x_gap = Alphmap[target[i]].first - Alphmap[cur].first;
			if(abs(y_gap)!=0)
			{				
				for(int j = 0;j<abs(y_gap);j++)
				{
					res+='L';
				}
			}
			if(abs(x_gap)!=0)
			{
				for(int j = 0;j < abs(x_gap);j++)
				{
					res+='D';
				}
			}
			res+='!';
			cur = target[i];
		}
	}
	return res;	
}

int main()
{
	initialMap();
	cout << alphabetBoardPath("leet")  << endl;
	/*
	cout << Alphmap['a'].first << " " << Alphmap['a'].second<< endl;
	cout << Alphmap['b'].first << " " << Alphmap['b'].second<< endl;
	cout << Alphmap['c'].first << " " << Alphmap['c'].second<< endl;
	cout << Alphmap['d'].first << " " << Alphmap['d'].second<< endl;
	cout << Alphmap['e'].first << " " << Alphmap['e'].second<< endl;
	cout << Alphmap['z'].first << " " << Alphmap['z'].second<< endl;
	cout << Alphmap['y'].first << " " << Alphmap['y'].second<< endl;
	cout << Alphmap['l'].first << " " << Alphmap['l'].second<< endl;
	*/
	return 0;
}