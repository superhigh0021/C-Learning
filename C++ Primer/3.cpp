#include<iostream>
#include<memory>
using namespace std;

int sb(int *i){
	return i;
}

int main(void){
	int i=6;
	int* j=&i;
	cout<<sb(&i)<<endl;
	
	return 0;
}
