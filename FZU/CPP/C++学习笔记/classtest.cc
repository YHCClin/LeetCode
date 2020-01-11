#include <iostream>
using namespace std;
// 内存对齐alignment
class A {
public:
	int a;
	char b;
	char e;
	char f;
	char d;
	char g;
};

class B : public A {
private:
	char c;
	//char d;
	//char e;
	//char f;
};

int main()
{
	B b;
	cout << sizeof(int) << endl;
	cout << sizeof(char) << endl;
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(b) << endl;
	return 0;
}