#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<initializer_list>
using namespace std;

//class Date
//{
//public:
//
//	Date(int year, int month, int day)
//	:_year(year),
//	_month(month),
//	_day(day)
//	{
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//template<class T>
//class Vector
//{
//
//}

//int main()
//{
//	//int a[] = { 1, 2, 3, 4 };
//	//vector<int> v{1,2,3,4};
//	//Date d = { 1999, 6, 8 };
//	//for (auto e : v)
//	//{
//	//	cout << e << endl;
//	//}
//
//	//for (auto e : a)
//	//{
//	//	cout << e << endl;
//	//}
//	//����
//	//int x1 = { 10 };
//	//int x2{ 10 };
//	//int x3 = 1 + 2;
//	//int x4{ 1 + 2 };
//	//int x5 = { 1 + 2 };
//	////����
//	//int a1[5] = { 1, 2, 3, 4, 5 };
//	//int a2[] = { 1, 2, 3, 4, 5 };
//
//	//int* a3 = new int[5] {1, 2, 3, 4, 5};
//
//	////STL����
//	//vector<int> v{ 1, 2, 3, 4 };
//	//map<string, int> m{ { "ƻ��", 5 }, { "����", 10 } };
//
//	system("pause");
//	return 0;
//
//}

//void* ALA(int size)
//{
//	return malloc(size);
//}

//int main()
//{
//	//û�д����������ݺ���������
//	//cout << typeid(decltype(ALA)).name() << endl;
//	////���˲������Ƶ����Ǻ�������ֵ�����ͣ�ע�⣺�˴�ֻ�����ݣ���ִ�к���
//	//cout << typeid(decltype(ALA(0))).name() << endl;
//	//map<string, int> m{ { "ƻ��", 5 }, { "����", 10 } };
//	//map<string, int> ::iterator it = m.begin();
//	//auto it = m.begin();
//
//
//	//short a = 32670;
//	//short b = 32670;
//
//	//decltype(a + b) c;
//	//cout << typeid(c).name() << endl;
//	
//
//	system("pause");
//	return 0;
//}

//class Date
//{
//public:
//	Date()
//		:_year(0),
//		_month(0),
//		_day(0)
//	{}
//
//	Date(int year)
//		:Date()
//	{
//		_year = year;
//	}
//
//	Date(int month)
//		:Date()
//	{
//		_month = month;
//	}
//private:
//	int _year = 1999;
//	int _month = 6;
//	int _day = 8;
//};

//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//	//��ʾȱʡ�������ɱ���������
//	A() = delete;
//	//�����������������ⶨ��ʱ�ñ���������Ĭ�ϸ�ֵ���������
//	A& operator= (const A& a) = delete;
//private:
//	int _a;
//};
//
////A& A::operator=(const A& a) = delete;
//
//
//int main()
//{
//	A a1(10);
//	//ʧ�ܣ���Ϊû����ʽ�Ĺ��캯��
//	//A a2;
//	//ʧ�ܣ���Ϊû�и�ֵ���������
//	//a2 = a1;
//	return 0;
//
//}


int main()
{
	int a = 10;
	int &lr = a;
	const int&& rr = 10;
	return 0;
}	