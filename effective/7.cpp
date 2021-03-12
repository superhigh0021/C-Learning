#include<iostream>
using namespace std;

class A {
	public:
		A() {
			show();
		}
		virtual void show() {
			cout<<"base class constructor!"<<endl;
		}
		virtual ~A(){
			cout<<"base class destructor!"<<endl;
		}
};

class B:public A {
	public:
		B() {
			show();
		}
		void show() {
			cout<<"derived class constructor!"<<endl;
		}
};

int main(void) {
	A a;
	B b;

	return 0;
}
