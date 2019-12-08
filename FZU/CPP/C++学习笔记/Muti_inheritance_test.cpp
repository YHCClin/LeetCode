#include "multi_inheritance.h"
#include <iostream>
using namespace std;

class A{
	int x;
	public:
		A(int a) : x(a) {cout << "Constructing" << endl;}
};

class B : public A{
	public:
		B() {cout << "Constructing" << endl;}
};

int main()
{
	SleepSofa ss;
	ss.setWeight(20);
	cout << ss.getWeight() << endl;

	B b;
	return 0;
}