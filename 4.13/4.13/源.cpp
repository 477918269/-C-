#include<iostream>
#include<map>

using namespace std;

void TestMap()
{
	map<string, string> m{ 
							{ "apple", "ƻ��" }, 
							{ "banan", "�㽶" }, 
							{ "orange", "����" }, 
							{ "peach", "����" }, 
							{ "waterme", "ˮ����" } 
							};
	for (auto it = m.begin(); it != m.end(); it++)
	{
		cout << (*it)->first << ":" << (*it)->second << endl;
	}
}

int main()
{
	TestMap();
	system("pause");
}