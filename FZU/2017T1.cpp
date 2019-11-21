#include <bits/stdc++.h>
using namespace std;

//时间复杂度为O(log n),表示整数n的位宽
int binaryCount_1(int n)
{
	int i = 0;
	int cnt = 0;
	while(n >> (i++))
	{
		if(n & 1)
			cnt++;
	}
	return cnt;
}
// 时间复杂度只与二进制中 1 的个数有关
int binaryCount_2(int n)
{
	int cnt = 0;
	while(n)
	{
		cnt++;
		n = n & (n-1);
	}
	return cnt;
}

// 时间复杂度为 O(1)
int binaryCount_3(int n)
{
	int Ready[16] = {
		0,1,1,2,1,
		2,2,3,1,2,
		2,3,2,3,3，4
	};
	return Ready[n];
}
int main()
{
	cout << binaryCount_1(7) << endl;
	cout << binaryCount_2(7) << endl;
	cout << binaryCount_3(7) << endl;
	return 0;
}