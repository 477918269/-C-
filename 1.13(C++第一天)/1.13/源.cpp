#include<iostream>

//��ͨ�����ռ�

namespace N1//��N1Ϊ�����ռ�����
{
	int a = 10;
}

namespace N2//���Ƕ�׿ռ�
{
	int a = 1;
	int b = 2;
	namespace N3
	{
		int c = 3;
		int b = 4;
	}
}

using namespace N1;//2.ʹ��using namespace �����ռ��������룬 Ҫ��;

using N1::a;

using namespace std; //C++�ı�׼�ռ�

int main()
{
	//printf("%d", N1 :: a);//��һ�ַ��� �������ռ����Ƽ��������޶���::
	//printf("%d",a);
	//printf("%d", N2::N3::c);//����Ƕ�׿ռ��ʱ��Ҫ�ȵ��ñ�Ƕ�׿ռ������
	//C++�ı�׼���
	//1.ʹ��cout��cinʱ���������< iostream >ͷ�ļ��Լ�std��׼�����ռ䡣
	//2.ʹ��C++������������㣬�����������ݸ�ʽ���ƣ����磺����--%d���ַ�--%c

	int a;
	int b;
	int c;
	int d;
	//cin >> a;
	cin >> b >> c>>d;//�����ǰ��˳��
	//cout << a  << endl;
	cout << b << d << " "<< c << endl;//����bcd��˳��
	system("pause");
	return 0;
}

