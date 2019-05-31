#include <stdio.h>
#include <string.h>

/*
c[i][j]�洢�����ִ�1��iλ�ã��ִ�2��jλ��ʱ���������е���󳤶�

if str1[i] == str2[j]    c[i][j] = c[i-1][j-1]+1;
if str1[i] != str2[j]    c[i][j] = max{c[i-1][j],c[i][j-1]}
*/
int lcs(char *str1, char *str2, int len1, int len2, int c[100][100])
{
	if (str1 == NULL || str2 == NULL)
	{
		return -1;//�����ַ�������
	}
	//��ʼ����¼dp�Ķ�ά����
	for (int i = 0; i <= len1; i++)
	{
		for (int j = 0; j <= len2; j++)
		{
			c[i][j] = 0;
		}
	}
	//dp����
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else {
				c[i][j] = c[i - 1][j]>c[i][j - 1] ? c[i - 1][j] : c[i][j - 1];
			}
		}
	}
	//��ӡ��dp����洢������
	for (int i = 0; i <= len1; i++)
	{
		for (int j = 0; j <= len2; j++)
		{
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}

	//��ӡ������������
	char str[100] = { 0 };
	int index = c[len1][len2] - 1;
	for (int i = len1, j = len2; i>0 && j>0;)
	{
		if (str1[i - 1] == str2[j - 1])
		{
			str[index--] = str1[i - 1];
			i--;
			j--;
		}
		else
		{
			if (c[i][j - 1]>c[i - 1][j])
			{
				j--;
			}
			else
			{
				i--;
			}
		}
	}
	printf("����������Ϊ��%s\n", str);
	return c[len1][len2];
}


int main(int argc, char **argv)
{
	char str1[] = { "ABCBDAB" };
	char str2[] = { "BDCABA" };
	int c[100][100];
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int num = lcs(str1, str2, len1, len2, c);
	printf("���������еĳ��ȣ�%d\n", num);
	return 0;
}