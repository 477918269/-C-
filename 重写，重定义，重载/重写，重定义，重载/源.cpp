#include<iostream>

using namespace std;

class Person
{
private:
	virtual void id()
	{
		cout << "id()" << endl;
	}

	void name()
	{
		cout << "name" << endl;
	}
public:
	void all()
	{
		id();
		name();
	}
	void fun1(string a)
	{
		cout << "Person(fun1 string)" << endl;
	}
	void fun1(int a)//����fun1��Person�ĺ�����Χ�ڱ�������
	{
		cout << "Person(fun1 int)" << endl;
	}

};

class student :public Person
{
public:
	void id()//�����е�idΪ�麯�����˴�Ϊ��д
	{
		cout << " student id()" << endl;
	}

	void fun1(int a, int b)//fun1��Ϊ�麯�����˴�Ϊ�ض���
	{
		cout << "student fun1(int a, int b)" << endl;
	}

	void name()
	{
		cout << "student name()" << endl;
	}

};

int main()
{
	student s;
	Person *p = &s;
	p->all ();
	s.all();
	s.name();
	system("pause");


}


