#include "Include_all.h"
using namespace std;

int func(int n)
{
	int temp = n;
	int x,sum = 0;
	while(temp)
	{
		x = temp%10;
		sum += pow(x,2);
		temp = temp/10;
	}
	return sum;
}
bool isHappy(int n)
{
	if(n==1 || n==7) return true;
	if(n<10 && n!=1 && n!=7) return false;
	int i = 0;
	while(i < 10)
	{
		n = func(n);
		if(n==1)
		{
			return true;
		}
		++i;
	}
	return false;
}

int main()
{
	cout << isHappy(19) << endl;
	return 0;
}