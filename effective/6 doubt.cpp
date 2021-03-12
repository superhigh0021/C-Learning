#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>
using namespace std;

class Widget {
	public:
		int x;
		int y;
		Widget(int x,int y) {
			this->x=x;
			this->y=y;
		}
//		void test(Widget* w) {
//			if(w->x<6&&w->y<6) {
//				cout<<"Yes!";
//			} else {
//				cout<<"No!";
//			}
//		}
};

void test(Widget& w) {
	if(w.x<6&&w.y<6) {
		cout<<"Yes!";
	} else {
		cout<<"No!";
	}
}


int main(void) {
	vector<Widget*>w;
	for(int i=5; i!=8; ++i) {
		w.push_back(new Widget(i,i));
	}
	for_each(w.begin(),w.end(),mem_fun(&Widget::test));

	return 0;
}
