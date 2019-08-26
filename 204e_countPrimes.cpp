#include "Include_all.h"
using namespace std;

int countPrimes(int n)
{
	if(n==1 || n==2) return 0;
	int count = 0;
	bool p[n] = {false};

	for(int i = 2; i < n;i++)//遍历从2到n的数
	{
		if(p[i] == false)//若i为素数
		{
			count++;//将i添加到prime数组中
			for(int j = i+i;j < n;j+=i)//筛掉i的倍数
			{
				p[j] = true;
			}
		}
	}
	return count;

}
int countPrimes_(int n)
{
	if(n==0 || n==1 || n==2) return 0;
	for()
}

int main()
{
	int n;
	while(1)
	{
		cin >> n;
		cout << "Pi(n) is : " << countPrimes(n) << endl;
	}
	return 0;
}