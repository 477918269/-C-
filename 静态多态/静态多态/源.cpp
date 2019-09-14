#include<iostream>

using namespace std;
class Base
{
public:
	virtual void fun()
	{
		cout << "Base::fun()" << endl;
	}
};

class Derive : public Base
{
public:
	void fun()
	{
		cout << "Derive::fun()" << endl;
	}
};

void Test1()
{
	Base b;
	Derive d;

	Base* pb = &b;
	Derive* pd = &d;

	pb->fun();
	pd->fun();

	pb = &d;//ͨ��ָ�룬��Ҫ����Derive�е�fun()
	pb->fun();

	Base& rb = b;
	Derive& rd = d;

	rb.fun();
	rd.fun();

	Base& rb2 = d;//ͨ�����ã���Ҫ����Derive�е�fun()
	rb2.fun();
}

int main()
{
	Test1();
	system("pause");
	return 0;
}