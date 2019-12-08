#include <iostream>
#include "Foo.h"

using namespace std;

int main()
{
	cout << "sizeof(Foo) = " << sizeof(Foo) << endl;

	Foo *p = new Foo(7);
	delete p;

	cout << "============================================" << endl;

	Foo* pArray = new Foo[5];
	delete[] pArray;

	cout << "********************************************" << endl;

	// 强制全局，不会打印出任何信息
	Foo* _p = ::new Foo(7);
	::delete[] _p;

	cout << "============================================" << endl;

	// 强制全局
	Foo *_pArray = new Foo[5];
	::delete[] _pArray;

	return 0;
}