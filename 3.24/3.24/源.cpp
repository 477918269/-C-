#include<iostream>

using namespace std;

//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "֧�����Ʊ" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	void BuyTicket()//���淶д��
//		
//	virtual void BuyTicket()
//	{
//		cout << "֧��ȫ��Ʊ" << endl;
//	}
//};
//
//class A
//{};
//
//class B : public A
//{};
//
//class Person
//{
//public:
//	virtual A* f()
//	{
//		return new A;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual B* f()
//	{
//		return new B;
//	}
//};



//void Func(Person& people)
//{
//	people.BuyTicket();
//}



//void Test()
//{
//	Person p;
//	Func(p);
//
//	Student s;
//	Func(s);
//}

//class Person
//{
//public:
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual ~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//};

//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//
//class Benz : public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz Good" << endl;
//	}
//};

//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//
//class Benz : public Car
//{
//public:
//	virtual void Drive() override
//	{
//		cout << "Benz Good" << endl;
//	}
//};

//������override�����ֱ�ʾ��ǰ������д�˻�����麯����
//Ŀ�ģ�1.�ں����Ƚ϶������¿�����ʾ����ĳ��������д�˻����麯������ʾ����麯���Ǵӻ���̳У������������Լ�����ģ���2.ǿ�Ʊ��������ĳ�������Ƿ���д�����麯�������û���򱨴�
//�÷�������ĳ�Ա���������б������Ӹùؼ��ּȿɡ�
//���ӣ�
//class Base ��
//	virtual void f();
//}��
//class Derived : public Base {
//	void f() override; // ��ʾ��������д�����麯��f
//	void F() override;//���󣺺���Fû����д�����κ��麯��
//}��
//ע�⣺overrideֻ��C++�����֣����ǹؼ��֣�����ζ��ֻ������ȷ��ʹ��λ�ã�oerride�������ؼ��֡������ã������ط�������Ϊ��־�����磺int override���ǺϷ��ģ���

//final�ؼ���
	//class Car
	//{
	//public:
	//	virtual void Drive() final;
	//};
	//
	//class Benz : public Car
	//{
	//public:
	//	virtual void Drive() override
	//	{
	//		cout << "Benz Good" << endl;
	//	}
	//};

//class Base
//{
//public:
//	virtual void Func()
//	{
//		cout << "Func() " << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Fun2()" << endl;
//	}
//protected:
//	int _b = 1;
//};
//
//class Drive : public Base
//{
//public:
//	virtual void Func()
//	{
//		cout << "Drive :: Func" << endl;
//	}
//	virtual void Ala()
//	{
//	}
//protected:
//	int _d = 2;
//};

class Base
{
public:
	virtual void Func()
	{
		cout << "Base::Func() " << endl;
	}

	virtual void Func2()
	{
		cout << "Base::Fun2()" << endl;
	}

	virtual void Func3()
	{
		cout << "Base::Fun3()" << endl;
	}
private:
	int _b = 1;
};

class Drive : public Base
{
public:
	virtual void Func()
	{
		cout << "Drive :: Func" << endl;
	}
private:
	int _d = 2;
};

int main()
{
	//Person* p1 = new Person;
	//Person* p2 = new Student;

	//delete p1;
	//delete p2;
	//Benz b;
	//b.Drive();
	Base b;
	Drive d;
	/*printf("%d", sizeof(d));*/
	system("pause");
	return 0;
}