#include<iostream>
#include<vector>
using namespace std;

int main(void) {
	vector<int>s={1,6,25,7,26,87,57,46,24,31};
	for(auto &c:s) {
		c*=2;
	}
	for(auto c:s)
		cout<<c<<' ';

	return 0;
}
