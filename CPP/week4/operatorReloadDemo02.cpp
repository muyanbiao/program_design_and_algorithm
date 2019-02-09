#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(double r = 0.0, double m = 0.0):real(r), imaginary(m) { } // Constructor
	Complex operator+(const Complex &); // addition
	Complex operator-(const Complex &); // subtraction

	void printComplex(char nameOfComplex);

private:
	double real;	// real part
	double imaginary; // imaginary part
	
};

// Overloaded addition operator
Complex Complex::operator+(const Complex &operand2) {
	return Complex(real + operand2.real, imaginary + operand2.imaginary);
}

// Overloaded subtraction operator
Complex Complex::operator-(const Complex &operand2) {
	return Complex(real - operand2.real, imaginary - operand2.imaginary);
}

void Complex::printComplex(char nameOfComplex) {
	cout << nameOfComplex << ".real = " << real << ", " << nameOfComplex << ".imaginary = " << imaginary << endl;
}

int main() {
	Complex x, y(4.3, 8.2), z(3.3, 1.1);

	y.printComplex('y');
	z.printComplex('z');

	x = y + z;
	cout << "x = y + z" << endl;
	x.printComplex('x');

	x = y - z;
	cout << "x = y - z" << endl;
	x.printComplex('x');
	return 0;
}