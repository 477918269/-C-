#include<iostream>
#include<string>

using namespace std;
//void Test()
//{
//	string s("hellow world");
//	string::iterator it = s.begin();
//	
//	while (it != s.end())//�������÷�(��������������ʹ��)
//	{
//		cout << *it << endl;
//		it++;
//	}
//
//	for (auto ch : s) //��Χfor(��������������ʹ��,�ײ�����������)
//	{
//		cout << ch << " ";
//	}
//
//	string::reverse_iterator rit = s.rbegin();//�õ������������
//	while (rit != s.rend)
//	{
//		cout << *rit << " ";
//		it++;
//	}
//	string::const_iterator it = s.begin();//���const��
//	string::const_reverse_iterator it = s.rbegin();//�������const��
//	//4�ֵ����������򣬷���const������const�ͷ���
//	//C++11�� s.cbegin s.cend,s.crbegin,s.crend.
//
//	//���ռ���k/2������
//
//	//reserve�����������Ч��
//	//s.reserve
//		//resize���Ըı�size�Ĵ�С
//
//		//s.resize;
//}
void Test1()
{
	string s("123");
	int num = atoi(s.c_str);
	cout << num << endl;
}
//string::npos = -1;


void Test2()
{
	string url("http://www.cplusplus.com/reference/string/string/find/");
	size_t pos = url.find("://");

}
int main()
{
	Test1();
	system("pause");
	return 0;
}