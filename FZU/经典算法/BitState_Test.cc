#include <iostream>
#include "BitState.h"
using namespace std;

int main()
{
	BitState bitset(100, 0ULL);
	bitset.reset();
	cout << bitset.none() << endl;
	cout << bitset.any() << endl;
	bitset.set(10);
	cout << bitset.none() << endl;
	cout << bitset.any() << endl;
	bitset.reset(10);
	cout << bitset.none() << endl;
	cout << bitset.any() << endl;
	bitset.set(98);
	bitset.set(80);
	cout << bitset.test(97) << endl;
	cout << bitset.test(98) << endl;
	cout << bitset.count() << endl;
	bitset.flip(98);
	cout << bitset.test(98) << endl;
	cout << bitset.count() << endl;
	return 0;
}