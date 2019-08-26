#include "Include_all.h"
using namespace std;
/****************************************************************
-----------------------我造了所有的轮子---------------------------

5167. 查询无效交易  显示英文描述  

用户通过次数 297
用户尝试次数 548
通过次数 304
提交次数 1868
题目难度 Easy
如果出现下述两种情况，交易 可能无效：

交易金额超过 ¥1000
或者，它和另一个城市中同名的另一笔交易相隔不超过 60 分钟（包含 60 分钟整）
每个交易字符串 transactions[i] 由一些用逗号分隔的值组成，这些值分别表示交易的名称，时间（以分钟计），金额以及城市。

给你一份交易清单 transactions，返回可能无效的交易列表。你可以按任何顺序返回答案。

 

示例 1：

输入：transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
输出：["alice,20,800,mtv","alice,50,100,beijing"]
解释：第一笔交易是无效的，因为第二笔交易和它间隔不超过 60 分钟、名称相同且发生在不同的城市。同样，第二笔交易也是无效的。
示例 2：

输入：transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
输出：["alice,50,1200,mtv"]
示例 3：

输入：transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
输出：["bob,50,1200,mtv"]
 

提示：

transactions.length <= 1000
每笔交易 transactions[i] 按 "{name},{time},{amount},{city}" 的格式进行记录
每个交易名称 {name} 和城市 {city} 都由小写英文字母组成，长度在 1 到 10 之间
每个交易时间 {time} 由一些数字组成，表示一个 0 到 1000 之间的整数
每笔交易金额 {amount} 由一些数字组成，表示一个 0 到 2000 之间的整数


****************************************************************/
struct tran{
	string name;
	int stamp;
	int amount;
	string city;
	tran(string name_,int stamp_,int amount_,string city_) \
	: name(name_), stamp(stamp_), amount(amount_), city(city_) {}
};
inline int _stoi(string str)
{
	int res = 0;
	int n = str.size();
	for(int i=0;i < n;++i)
	{
		int num = str[i]-'0';
		res = res*10 + num;
	}
	return res;
}
tran split(string translation,char sp)
{
	int n = translation.length();
	vector<string> strans(4,"");
	auto iter = translation.begin();
	for(int i = 0;i < 4;i++)
	{
		for(;iter != translation.end();iter++)
		{
			if(*iter != ',')
			{
				strans[i]+=(*iter);
			}
			else
			{
				iter++;
				break;
			}
		}
	}
	tran* t = new tran(strans[0],_stoi(strans[1]),_stoi(strans[2]),strans[3]);
	return *t;
}
vector<string> invalidTransactions(vector<string> transactions)
{
	int n = transactions.size();
	vector<string> res;
	vector<tran> trans;	
	set<string> ans;
	for(int i = 0;i < n;++i)
	{
		trans.push_back(split(transactions[i],','));
	}
	for(int j = 0;j < n;++j)
	{
		if(trans[j].amount > 1000)
		{
			ans.insert(transactions[j]);
		}
		for(int k = 0;k < n;++k)
		{
			if(trans[j].name==trans[k].name && abs(trans[j].stamp-trans[k].stamp)<=60 \
				&& trans[j].city!=trans[k].city)
			{
				ans.insert(transactions[j]);
			}
		}
	}
	res.assign(ans.begin(),ans.end());
	return res;
}
int main()
{
	vector<string> transactions = {"alice,20,800,mtv","alice,50,100,beijing"};
	vector<string> ans = invalidTransactions(transactions);
	for(string t : ans)
	{
		cout << t << endl;
		//cout << t.name << " " << t.stamp << " " << t.amount << " " << t.city << endl;	
	}
	
	return 0;
}