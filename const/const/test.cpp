#include<iostream>
#include"test1.cpp"
extern const int k;//��ȫ��������������const�����Ƕ���ö�����ļ���ȫ�ֱ���

using namespace std;

//class A
//{
//public:
//	//���е�const������Ҫͨ����ʼ������ֵ
//	A(int i)
//		:a(i)
//	{}
//	void Print();
//private:
//	const int a;
//};





//int& reval2 = ival;
int main()
{
	//const int i = 1000;
	//i = 100;
	//const int j, k = 100;
	//A a(1);
	//const int ival = 2019;
	//const int& reval = ival;
	//reval = 100
	//int i = 42; 
	//const int& r = 42;
	//const int& r1 = r + i;
	//cout << r1 << endl;

	//double i = 3.14;
	//const int& j = i;
	////ʵ��ת����
	//int la = i;
	//int k = i;//������ʽ����ת��
	//const int& j = k;

	//const int* a = new const int[100]();
	//const string* s = new string[100];

	//const double* cur;
	//const double pur = 1.2;
	//cur = &pur;
	
	int pur = 10;
	int* const cur = &pur;
	system("pause");

	return 0;
}