#include<iostream>

using namespace std;

//���μ̳�
class Person
{
public:
	string _name;
};

class Student : virtual public Person//��������̳н�����μ̳еĶ����Ժ�������
{
protected:
	int _num;
};

class Teacher : virtual public Person
{
protected:
	int _id;
};

class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse;
};
//
//void Test()
//{
//	Assistant a;
//	//�޷����ʣ����ڶ�����
//	//a._name = "aoliao";
//	//��Ҫָ�������ĸ�����ĳ�Ա���Խ�������ԣ����Ǵ����������������
//	a.Student::_name = "aoliao";
//	a.Teacher::_name = "maliao";
//
//
//}

//class A
//{
//public:
//	int _a;
//};
////class B : public A
//class B : virtual public A
//{
//public:
//	int _b;
//};
//
////class C : public A
//class C : virtual public A
//{
//public:
//	int _c;
//};
//
////class D : public B, public C
//class D : public B, public C
//{
//public:
//	int _d;
//};
//
//void Test()
//{
//	Assistant a;
//	a._name = "aoliao";
//}
//
//void Test1()
//{
//	D d;
//	d.B :: _a = 1;
//	d.C :: _a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//}

class Base1
{
public:
	int _a;
};

class Base2
{
public:
	int _b;
};

class Derive : public Base1, public Base2
{
public:
	int _c;
};



int main()
{
	Derive d;
	Base1* p1 = &d;
	Base2* p2 = &d;
	Derive* p3 = &d;

	system("pause");
	return 0;
}