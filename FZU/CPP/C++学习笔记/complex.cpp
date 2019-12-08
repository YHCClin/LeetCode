#include <iostream>
#include <cstdio>
#include "COMPLEX.h"
using namespace std;

class Aanimous {
	public:
		Aanimous(string name) : name(name) {}
	private:
		string name;
};

int main()
{
	{static Complex c(1,2);} // 尽管越出作用域，c 任然不会被回收，知道程序结束
	Complex c1(2,3);
	{Complex c2(3,4);} // 调用构造后直接调用析构，因为生命周期结束（作用域结束）
	Complex c3(c1);
	cout << c3 << endl;;
	c1 += c1;
	cout << c1.getReal() << " + " << c1.getIm() << "i" << endl;
	c1 *= c1;
	cout << c1.getReal() << " + " << c1.getIm() << "i" << endl;
	cout << sizeof(c1) << endl;

	/*new 的细节操作*/
	Complex* pc = new Complex(1,2);

	/*相当于
	void* memo = operator new(sizeof(Complex)); // allocator memory， 内部调用malloc函数
	pc = static_cast<Complex*>(memo); // cast
	pc->Complex::Complex(1,2); // constructor   pc = this ,so it means that call *pc's constructor
	*/

	delete pc;
	return 0;
}