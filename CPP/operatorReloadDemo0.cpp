#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(double r = 0.0, double i = 0.0) {
		real = r;
		imaginary = i;
	}
	double real;		//real part
	double imaginary;	// imaginary
	
};

Complex operator+(const Complex &a, const Complex &b)
{
	return Complex(a.real+b.real, a.imaginary+b.imaginary);
} //“类名（参数表）”就代表一个对象

int main() {
	Complex a(1,2), b(2,3), c;
	c = a + b;
	cout << "c.real = " << c.real << ", c.imaginary = " << c.imaginary << endl;
	return 0;
}