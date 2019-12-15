#include <bits/stdc++.h>
using namespace std;

class A {
public:
	int getpA() { return pA;}
	void setpA(int a_) { pA = a_;}
private:
	int pA;
};

class B : public virtual A {
public:
	void onB() {cout << "on B" << endl;}
};

class C : public virtual A, public B {
public:
	void sc() {cout << "Cf" << endl;}
};


int main()
{
	C c;
	c.setpA(6);
	cout << c.getpA() << endl;
	c.onB();
}