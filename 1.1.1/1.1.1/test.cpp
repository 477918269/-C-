#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
//���쳲�������
//int FB(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return FB(n - 1) + FB(n - 2);
//}
//
//int main()
//{
//	int num = 0;
//	int poi = 0;
//	printf("��������Ҫ�Ĳ��ҵĵ�Nλ쳲�������>:");
//	scanf("%d", &num);
//	poi = FB(num);
//	printf("%d", poi);
//
//	system("pause");
//	return 0;
//}

//�����ŵ������
//void move()
//{
//	printf("form %d to %d ")
//}
//
//int Honio(int n)
//{
//	if (n = 1)
//	{
//		move()
//	}
//	else
//
//}
//
//int main()
//{
//	int n = 0;
//	
//	printf("��������Ҫ���˵�ľ��");
//	scanf("%d", &n);
//
//	char 
//	system("pause");
//
//	return 0;
//}

//������̨������
//��һ�ʣ�һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������
//��쳲���������һ������n>3ʱ�õݹ顣
//���ǣ�������ǳ�����Ҫ��ѭ������ݹ顣
//���£�
//int FB(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = a+b;
//	int i = 0;
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		for (i = 3; i < n; i++)
//		{
//			b = a;
//			a = c;
//			c = a + b;
//		}
//		return c;
//	}
//	
//}
//
//int main()
//{
//	int num = 0;
//	int poi = 0;
//	printf("������N��̨��>:");
//	scanf("%d", &num);
//	poi = FB(num);
//	printf("%d", poi);
//
//	system("pause");
//	return 0;
//}

//�ڶ��ʣ�һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
//		  �����������һ��n����̨���ܹ��ж�����������
//˼·��n=1 , f(n)ֻ��һ����һ��̨�ף�1�ַ�����
//		n=2 , f(n)��һ����һ��̨�ף�1�֣���һ��������̨�ף�1��
//		n=3 , f(n)��һ����һ��̨�ף�f(3-1)�֣���һ��������̨�ף�f(3-2)�֣���һ��������̨��, 1��
//		f(n) = f(n-1)+f(n-2)+...+1
//		f(n-1) = f(n-2) +f(n-3)+...+1
//		f(n) - f(n - 1) = f(n - 1);
int FB(int n)
{
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else
		return 2 * FB(n - 1);
}
int main()
{
		int num = 0;
		int poi = 0;
		printf("����������Ҫ��̨��>:");
		scanf("%d", &num);
		poi = FB(num);
		printf("%d", poi);
	
		system("pause");
		return 0;
	return 0;
}
