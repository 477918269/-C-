#include<iostream>

using namespace std;


double Division(int a, int b)
{
	if (b == 0)
		throw "Division by zero condition!";
	else
		return ((double)a / (double)b);
}

//void Func()
//{
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//}
//
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (...)
//	{
//		cout << "unknow exception" << endl;
//	}
//	system("pause");
//	return 0;
//}

//void Func()
//{
//	int* array = new int[10];
//	try
//	{
//		int len, time;
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (...)	
//	{
//		cout << "delete[]" << array << endl;
//		delete[] array;
//		throw;
//	}
//	cout << "delete[] " << array << endl;
//	delete[] array;
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	system("pause");
//}
//
////��ʾ������������׳�A/B/C���������͵��쳣
//void fun() throw(A, B, C);
////�����ʾ�������ֻ���׳�bad_alloc���쳣
//void operator* new(size_t size)throw(bad_alloc());
////�����ʾ���������׳��쳣
//void* operator new(size_t size, void* ptr) throw();
#include<vector>
int main()
{
	try
	{
		vector<int> v(10, 5);
		v.reserve(1000000000);

		v.at(10) = 100;

	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown Exception" << endl;
	}
	system("pause");
}