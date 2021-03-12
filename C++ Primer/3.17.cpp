#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	vector<string>s;
	string str;
	while(cin>>str) {
		s.push_back(str);
	}

	for(auto &t:s) {
		for(auto &v:t) {
			v=toupper(v);
		}
	}
	for(auto &t:s) {
		cout<<t<<' ';
	}
	return 0;
}
