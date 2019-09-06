#include "Include_all.h"
 
template<class T>
class Stack
{
	public:
		Stack(unsigned int size = 100);
		~Stack();

		void push(T value);
		void pop();
		T top();


	private:
		T *data;
		unsigned int sp = -1;
		unsigned int size;
};

template<class T>
Stack::Stack(unsigned int size = 100)
{
	this->size = size;
	this->data = new T[size];
}

template<class T>
Stack::~Stack()
{
	delete[] this->data;
}

template<class T>
void Stack::push(T value)
{
	if(this->sp < this->size)
		this->data[++(this->sp)] = value;
	cerr << "Stack overflow !" << endl;
}

template<class T>
void Stack::pop()
{
	if(this->sp >= 0)
		this->sp--;
	cerr << "Stack is empty!" << endl;
}

template<class T>
T Stack::top()
{
	if(this->sp>=0)
		return this->data[this->sp];
	cerr << "Stack is empty !" << endl;
}

int main()
{
	Stack<int> sta;
	return 0;
}