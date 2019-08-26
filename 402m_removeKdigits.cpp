#include "Include_all.h"
using namespace std;
//贪心算法
string removeKdigits(string num,int k)
{
	vector<int> sta;
	int temp;
	string res = "";
	for(int i = 0;i < num.size();++i)
	{
		temp = num[i] - '0';
		//若栈不空且栈顶元素大于当前遍历元素且还未删除k个数字，出栈（用较小的低位数字代替高位数字）
		while(!sta.empty() && temp<sta.back() && k>0)
		{
			sta.pop_back();
			k--;
		}
		//否则的话只要当前遍历元素不为0或栈不空，进栈
		if(temp != 0 || !sta.empty())
		{
			sta.push_back(temp);
		}
	}
	//遍历完毕还可删除元素则逐个删除末尾的元素
	while(k>0 && !sta.empty())
	{
		sta.pop_back();
		k--;
	}
	//将结果栈内容转为字符串
	for(auto i : sta)
	{
		res += i + '0';
	}
	if(res=="") return "0";
	return res;
}

int main()
{
	string num = "14320054532043506003530";
	int k = 10;
	cout << removeKdigits(num,k) << endl;
	return 0;
}