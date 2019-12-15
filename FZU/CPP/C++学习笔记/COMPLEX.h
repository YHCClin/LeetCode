#ifndef __COMPLEX__
#define __COMPLEX__

#include <string>
#include <iostream>
#include <cmath>
// if no define 如果 __COMPLEX__ 没有被定义过
// define 定义 __COMPLEX__

typedef double T;
class Complex{
	friend bool operator==(const Complex& , const Complex& );
	friend bool operator!=(const Complex& , const Complex& );
	friend std::ostream& operator<<(std::ostream&,const Complex&);
	friend std::istream& operator>>(std::istream&,Complex&);
	public:
		Complex() = default;
		// Initialization list
		Complex(T r = 0, T i = 0) : re(r), im(i) {/*std::cout << "Constructor has been called" << std::endl;*/}
		// 析构函数
		~Complex() {/*std::cout << "destructor has been called" << std::endl;*/}
		// 拷贝构造函数
		Complex(const Complex &com){this->re = com.re; this->im = com.im;/*std::cout << "copy constructor has been called" << std::endl;*/}
		
		// 运算符重载
		Complex& operator+=(const Complex&);
		Complex& operator-=(const Complex&);
		Complex& operator*=(const Complex&);
		Complex& operator/=(const Complex&);
		Complex operator+(const Complex&);
		Complex operator-(const Complex&);
		Complex operator*(const Complex&);
		Complex operator/(const Complex&);
		
		//ostream& operator<<(ostream&, const Complex&);


		// this 默认为一个指向非常量对象的常量指针，若加了const 就将其变成了指向常量对象的指针
		// 如果不加 const 的话 若要访问常量对象的数据内容就无法过编译
		T getReal() const {return re;}
		T getIm() const {return im;};

	private:
		T re, im;
};

std::ostream& operator<<(std::ostream& os, const Complex& com)
{
	if(com.getIm() >= 0) return os << com.getReal() << " + " << com.getIm() << 'i';
	else return os << com.getReal() << com.getIm() << 'i';
}

std::istream& operator>>(std::istream& is,Complex& com)
{
	is >> com.re >> com.im;
	return is;
}

Complex& Complex::operator+=(const Complex& com)
{
	this->re += com.getReal();
	this->im += com.getIm();
	return *this;
}

Complex& Complex::operator-=(const Complex& com)
{
	this->re -= com.getReal();
	this->im -= com.getIm();
	return *this;
}

Complex& Complex::operator*=(const Complex& com)
{
	T real,imag;
	real = this->getReal()*com.getReal() - this->getIm()*com.getIm();
	imag = this->getReal()*com.getIm() + this->getIm()*com.getReal();
	this->re = real;
	this->im = imag;
	return *this;
}

Complex& Complex::operator/=(const Complex& com)
{
	T a = this->getReal(),c = com.getReal();
	T b = this->getIm(),d = com.getIm();
	T real = (a*c + b*d)/(pow(c,2)+pow(d,2));
	T imag = (b*c - a*d)/(pow(c,2)+pow(d,2));

	this->re = real;
	this->im = imag;
	return *this;
}

Complex Complex::operator+(const Complex& com)
{
	return Complex(this->getReal()+com.getReal(), this->getIm()+com.getIm());
}

Complex Complex::operator-(const Complex& com)
{
	return Complex(this->getReal()-com.getReal(), this->getIm()-com.getIm());
}

Complex Complex::operator*(const Complex& com)
{
	T real,imag;
	real = this->getReal()*com.getReal() - this->getIm()*com.getIm();
	imag = this->getReal()*com.getIm() + this->getIm()*com.getReal();
	return Complex(real, imag);
}

Complex Complex::operator/(const Complex& com)
{
	T a = this->getReal(),c = com.getReal();
	T b = this->getIm(),d = com.getIm();
	T real = (a*c + b*d)/(pow(c,2)+pow(d,2));
	T imag = (b*c - a*d)/(pow(c,2)+pow(d,2));

	return Complex(real, imag);
}

// 非成员函数
bool operator==(const Complex& a, const Complex& b)
{
	if(a.re == b.re && a.im == b.im)
		return true;
	else return false;
}

bool operator!=(const Complex& a, const Complex& b)
{
	if(a.re != b.re || a.im != b.im) return true;
	else return false;
}



// end of define
#endif