#include <iostream>
#include <string>
#include <map>
using namespace std;

int romanToInt(string s)
{
	if(s.empty())
		return 0;
	//建立键值映射
	std::map<string, int> kv = {{"I",1},{"V",5},{"X",10},{"L",50},{"C",100},{"D",500},{"M",1000},{"IV",4},{"IX",9},{"XL",40},{"XC",90},{"CD",400},{"CM",900}};

	int num = s.size();
	int ans = 0;
	for(int i = 0;i<num;)
	{
		int j = i + 1;
		string temp="";
		if(j < num)
		{
			temp.push_back(s[i]);
			temp.push_back(s[j]);
		}
		else
		{
			temp = s[i];
		}
		if(kv.count(temp)>0)
		{
			ans += kv[temp];
			i+=2;
		}
		else
		{
			string k(1,s[i]);
			ans += kv[k];
			i++;
		}
	}
	return ans;

}

int main()
{

	string s;
	cin >> s;
	cout << romanToInt(s) << endl;
	return 0;
}