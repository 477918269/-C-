#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
	vector<int> table = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };//������⣬�����±��1��ʼ��0��λ C++11�±�׼vector��ʼ����ʽ
	int n;
	cin >> n;//�����������
	vector<int> r(n + 1, 0);//������⣬�����±��1��ʼ����ʼ��11λ����
	for (int i = 1; i <= n; i++)
	{
		int max = -1;
		for (int j = 1; j <= i; j++)
		{
			if (max < table[j] + r[i - j])
				max = table[j] + r[i - j];
		}
		r[i] = max;
	}
	for (auto x : r)
		cout << x << " ";
	cout << endl;
	return 0;
}