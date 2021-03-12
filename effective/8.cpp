#include<iostream>
using namespace std;

class A{
	public:
		A(){
			cout<<"Constructors!"<<endl;
		}
};

void f(const A& a){
	cout<<"used!"<<endl;
}
 
int main(void){
	A a;
	f(a);
	return 0;
}
