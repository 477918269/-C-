#include<iostream>
using namespace std;
//
//class parent
//{
//	int i;
//protected:
//	int x;
//public:
//	parent(){ x = 0; i = 0; }
//	void change(){ x++; i++; }
//	void display();	
//
//};
//class son :public parent
//{
//public:
//	void modify();
//};
//void parent::display()
//{
//	cout << "x=" << x << endl;
//}
//void son::modify() { x++; }
//void Test4()
//{
//	son A;
//	parent B;
//	A.display();
//	A.change();
//	A.modify();
//	A.display();
//	B.change();
//	B.display();
//}
//#include<iostream>
//using namespace std;
//class B0//����BO����//5
//{
//public:
//	//�ⲿ�ӿ�
//	virtual void display()//���Ա����
//	{    cout<<"B0::display0"<<endl;}
//};
//class B1:public B0//��������
//{
//public:
//	void display() { cout<<"B1::display0"<<endl; }
//};
//class D1: public B1//��������
//{
//public:
//	void display(){ cout<<"D1::display0"<<endl; }
//};
//void fun(B0 ptr)//��ͨ����
//{
//	ptr.display();
//}
//void Test2()//������ 
//{    
//	B0 b0;//������������ָ��
//	B1 b1;//�������������
//	D1 d1;//�������������
//	fun(b0);//���û���B0������Ա
//	fun(b1);//����������B1������Ա
//	fun(d1);//����������D1������Ա
//}

//#include<iostream>
//using namespace std;
//
//class parent//7
//{
//public:
//	int i;
//	int x;
//public:
//	parent(){ x = 0; i = 0; }
//	void change(){ x++; i++; }
//	void display();
//};
//class son :public parent 
//{ 
//public:
//	void modify();
//};
//void parent::display()
//{
//	cout << "x=" << x << endl;
//}
//void son::modify() { x++; }
//void Test3()
//{
//	son A;
//	parent B;
//	A.display();
//	A.change();
//	A.modify(); 
//	A.display();
//	B.change();
//	B.display();
//	cout << A.x << endl;
//}

//#include <iostream>
//using namespace std;
//class cla//8
//{
//	static int n;
//public:
//	cla(){n++;}
//	~cla(){n--;}
//	static int get_n(){return n;}
//};
//int cla::n = 0;
//void Test4()
//{
//	cla *p = new cla;
//	delete p;
//	cout << "n=" << cla::get_n() << endl;
//}

//class A //8
//{ 
//public:
//	A() :m_iVal(0){ test(); }
//	virtual void func(){ cout << m_iVal << ' '; }
//	void test(){ func(); }
//public:
//	int m_iVal;
//};
//class B : public A
//{
//public:    
//	B(){ test(); }
//	virtual void func()
//	{
//		++m_iVal;      
//		cout << m_iVal << ' ';
//	}
//};
//void Test5() 
//{ 
//	A*p = new B;
//	p->test();
//}

//class MyClass//9
//{
//public:
//	MyClass(int i = 0){ cout << 1; }
//	MyClass(const MyClass&x){ cout << 2; }
//	MyClass& operator=(const MyClass&x){ cout << 3; return*this; }
//	~MyClass(){ cout << 4; }
//};
//void Test6()
//{
//	MyClass obj1(1), obj2(2), obj3(obj1);
//}


//class Test//9
//{
//public:
//	int a;
//	int b;
//	virtual void fun() {}
//	Test(int temp1 = 0, int temp2 = 0)
//	{ 
//		a = temp1;        
//		b = temp2;
//	}    
//	int getA(){ return a; }
//	int getB(){ return b; } 
//};
//�麯����ָ��ƫ������
//void Test7()
//{
//	Test obj(5, 10);
//	// Changing a and b
//	int* pInt = (int*)&obj;
//	*(pInt+0) = 100;
//	*(pInt+1) = 200;
//	cout << "a = " << obj.getA() << endl;
//	cout << "b = " << obj.getB() << endl;
//}


//struct A
//{
//	void foo(){ printf("foo"); }
//	virtual void bar(){ printf("bar"); }
//	A(){ bar(); } 
//}; 
//struct B :A
//{ 
//	void foo(){ printf("b_foo"); }
//	void bar(){ printf("b_bar"); }
//};
//
//void Test9()
//{
//	A *p = new B;
//	p->foo();
//	p->bar();
//}

//��ʼ��˳��
//class Printer
//{
//public:
//	Printer(std::string name) { cout << name; }
//};
//class Container{
//public:
//	Container() : b("b"), a("a") {}
//	Printer a;
//	Printer b;
//};
//void Test10()
//{
//	Container c;
//}

int main()
{
	Test10();
	system("pause");
	return 0;
}