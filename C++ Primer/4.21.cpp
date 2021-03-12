#include<iostream>
using namespace std;
#include<vector>

int main(void){
	vector<int>p;
	for(vector<int>::size_type i=0;i!=10;++i){
		p.push_back(i);
	}
	for(auto i=p.begin();i!=p.end();++i){
		(*i)%2==0? *i=*i : *i=*i*2;
	}

	for(auto c:p)
	cout<<c<<' ';
	return 0;
}
