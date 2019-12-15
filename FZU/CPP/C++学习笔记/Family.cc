#include <bits/stdc++.h>
using namespace std;

class Family {
public:
	virtual void Drive(){};
	virtual void FixTv(){};
	virtual void Sing(){};
};

class Father : virtual public Family {
public:
	virtual void Drive()
	{
		cout << "Father Driveing" << endl;
	}
	virtual void FixTv()
	{
		cout << "Father Fixing" << endl;
	}
};

class Mather : virtual public Family {
public:
	virtual void Sing()
	{
		cout << "Mather Singing" << endl;
	}
	void doWork()
	{
		cout << "Mather Working" << endl;
	}
};

class Child : virtual public Family {
public:
	virtual void Sing()
	{
		cout << "Child Singing" << endl;
	}
	virtual void Drive()
	{
		cout << "Child Driving" << endl;
	}
	virtual void FixTv()
	{
		cout << "Child Fixing" << endl;
	}
	void playPin()
	{
		cout << "Child playing PinPong" << endl;
	}
};


int main()
{
	Father f;
	Mather m;
	Child  c;
	f.Drive();
	m.Sing();
	c.playPin();
	c.Drive();
	c.Sing();
	c.FixTv();
	f.FixTv();
}