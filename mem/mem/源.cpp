#include<iostream>
#include<stdio.h>
#include<string.h>

//һ��汾,�����dest��src��ǿ��ת�����ˣ�char*�����ͣ�����copyһ����һ�����ֽ���ɵ���?��������������汾�����Թٿ�����
//void* my_memcpy(void* dest, const void* src, size_t count)
//{
//	assert((NULL != dest) && (NULL != source));
//	char* tmp = (char*)dest;
//	const char* cur = (char*)src;
//
//	while (count--)
//		*tmp++ = *cur++;
//
//	return dest;
//}

//���հ汾���������ڴ��ص�������¡�
//void* my_memcpy(void* dest, const void* src, size_t count)
//{
//	//assert((NULL != dest) && (NULL != source));
//
//	int num = count / sizeof(dest);//��dest���Ϳ���
//	int slice = num % sizeof(dest);//ʣ���ֽڿ���
//
//	unsigned long * s = (unsigned long*)src;
//	unsigned long * d = (unsigned long*)dest;
//
//	while (num--)
//		*d++ = *s++;
//
//	while (slice--)
//		*((char*)d++) = *((char*)s++);
//
//	return dest;
//
//}
//���հ汾�������ڴ��ص�����

void* my_memcpy(void* dst, const void* src, size_t count)
{
	void* ret = dst;
	//dst <= src��ʾ�����dst��src��ǰ�棬��ǰ�����Ʋ��Ḳ��src�л�û�и��Ƶ�����

	if (dst <= src || (char*)dst >= ((char*)src + count))
	{
		//��ǰ�����ƣ��򲻻���ָ���src��û�и��Ƶ�����
		while (count--)
		{
			*(char*)dst = *(char*)src; //char����ָ�룬��ʾһ���ֽ�һ���ֽڵĸ���
			dst = (char*)dst + 1; //�ƶ�һ���ֽ�
			src = (char*)src + 1;
		}
	}
	else
	{
		//�Ӻ���ǰ���ƣ��򲻻���ָ���src��û�и��Ƶ�����
		dst = (char*)dst + count - 1;//�ƶ���ĩβ
		src = (char*)src + count - 1;
		while (count--)
		{
			*(char*)dst = *(char*)src;
			dst = (char*)dst - 1; //�ƶ�һ���ֽ�
			src = (char*)src - 1;
		}
	}
	//����dst��ͷָ�룬��������ֵ������
	//�磺ptstr = memmove(ptstr,src,count); cout << memmove(ptstr,src,count);
	return ret;
}

int main()
{
	char s[] = "abcdefghijk";
	my_memcpy(s, s + 4, 4);
	printf("%s", s);
	system("pause");
	return 0;
}