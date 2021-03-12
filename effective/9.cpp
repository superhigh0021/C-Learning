#include<iostream>
using namespace std;

class Rational {
		friend const Rational operator*(Rational& lhs,Rational& rhs);
		friend void print(Rational& r);
	public:
		Rational(int numerator=0,int denominator=1):Numerator(numerator),Denominator(denominator) {};
	private:
		int Numerator;
		int Denominator;
};

const Rational operator*(Rational& lhs,Rational& rhs) {
	return Rational(lhs.Numerator*rhs.Numerator,lhs.Denominator*rhs.Denominator);
}

void print(Rational& r) {
	cout<<r.Numerator<<' '<<r.Denominator<<endl;
}

int main(void) {
	Rational r(1,4);
	Rational s(static_cast<Rational>(2));
	Rational result;
	result=r*s;
	print(result);

	return 0;
}
