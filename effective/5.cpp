#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

bool compare(int i){
	return i==99;
}

int main(void){
	vector<int>v;
	v.reserve(10);
	for(int i=1;i!=11;++i){
		v.push_back(i);
	}
	cout<<v.size()<<endl;
	v[3]=v[5]=v[9]=99;
	v.erase(remove_if(v.begin(),v.end(),compare),v.end());
	cout<<v.size()<<endl;
	
	return 0;
} 
