
#include"game.h"

//ð������
void BullSort(int* a, int n)
{
	int i = n - 1;
	while (i >= 0)
	{
		int cur = 0;
		
		while (cur < i)
		{
			if (a[cur] > a[cur + 1])//ѡ����С����������������һλ
			{
				int tmp = a[cur];
				a[cur] = a[cur + 1];
				a[cur + 1] = tmp;
			}
			cur++;//����һλ�ƶ�
		}
		i--;//�����һ����С����Ų��ѭ����
	}
}

//��������



int Realkey(int* a, int begin, int end)//����ȡ��
{
	int mid = begin + ((end - begin) >> 1);
	if (a[mid] > a[begin])
	{
		if (a[begin] > a[end])
			return begin;
		if (a[end] > a[mid])
			return mid;
	}
	if (a[mid] > a[end])
	{
		if (a[end] > a[begin])
			return end;
		if (a[begin] > a[mid])
			return mid;
	}
	return begin;
}

int QuickBuilt1(int*a, int begin, int end)//��򵥵Ŀ�������
{
	int key = Realkey(a,begin,end);
	int tme = a[begin];
	a[begin] = a[key];
	a[key] = tme;
	while (begin < end)
	{
		while (begin < end && a[end] > a[key])
		{
			end--;
		}

		while (begin < end && a[begin] <= a[key])
		{
			begin++;
		}

		int tmp = a[begin];
		a[begin] = a[end];
		a[end] = tmp;
	}
	int tmp = a[key];
	a[key] = a[end];
	a[end] = tmp;
	return begin;
}

int QuickBuilt2(int*a, int begin, int end)//�ڶ�����
{
	int key = Realkey(a, begin, end);
	int newkey = a[key];
	int tme = a[begin];
	a[begin] = a[key]; 
	a[key] = tme;
	
	while (begin < end)
	{
		while (begin < end && a[end] > newkey)
		{
			end--;
		}
		a[begin] = a[end];
		while (begin < end && a[begin] <= newkey)
		{
			begin++;
		}
		a[end] = a[begin];
	}
	a[begin] = newkey;
	return begin;
}

int QuickBuilt3(int*a, int begin, int end)//����ָ������
{
	int key = begin;
	int cur = begin + 1;
	int prev = begin;
	return 0;
}
	


void QuickSort1(int*a, int begin, int end)
{
	if (begin >= end)
		return;
	int div = QuickBuilt1(a, begin, end);
	QuickSort1(a, begin, div-1);
	QuickSort1(a, div + 1, end);
}

void QuickSort2(int*a, int begin, int end)//�ǵݹ�д��
{
	Stack ps;
	StackInit(&ps);
	StackPush(&ps, begin);
	StackPush(&ps, end);
	while (StackEmpty(&ps) != 0)
	{
		int right = StackTop(&ps);
		StackPop(&ps);	
		int left =StackTop(&ps);
		StackPop(&ps);

		int div = QuickBuilt1(a, left, right);

		if (div - 1 > left)
		{
			StackPush(&ps, left);
			StackPush(&ps, div-1);
			

		}

		if (div + 1 < right)
		{
			StackPush(&ps, div + 1);
			StackPush(&ps, right);
			

		}

	}

}


int main()
{
	int a[] = { 6, 1, 2, 7, 9, 3, 4, 5, 10, 8 };
	int n = sizeof(a) / sizeof(a[0]);
	//BullSort(a, n);
	int begin = 0;
	int end = n - 1;
	QuickSort2(a, begin, end);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}
