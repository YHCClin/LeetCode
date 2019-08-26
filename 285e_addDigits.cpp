#include "Include_all.h"
using namespace std;

int func(int n)
{
	int sum = 0;
	while(n)
	{
		sum += n%10;
		n = n/10;
	}
	return sum;
}

int addDigits(int num)
{
	while(num/10!=0)
	{
		num = func(num);
	}
	return num;
}
int main()
{
	cout << addDigits(38) << endl;
	return 0;
}