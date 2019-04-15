#include<iostream>
#include<map>
#include<string>
using namespace std;

void Test()
{
	map<string, string> m{
		{ "apple", "ƻ��" },
		{ "banan", "�㽶" },
		{ "orange", "����" },
		{ "peach", "����" },
		{ "waterme", "ˮ����" } };
	auto it = m.begin();
	while (it != m.end())
	{
		cout << (*it).first << ":" << it->second << endl;
		it++;
	}
}

void Test1()
{
	map<string, string> m{
		{ "apple", "ƻ��" },
		{ "banan", "�㽶" },
		{ "orange", "����" },
		{ "peach", "����" },
		{ "waterme", "ˮ����" } };

	cout << m["apple"] << endl;
	cout << m["peach"] << endl;
	map<string, string> m1(m);

}

void Test2()
{
	map<string, long long> m;
	m["abc"] = 2;

	cout << m["abc"] << endl;
	cout << m.size() << endl;
}

void Test3()
{
	map<string, string> m;
	m.insert(pair<string, string>("peach", "����"));
	m.insert(pair<string, string>("apple", "ƻ��"));

	m["orange"] = "����";
	
	m.insert(m.find("banana"), make_pair("waterme", "ˮ����"));
	cout << m.size() << endl;

	for (auto& e : m)
		cout << e.first << ":" << e.second << endl;
	cout << endl;
	auto ret = m.insert(make_pair("peach", "��ɫ"));

	if (ret.second)
		cout << "<peach, ��ɫ>����map��, �Ѿ�����" << endl;
	else
		cout << "��ֵΪpeach��Ԫ���Ѿ����ڣ�" << ret.first->first << "--->" << ret.first->second\
		<< " ����ʧ��" << endl;

	m.erase("apple");
	for (auto& e : m)
		cout << e.first << ":" << e.second << endl;


}


void Test4()
{
	multimap<string, string> m{
		{ "apple", "ƻ��" },
		{ "banan", "�㽶" },
		{ "orange", "����" },
		{ "peach", "����" },
		{ "waterme", "ˮ����" } };

	m.insert(make_pair("apple", "��ƻ��"));
	cout << m.size() << endl;

	for (auto& e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

void Test5()
{
	multimap<int, int> m;

	for (int i = 0; i < 10; ++i)
		m.insert(make_pair(i, i));

	for (auto& e : m)
	{
		cout << e.first << ":" << e.second << endl;
	}
}

int main()
{
	Test5();
	system("pause");
}
