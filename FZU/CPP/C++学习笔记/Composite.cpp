#include <iostream>
using namespace std;

class Base {
	public:
		Base()
		{
			cout << "Base's constructor called" << endl;
		}
		virtual ~Base(){
			cout << "Base's destructor called" << endl;
		}
};
class Component {
	public:
		Component()
		{
			cout << "Component's constructor called" << endl;
		}
		~Component()
		{
			cout << "Component's destructor called" << endl;
		}
};
class Derived : public Base {
	public:
		Derived()
		{
			cout << "Derived's constructor called" << endl;
		}
		~Derived()
		{
			cout << "Derived's destructor called" << endl;
		}
	private:
		Component c;
};

int main()
{
	Derived b;
	return 0;
}
/*
 构造： Base --> Component --> Derived
 析构： Derived --> Component --> Base

Base's constructor called
Component's constructor called
Derived's constructor called
Derived's destructor called
Component's destructor called
Base's destructor called
*/