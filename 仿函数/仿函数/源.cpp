#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//
//class Mul2
//{
//public:
//	void operator()(int& date)
//	{
//		date <<= 1;
//	}
//};
//
//class Mul3
//{
//public:
//	bool operator()(int& date)
//	{
//		return 0 == date % 3;
//	}
//};

int main()
{
	//vector<int> v{ 1, 2, 3, 4, 5, 6 };
	//for_each(v.begin(), v.end(), Mul2());//һ�������ʹ�õ�ʱ���ǰ�first��Ϊ������������ʼ��ָ�룬last��������ĩβ���ص���functor(�º���)��
	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	//auto pos = remove_if(v.begin(), v.end(), Mul3());
	//v.erase(pos, v.end());

	////������Թ��ܼ򵥵Ĳ�����������C++11�ṩ��lambda��ʾ�����
	////lambda���ʽʵ�ּ򵥣����ڵײ�ͷº�����ͬ���������Ὣlambdaת��Ϊ�º���

	//for_each(v.begin(), v.end(), [](int date){cout << date << " "; });
	//cout << endl;


	cout << 10 / 10 << endl;
	system("pause");
}