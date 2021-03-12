#include<iostream>
#include<vector>
#include<algorithm>

class WidgetImpl{
	public:
		
	private:
		int a,b,c;
		std::vector<double>v;
}; 

class Widget{
	public:
		Widget(int x){X=x;};
		Widget(const Widget& rhs);
		Widget& operator=(const Widget& rhs){
			*pImpl=*(rhs.pImpl);
		}
		void swap(Widget& other){
			using std::swap;
			swap(pImpl,other.pImpl);
		}
	private:
		WidgetImpl* pImpl;
		int X;
};

namespace std{
	template<>
	void swap<Widget>(Widget& a,Widget& b){
		a.swap(b);
	}
}

int main(void){
	Widget w(1);
	Widget s(2);
	using std::swap;
	swap(w,s);
	
	return 0;
}
