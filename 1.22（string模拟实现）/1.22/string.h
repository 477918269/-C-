
#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
using namespace std;


class String
{
public:
	String(char* s = "")//���캯��
	{
		if (s == nullptr)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(s) + 1];
		_size = strlen(s);
		_capacity = strlen(s) + 1;
		strcpy(_str, s);
	}

	~String()//��������
	{
		if (this)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

	String(String& s)//��������
		:_str( new char[strlen(s._str) + 1])
	{
		swap(_str, s._str);
	}

	String& operator=(String s);//��ֵ����
	bool operator == (const String& s);//�Ƚϴ�С
	bool operator != (const String& s);//�Ƚϴ�С
	bool operator <= (const String& s);//�Ƚϴ�С
	bool operator < (const String& s);//�Ƚϴ�С
	//void operator => (const String& s);//�Ƚϴ�С
	bool operator > (const String& s);//�Ƚϴ�С

	void PushBack(char ch);//ͷ��
	void Append(const char* str);//β��
	void Insert(size_t pos, char ch);//�ں���׷���ַ�
	void Insert(size_t pos,  const char* ch);//�ں���׷���ַ���
	void Earse(size_t pos);//ɾ��pos��
	void Find(char a);//����A���ڵ�λ��
	void operator+=(const String& s);
	void CheckCP();
	friend ostream& operator<<(ostream& _cout, const String& s)
	{
	
		cout << s._str;
		return _cout;
	}
private:
	char* _str;
	size_t _size;
	size_t _capacity;

	const static size_t npos;
};

//void Test1()
//{
//	
//	String s2("hello world");
//	String s1;
//	s1 = s2;
//	cout << s2 << endl;
//	cout << s1;
//}

