#include<iostream>
#include<string>
using namespace std;

//template<class T>
//class Smartptr
//{
//public:
//	Smartptr(T* ptr = nullptr)
//		:_ptr(ptr)
//	{
//	}
//
//	~Smartptr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//			cout << "delete[] "<< endl;
//		}
//	}
//
//private:
//	T* _ptr;
//};
//
//void Mersort(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int)* n);
//
//	Smartptr<int> sp(tmp);
//
//	string s("abcdefghijklnmopqrstuvwxyz");
//}
//double Division(int a, int b)
//{
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//
//void Func()
//{
//	int* array = new int[10];
//	memset(array, 0, sizeof(int)* 10);
//	Smartptr<int> s(array);
//
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;	
//}
//int main()
//{
//	try
//	{
//		Func();
//		//int a[5] = { 1, 2, 3, 4, 5 };
//		//Mersort(a, 5);
//	}
//
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	system("pause");
//}

/*template<class T>
class Smartptr
{
public:
	Smartptr(T* ptr = nullptr)
		:_ptr(ptr)
	{
	}

	~Smartptr()
	{
		if (_ptr)
		{
			delete _ptr;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}
private:
	T* _ptr;
};

struct Date
{
	int year;
	int month;
	int day;
};

int main()
{
	Smartptr<int> p(new int);
	*p = 10;
	cout << *p << endl;

	Smartptr<Date> p1( new Date);
	p1 -> year = 2019;
	p1 -> month = 3;
	p1 -> day = 31;
	system("pause");
}*/	

//#include<memory>
//
class Date
{
public:
	Date()
	{
		cout << "Date()" << endl;
	}
	~Date()
	{
		cout << "~Date" << endl;
	}
	int _year;
	int _month;
	int _day;
};
	

//int main()
//{
//	unique_ptr<Date> up(new Date);
//	unique_ptr<Date> copy(up);
//
//	system("pause");
//}

//int main()
//{
//	shared_ptr <Date> up(new Date);
//	shared_ptr <Date> copy(up);
//
//	cout << "count:" << up.use_count() << endl;
//	cout << "count:" << copy.use_count() << endl;
//
//	system("pause");
//}

//template<class T>
//class  AutoPtr
//{
//public:
//	AutoPtr(T* ptr = nullptr)
//		:_ptr(ptr)
//	{
//	}
//
//	~AutoPtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//		}
//	}
//	һ��������������ptr����Դת�Ƶ���ǰ�����У�Ȼ����ptr����������Դ������ϵ
//	������һ���ռ䱻�������ʹ��ʱ��ɵı������⡣
//	AutoPtr(AutoPtr<T>& ptr)
//		:_ptr(ptr._ptr)
//	{
//		ptr._ptr = NULL;
//	}
//
//	AutoPtr<T>& operator= (AutoPtr<T>& ptr)
//	{
//		if (this != &ptr)
//		{
//			if (_ptr)
//				delete _ptr;
//			_ptr = ptr._ptr;
//			ptr._ptr == NULL;
//		}
//		return *this;//operatorҪ�з���ֵ
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	T* _ptr;
//};
//
//int main()
//{
//	AutoPtr<Date> ap(new Date);
//	AutoPtr<Date> copy(ap);
//	ap->_year = 2019;
//	system("pause");
//}

//template<class T>
//class UniquePtr
//{
//public:
//	UniquePtr(T* ptr = nullptr)
//		:_ptr(ptr)
//	{
//	}
//
//	~UniquePtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//		}
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	//C++98��������ֻ������ʵ��+������˽��
//	UniquePtr(UniquePtr<T> cosnt &);
//	UniquePtr<T> operator= (UniquePtr<T> const &);
//	//C++11��������delete
//	UniquePtr(UniquePtr<T> cosnt &) = delete;
//	UniquePtr<T> operator= (UniquePtr<T> const &) = delete;
//private:
//	T* _ptr;
//};

template<class T>
class  SharedPtr
{
public:
	SharedPtr(T* ptr = nullptr)
		:_ptr(ptr)
		��_Rcount(new int(1))
	{
	}

	~SharedPtr()
	{
		if (_ptr)
		{
			delete _ptr;
		}
	}

	SharedPtr(SharedPtr<T>& ptr)
		:_ptr(ptr._ptr)
		, _Rcount(ptr._Rcount)
	{
		++(*_Rcount);//�����ռ�++
	}

	SharedPtr<T> operator= (SharedPtr<T>& s)
	{
		if (this != &s)
		//if(_ptr != s._ptr)
		{
			//�������ֵ��������Ϊ1�Ļ���ֱ�ӽ�ԭ�����ռ��ԭ��ַ�ͷ�
			if (--(*_Rcount) == 0)
			{
				delete _ptr;
				delete _Rcount;
			}
			//����ֵ�����ռ�͸�ֵ��ַ��������ֵ�����ռ�ͱ���ֵ��ַ
			_ptr = s._ptr;
			_Rcount = s._Rcount;
			//����++
			++(*_Rcount);
		}
	}
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;//ָ�������Դ��ָ��
	int* _Rcount;//���ü���
};