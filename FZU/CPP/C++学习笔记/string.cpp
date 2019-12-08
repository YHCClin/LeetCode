#include <iostream>
#include "String.h"

using namespace std;

int main()
{
	String s1();
	String s2("hello");
	String s3(s2);
	String* p = new String("world");
	cout << s2;
	delete p; // delete调用*p的析构函数
	/*相当于
	String::~String(p); // 析构函数
	operator delete(p); // 内部调用free(p); 释放内存
	 */
	/*内存泄漏： 指针被销毁，但指针之前所指的空间区域没有被销毁*/
}