#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void CountSort(int*a, int n)
{
	//�ȼ��������С����
	int min = a[0];
	int max = a[0];
	int i = 0;
	while (i < n)
	{
		if (min > a[i])
		{
			min = a[i];
		}
		if (max < a[i])
		{
			max = a[i];
		}
		i++;
	}
	//���ٿռ�

	int count = max - min + 1;
	int* cur = (int*)malloc(sizeof(int)*count);

	//�ǵ�Ҫ���¿��ٵ������ʼ��
	memset(cur, 0, sizeof(int)*count);

	//���������ı�

	for (int i = 0; i < n; i++)
	{
		cur[a[i] + min]++;
	}

	//��cur����ȡ�������ηŻ�a[]��

	int index = 0;
	for (i = 0; i < count; i++)//��ס�Ǵ�cur������ȡ������˷�ΧӦ����0~count
	{
		while (cur[i]-- != 0)
		{
			a[index++] = i + min; //����Ĳ���cur[i],����cur���±꣬���cur[i]������Ϊ0����������һ������
		}
	}

}

void _MergeSort(int*a, int begin, int end, int* cur)
{
	if (begin >= end )
	{
		return;
	}

	int mid = begin + ((end - begin) >> 1);

	_MergeSort(a, begin, mid-1, cur);
	_MergeSort(a, mid, end, cur);
	int begin1 = begin;
	int end1 = mid - 1;
	int begin2 = mid;
	int end2 = end;
	int index = begin;

	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			cur[index++] = a[begin1++];
		}
		else
			cur[index++] = a[begin2++];

	}
	while (begin1 <= end1)
	{
		cur[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		cur[index++] = a[begin2++];
	}
	//�鲢���
	index = begin;
	while (begin <= end)
		a[index++] = cur[begin++];


}

void MergeSort(int*a, int n)
{
	int* cur = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, cur);
	free(cur);
}

int main()
{
	int a[] = { 10,6,7,1,3,9,4,2};
	int n = sizeof(a) / sizeof(a[0]);
	int i = 0;
	MergeSort(a, n);
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}