define  _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int inverse(char *str1)
{
	int length = 0;
	char *p1 = NULL;
	char *p2 = NULL;
	if (str1 == NULL)
	{
		return -1;
	}
	length = strlen(str1);
	p1 = str1;                 //ָ��ָ���ַ����Ŀ�ͷ;
	p2 = str1 + (length - 1);  //ָ��ָ���ַ��������һ��;
	while (p1 < p2)
	{
		char c = *p1;
		*p1 = *p2;
		*p2 = c;
		++p1;
		--p2;
	}
	return 0;
}
int  main(void)
{
	char buf[] = "abcdefg";   //buf[] ������ջ�϶�ȫ�������ַ���������
	inverse(buf);
	printf("buf:%s\n", buf);
	system("pause");
	return 0;
}
