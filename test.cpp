#include "Include_all.h"
#include<cstdio>
using namespace std;

int &func(int &a);

vector<int> findMax(vector<int> &arr)
{
	int Max = INT_MIN;
	int Min = INT_MAX;
	for(int i = 0; i < arr.size();i++)
	{
		if(arr[i] > Max) Max = arr[i];
		if(arr[i] < Min) Min = arr[i];
	}
	return {Max, Min};
}

int main(){
	int i = 2, j = 4, m,n;
	m = ++i + j++;
	n = (++i)+(j++) + m;
	cout << i << j << m << n << endl;
	short b = 15;
	b <<= 15;
	cout << b << endl;
	vector<int> arr = {2,3,3,4,3,5,34,1,5,32};
	vector<int> res(findMax(arr));
	for(auto p : res)
		cout << p << " ";

	int a = 15;
	a <<= 15;
	printf("%x",a);
	return 0;
}
<script type="text/javascript" src="//rf.revolvermaps.com/0/0/0.js?i=0xetp0d4rdh&amp;d=2&amp;p=1&amp;b=8&amp;w=193&amp;g=2&amp;f=arial&amp;fs=12&amp;r=0&amp;c0=000000&amp;c1=00a99d&amp;c2=000000&amp;ic0=0&amp;ic1=0" async="async"></script>