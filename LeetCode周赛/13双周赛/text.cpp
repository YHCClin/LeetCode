#include <bits/stdc++.h>
using namespace std;

/************************************
void swap1(int a,int b)
{
	int temp = a;
	a = b;
	b = temp;
}
void swap2(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void swap3(int *a, int *b)
{
	int *temp = a;
	a = b;b = temp;
}
void swap4(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 10,b = 20;
	swap1(a,b);
	cout << a << ":" << b << endl;
	swap2(&a,&b);
	cout << a << ":" << b << endl;
	swap3(&a,&b);
	cout << a << ":" << b << endl;
	swap4(a,b);
	cout << a << ":" << b << endl;
	return 0;
}
************************************/

int main()
{
	int b[3][5] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int (*p)[5];
	p = b;
	for(int j = 0;j < 5;j++)
		cout << *(*p+j) << ",";
	cout << endl;
}
