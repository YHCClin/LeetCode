#ifndef __STRING__
#define __STRING__

#include <iostream>
#include <cstring>
// Big Three
// class 里面有指针，多数要使用动态分配内存
class String{
	// class with pointer members
	public:
		String(const char* cstr);
		// 若不定义拷贝构造函数，靠编译器自动生成，对于这个类，那只是浅拷贝（只拷贝指针）
		String(const String& str /*蓝本*/); // copy constructor
		// 拷贝赋值函数
		String& operator=(const String& str); // copy assignment operator
		~String(); // destructor

		char* get_c_str() const {return m_data;}
	private:
		char* m_data;
};

inline
String::String(const char* cstr = 0)
{
	if(cstr)
	{
		m_data = new char[strlen(cstr)+1]; // '\0' -> +1
		strcpy(m_data, cstr); // copy cstr to m_data
	}
	else // unassigned the initial value
	{
		m_data = new char[1];
		*m_data = '\0';
	}
}

inline
String::String(const String& str)
{
	m_data = new char[strlen(str.m_data)+1];
	strcpy(m_data, str.m_data);
}

inline
String& String::operator=(const String& str)
{
	if(this == &str) return *this; // 检测自我拷贝 s1 = s1;

	delete[] m_data;
	m_data = new char[strlen(str.m_data)+1]; // reallocate
	strcpy(m_data,str.m_data);
	return *this;
}

inline
String::~String()
{
	// new 与 delete 成对出现
	delete [] m_data;
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
	os << str.get_c_str();
	return os;
}



#endif