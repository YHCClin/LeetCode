#include <iostream>
#include <cstdio>
#include "COMPLEX.h"
using namespace std;


int main()
{
	Complex c1(2,3);
	Complex c2(3,4);
	Complex c4(c1);
	cout << c4 << endl;
	cout << c1+c2 << endl;
	cout << (c1==c2 ? "equel" : "unequal") << endl;
	Complex c3 = c1+c2;
	cout << "c1 + c2 = " << c3 << endl;
	cout << (c2/=c3) << endl;
	cout <<  (c3*=c1) << endl;
	cout << (c1+=c2) << endl;
	cout << (c1-=c2) << endl;
	cout << (c1!=c2) << endl;

	// input
	Complex c5(0,0);
	cin >> c5;
	cout << c5 << endl;
	 cout << __cplusplus;
	return 0;
}