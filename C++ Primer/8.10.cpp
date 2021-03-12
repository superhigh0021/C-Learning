#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

int main(void){
	string s,line,word;
	cin>>s;
	ifstream in(s);
	while(getline(in,line)){
		for(istringstream is(line);is>>word;)
		cout<<word<<' ';
	}
	return 0;
}
