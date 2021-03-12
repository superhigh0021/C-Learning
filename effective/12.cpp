#include<iostream>
using namespace std;

class Base{
	public:
		virtual void show(){
			cout<<"Base!"<<endl;
		}
};

class Derived:public Base{
	public:
		virtual void show(){
			Base::show();
		}
};

int main(void){
	Derived d;
	d.show();
	
	return 0;
}
