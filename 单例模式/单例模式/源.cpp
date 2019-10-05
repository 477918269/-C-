
#include <iostream>
using namespace std;

class Singleton{
public:
	static Singleton* getInstance();

private:
	Singleton();
	//�Ѹ��ƹ��캯����=������Ҳ��Ϊ˽��,��ֹ������
	Singleton(const Singleton&);
	Singleton& operator=(const Singleton&);

	static Singleton* instance;
};

Singleton::Singleton(){

}


Singleton::Singleton(const Singleton&){

}


Singleton& Singleton::operator=(const Singleton&){
	return *this;
}


//�ڴ˴���ʼ��
Singleton* Singleton::instance = new Singleton();
Singleton* Singleton::getInstance(){
	return instance;
}

int main(){
	Singleton* singleton1 = Singleton::getInstance();
	Singleton* singleton2 = Singleton::getInstance();

	if (singleton1 == singleton2)
		fprintf(stderr, "singleton1 = singleton2\n");

	return 0;
}
