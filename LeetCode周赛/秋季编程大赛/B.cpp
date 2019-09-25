#include "Include_all.h"
using namespace std;

//分数结构体
struct frac{
		int n;
		int m;
};
int common_mult(int x,int y)    //辗转相减求最小公倍数 
{
	int a=x,b=y;
	while(x!=y)
	{
		if(x>y)
		{
			x=x-y;
		}else
			{
				y=y-x;
			}
	} 
	return a*b/x;
}
//分数和函数
frac Sum(frac a,frac b,frac& res)
{
	if(a.m == b.m)
	{
		res.n = a.n + b.n;
		res.m = a.m;
	}
	else
	{
		int cm = common_mult(a.m,b.m);
		res.m = cm;
		res.n = (cm/a.m)*a.n + (cm/b.m)*b.n;
	}
	return res;
}
//迭代法，也可以递归
vector<int> fraction(vector<int>& cont) {
	int len = cont.size();
	frac res;
	res.m = cont[len-1];res.n = 1;
	for(int i = len-2;i >= 0;--i)
	{
		if(cont[i] != 0)
		{
			frac cur;
			//取倒数
			cur.n = cont[i];
			cur.m = 1;
			//与下一个数求和
			Sum(cur,res,res);
		}
		//求和后再取倒数
		int temp = res.n;
		res.n = res.m;
		res.m = temp;
	}
	vector<int> result = {res.m,res.n};
	return result;
}
int main()
{
	vector<int> cont = {3,2,0,2};
	vector<int> res(fraction(cont));
	cout << res[0] << " / " << res[1] << endl;
	return 0;
}