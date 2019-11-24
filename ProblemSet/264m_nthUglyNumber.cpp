

#include "Include_all.h"
using namespace std;

//可以发现后面的丑数都可以由前面的丑数2，3，5乘来的，
//但是如果直接做乘法得到后面的丑数的话得到的丑数是
//乱序的，因此应该控制每次得到的丑数都为当前的最小值，
//才将其纳入结果数组

int nthUglyNumber(int n)
{
	//分配数组空间存储n个丑数
	int *res = new int[n];
	//已知第一个丑数为1
	res[0] = 1;
	//定义三个指向前面（已生成）的丑数的指针
	int *ugly2 = res;
	int *ugly3 = res;
	int *ugly5 = res;
	int next = 1;
	//记录每次乘积的最小值
	int Min;

	//开始递推地由已知推出未知
	while(next < n)
	{
		//将前面的丑数与2，3，5相乘并取最小的乘积值
		Min = min(min(*ugly2 * 2,*ugly3 * 3),*ugly5 * 5);
		res[next] = Min;

		//排除重复项并指向正确的位置，
		//这里所谓正确的位置就是为了保证下一次乘积的值都不会小于等于前面的任何丑数
		//这样也就保证了不会出现重复项
		while(*ugly2 * 2 <= res[next])
			++ugly2;
		while(*ugly3 * 3 <= res[next])
			++ugly3;
		while(*ugly5 * 5 <= res[next])
			++ugly5;

		++next;
	}
	return res[n-1];

}

int main()
{
	int n;
	while(1)
	{
		cin >> n;
		cout << nthUglyNumber(n) << endl;	
	}
	
	return 0;
}