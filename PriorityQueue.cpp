#include "Include_all.h"
using namespace std;

struct Person{
	string name;
	int age;
	Person(string n,int a) : name(n), age(a) {}
};
//自定义排序规则
struct LessThanByAge{
	bool operator()(const Person& a,const Person& b)
	{
		return a.age > b.age;//小顶堆(>),大顶堆(<)
	}
};

int main()
{
	priority_queue<Person,vector<Person>,LessThanByAge> Q;
	Person p1 =  Person("lin",23);
	Person p2 =  Person("chen",21);
	Person p3 =  Person("wang",18);
	Person p4 =  Person("li",25);
	Q.push(p1);
	Q.push(p2);
	Q.push(p3);
	Q.push(p4);
	while(!Q.empty())
	{
		cout << Q.top().name << " " << Q.top().age << endl;
		Q.pop();
	}
}