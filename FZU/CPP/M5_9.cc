#include <iostream>
#include <string.h>
using namespace std;

class mystring {
public:
	char *pdata;
	mystring(int len)
	{
		pdata = new char[len + 1];
	}
	~mystring()
	{
		delete pdata;
	}
	void show()
	{
		cout << pdata << endl;
	}
};
// mystring* 为指向 mystring对象 的指针，mystring** 为指向mystring对象的指针的指针
void fun(mystring **array, int len)
{
	// old 为指向 mystring对象的指针
	mystring *old = *array;	// old 指向 array 指向的空间
	// 为 array 分配一块新的空间指向
	*array = new mystring(len);
	// 将 old 指向的空间内容复制到 array 指向的新空间中
	memcpy(*array, old, len);
} // 这个函数从头到尾没干啥实事儿，只是新建一个空间将 str 的值拷贝进去而已

int main()
{
	mystring str(20);
	mystring *pstr = &str;
	mystring **ppstr = &pstr;
	// ppstr -> pstr -> str;
	strcpy(str.pdata, "hello, FZU");
	fun(ppstr, 20);
	str.show();
	return 0;
}