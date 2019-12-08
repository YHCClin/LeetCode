#ifndef __MULTIINHERIT__
#define __MULTIINHERIT__
#include <iostream>

class Furniture {
public:
	Furniture(int w) : weight(w) {}
	Furniture() = default;
	int getWeight() const { return weight; }
	//void setWeight(int weight) { weight = weight;}
private:
	int weight = 0;
};

class Bed : virtual public Furniture{
public:
	Bed(int w = 0) : weight(w) {}
	void sleep() {std::cout << "Sleeping ..." << std::endl;}
	//void setWeight(int w){weight = w;}
private:
	int weight = 0;
};

class Sofa : virtual public Furniture{
public:
	Sofa(int w = 0) : weight(w) {}
	void watchTV() {std::cout << "watchint TV" << std::endl;}
	//void setWeight(int w) {weight = w;}
private:
	int weight = 0;
};

class SleepSofa : public Sofa , public Bed {
public:
	SleepSofa() = default;
	SleepSofa(int w) : weight(w) {}
	void setWeight(int w) { weight = w; }
	int getWeight() const { return weight; }
	void foldOut() const {std::cout << "Fold out the sofa" << std::endl;}
private:
	int weight = 0;
};

#endif