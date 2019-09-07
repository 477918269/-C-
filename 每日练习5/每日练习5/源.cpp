//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	
//	vector<int> v(5, 0);
//	return 0;
//}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//	int T, m, k;
//	cin >> T;
//	while (T--)
//	{
//		cin >> m >> k;
//		int num = m * 2;
//		vector<int> v(num, 0);
//
//		for (int i = 0; i < num; i++)
//		{
//			cin >> v[i];
//		}
//		vector<int> v1(num, 0);
//		while (k--)
//		{
//			int z = num;
//			int y = m;
//			int j = 0;
//			while (--y >= 0)
//			{
//				v1[j++] = v[--z];
//				v1[j++] = v[y];
//			}
//			reverse(v1.begin(), v1.end());
//			v = v1;
//		}
//
//		for (int i = 0; i < v1.size(); i++)
//		{
//			cout << v1[i] << " ";
//		}
//	}
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	int T, n, k;
//	cin >> T;
//	while (T--)
//	{
//		cin >> n >> k;
//		int num = 2 * n;
//		vector<int> table(num);
//		for (int i = 0; i < num; ++i)
//			cin >> table[i];
//		//ϴk����
//		while (k--)
//		{
//			vector<int> n1(table.begin(), table.end());
//			for (int i = 0; i < n; ++i)
//			{
//				//�����ǰ��С�ڵ���n���������֣��������´γ��ֵ�λ���� 2*��ǰλ��
//				//��֮��Ӧ�ĵ�ǰλ�� + n���������֣�����,�����´γ��ֵ�λ���� 2*��ǰλ�� + 1
//				table[2 * i] = n1[i];
//				table[2 * i + 1] = n1[i + n];
//			}
//
//		}
//		for (int i = 0; i < num - 1; ++i)
//			cout << table[i] << " ";
//		cout << table[num - 1] << endl;
//	}
//		return 0;
//}

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		//����̵��ַ�����Ϊs1
		if (str1.size() > str2.size())
			swap(str1, str2);
		int len1 = str1.size(), len2 = str2.size();
		int i, j, start = 0, max = 0;
		vector<vector<int>> MCS(len1 + 1, vector<int>(len2 + 1, 0));
		for (i = 1; i <= len1; i++)
		for (j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				MCS[i][j] = MCS[i - 1][j - 1] + 1;
			//����и����Ĺ����Ӵ������³���
			if (MCS[i][j] > max)
			{
				max = MCS[i][j];
				//��i��β����󳤶�Ϊmax, ���Ӵ�����ʼλ��Ϊi - max
				start = i - max;
			}
		}
		cout << str1.substr(start, max) << endl;
	}
	return 0;
}