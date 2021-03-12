#include<iostream>
#include<vector>
#include<functional>
#include<numeric>
#include<algorithm>
using namespace std;

template<class T>
void print(T i){
	cout<<i<<' ';
}

int main(void) {
	vector<int>v= {0,10,29,27,65,287,61,86};
	stable_sort(v.begin(),v.end());
	for(auto i:v){
		cout<<i<<' ';
	}
	cout<<endl;
	for_each(v.begin(),v.end(),print<int>);
	return 0;
}
