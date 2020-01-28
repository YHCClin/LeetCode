#include <iostream>
using namespace std;

int main()
{
	int a = 100;
	int *p = new int(1);
	cout << *p << endl;
	cout << p << endl;
	delete p;
	p = NULL;
	cout << *p << endl;
	cout << p << endl;
}