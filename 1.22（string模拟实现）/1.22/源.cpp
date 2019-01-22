//#include"string.h"
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

	String(const String& s)//��������
		:_str(new char[strlen(s._str) + 1])
		,_size ( s._size)
		, _capacity(s._capacity)
	{
		strcpy(_str, s._str);
		
	}

	String& operator=(String s)//��ֵ����
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);

		return *this;
	}

	//String& operator=(const String& s)//��ͳд��
	//{
	//	if (this != &s)
	//	{
	//		delete[] _str;
	//		_str = new char[strlen(s._str) + 1];
	//		strcpy(_str, s._str);

	//	}
	//	return *this;
	//}

	bool operator == (const String& s)//�Ƚϴ�С
	{
		int size1 = strlen(this->_str);
		int size2 = strlen(s._str);
		if (size1 != size2)
			return false;
		for (int i = 0; i <= size1; i++)
		{
			if (this->_str[i] != s._str[i])
				return false;

		}
		return true;
	}
	bool operator != (const String& s)//�Ƚϴ�С
	{
		return !(*this == s);
	}

	bool operator <= (const String& s)//�Ƚϴ�С
	{
		return (*this < s) || (*this == s);
	}
	bool operator < (const String& s)//�Ƚϴ�С
	{
		int size1 = strlen(this->_str);
		int size2 = strlen(s._str);
		if (size1 < size2)
			return true;
		else
			return false;
		for (int i = 0; i <= size1; i++)
		{
			if (this->_str[i] > s._str[i])
				return false;

		}
		return true;
	}
	//bool operator => (const String& s);//�Ƚϴ�С
	bool operator > (const String& s)//�Ƚϴ�С
	{
		return !(*this <= s);
	}

	void Reserve(size_t n)
	{
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;		
	}

	void PushBack(char ch)//β��
	{
		if (_size == _capacity || _size + 1 == _capacity)
		{
			_capacity == 0 ? 4 : _capacity *= 2;
			Reserve(_capacity);
		}
		_str[_size] = ch;
		_size++;
		_str[_size] = '\0';
	}
	void Append(const char* str)//β��
	{
		int cur = strlen(str);
		if ((cur + _size) >= _capacity)
		{
			Reserve(_size + cur);
		}

		for (int i = 0; i <= cur; i++)
		{
			_str[_size++] = *str++;
		}
	}

	void Insert(size_t pos, char ch)//�ں���׷���ַ�
	{
		int end = _size - 1;
		if (_size == _capacity || _size + 1 == _capacity)
		{
			_capacity == 0 ? 4 : _capacity *= 2;
			Reserve(_capacity);
		}
		while (end >(int) pos)
		{
			_str[end] = _str[end - 1];
			end--;
		}
		_str[pos] = ch;
		_size++;
		_str[_size] = '\0';
	}

	void Insert(size_t pos, const char* ch)//�ں���׷���ַ���
	{
		int cur = strlen(ch);
		if (_size == _capacity || _size + 1 == _capacity)
		{
			_capacity == 0 ? 4 : _capacity *= 2;
			Reserve(_capacity);
		}
		int end = _size;
		while (end >(int)pos)
		{
			_str[end + cur -1] = _str[end - 1];
			end--;
		}
		for (int i = 0; i <= cur; i++)
		{
			_str[pos++] = *ch++;
		}


	}

	void Erase(size_t pos, size_t len)//��posλ��ɾ��len��
	{
		if (pos + len >= _size)
		{
			_size = pos;
			_str[_size] = '\0';

		}
		else
		{
			for (size_t i = pos + len; i < _size; i++)
			{
				_str[pos++] = _str[i];
			}
		}
	}

	String& operator+=(char ch)
	{
		PushBack(ch);
		return *this;
	}
	String& operator+=(const char* str)
	{
		Append(str);
		return *this;
	}
	size_t Find(char ch, size_t pos = 0)
	{
		for (int i = 0; i < _size; i++)
		{
			if (_str[i] == ch)
				return i - pos;
		}
		return -1;
	}
	size_t Find(const char* str, size_t pos = 0)
	{
		{
			for (int i = 0; i < _size; i++)
			{
				if (_str[i] == *str)
					return i - pos;
			}
			return -1;
		}
	}
	char* c_str()
	{
		return _str;
	}

	char& operator[](size_t pos)
	{
		//assert(pos < _size);

		return _str[pos];
	}

	size_t Size()
	{

		return _size;
	}

	size_t Capacity()
	{
		return _capacity;
	}

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

void Test1()
{
	
	String s2("hello world");
	String s1;
	s1 = s2;
	cout << s2 << endl;
	cout << s1 << endl;
	
}

void Test2()
{
	String s1("hello world");
	String s2("hello world");
	printf("%d\n", s1 == s2);
	printf("%d\n", s1 != s2);
	printf("%d\n", s1 < s2);
	printf("%d\n", s1 <= s2);
	printf("%d\n", s1 > s2);
	//printf("%d", s1 == s2);

}

void Test3()
{
	String s1("hello world");
	//s1.PushBack('a');
	/*s1.Append("abcd");*/
	
	printf("%d\n",s1.Find('e'));
	cout << s1;
}

int main()
{
	Test3();
	system("pause");
	return 0;
}