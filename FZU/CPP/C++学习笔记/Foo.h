#ifndef __FOO__
#define __FOO__

#include <iostream>
#include <string>

class Foo {
	public:
		int _id;
		long _data;
		std::string _str;

	public:
		Foo() : _id(0) {std::cout << "default ctor. this = " << this << " id = " << _id << std::endl;}
		Foo(int id) : _id(id) {std::cout << "ctor. this = " << this << " id = " << _id << std::endl;}

	//virtual    // 可选的 virtual 关键字
	~Foo() {std::cout << "dtor. this = " << this << " id = " << _id << std::endl;}

	static void* operator new(size_t size);
	static void operator delete(void* phead, size_t size);
	static void* operator new[](size_t size);
	static void operator delete[](void* phead, size_t size);
};

void* Foo::operator new(size_t size)
{
	Foo* p = (Foo*) malloc(size);
	std::cout << "Foo:new has been called." << std::endl;
	return p;
}

void Foo::operator delete(void* phead,size_t size)
{
	std::cout << "Foo:delete has been called." << std::endl;
	free(phead);
}

void* Foo::operator new[](size_t size)
{
	Foo* p = (Foo*) malloc(size);
	std::cout << "Foo:new[] has been called." << std::endl;
	return p;
}

void Foo::operator delete[](void* phead, size_t size)
{
	std::cout << "Foo:delete[] has been called." << std::endl;
	free(phead);
}

#endif // END DEFINE