void intercept()
{
	vector<int> missile = { 389, 207, 155, 300, 299, 170, 158, 65 };
	int len = missile.size();
	vector<int> note(len);
	for (int i = 0; i < len; i++)
		note[i] = 0;//note���ʼ��

	for (int i = len - 1; i >= 0; i--)//�����һ��������ʼ��ǰ����
	{
		int max = 0, flag = i;//max��ʾ����ѯ��¼��noteʱ����ǰ��ѯ�����������ص���������flag��ʾ��ǰ�鵽����������������±�
		cout << "i=" << i << endl;
		for (int j = i + 1; j < len; j++)
		{
			if (missile[i] > missile[j] && note[j] > max)//����ǰ�����߶ȴ���֮���j�������߶ȣ��ҵ�j������֮������������������Ŀǰ��֪�������ʱ�򣬸���flag��max��
			{
				flag = j;
				max = note[j];
			}
		}
		note[i] = note[flag] + 1;
		for (auto x : note)
			cout << x << " ";
		cout << endl;
	}

	return;
}
