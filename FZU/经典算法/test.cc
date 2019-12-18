#include <iostream>
#include <string>
using namespace std;
unsigned int CountBit(unsigned long long &n)
{
	unsigned int cnt = 0;
	while(n)
	{
		cnt++;
		n = n & (n - 1);
	}
	return cnt;
}
int main()
{
	int len;
	unsigned long long a = 0x800000000;
	cin >> len;
	cout << ((len + 8 * sizeof(unsigned long long)-1) / sizeof(unsigned long long) / 8) << endl;
	cout << CountBit(a) << endl;
	cout << a << endl;
	return 0;
}