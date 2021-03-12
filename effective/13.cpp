#include<iostream>
using namespace std;

class A {
	public:
		A(){};
		void show() {
			int i=0;
			i+1;
		}
};

class B {
	public:
		B(){};
		void show();
};

void B::show(){
	int i=0;
	i+i;
}

void test01() {
	A a;
	for(long i=0; i!=10000000000; ++i)
		a.show();
}

void test02(){
	B b;
	for(long i=0; i!=10000000000; ++i)
		b.show();
}
int main (void){
	test01();
	
	return 0;
}
