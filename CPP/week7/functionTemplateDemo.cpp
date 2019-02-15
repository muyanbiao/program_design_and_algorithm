#include <iostream>
using namespace std;

template <class T>
void Swap(T &x, T &y) {
	T tmp = x;
	x = y;
	y = tmp;
}

int main() {
	int n = 1, m = 2;
	cout << "Before swap: n = " << n << ", m = " << m << endl;
	Swap(n, m);		// 编译器自动生成 void Swap(int &, int &)函数
	cout << "After swap: n = " << n << ", m = " << m << endl;

	double f = 1.2, g = 2.3;
	cout << "Before swap: f = " << f << ", g = " << g << endl;
	Swap(f, g);		// 编译器自动生成 void Swap(float &, float &)函数
	cout << "After swap: n = " << f << ", m = " << g << endl;
	
	return 0;
}