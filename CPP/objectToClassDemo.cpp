#include <iostream>
using namespace std;

class CRectangle
{
public:
	int w, h;
	void init(int w_, int h_) {
		w = w_;
		h = h_;
	}

	int Area() {
		return w * h;
	}

	int Perimeter() {
		return 2 * (w + h);
	}
};

int main() {
	int w, h;
	CRectangle r; // r是一个对象
	cin >> w >> h;
	r.init(w, h);
	cout << r.Area() << endl << r.Perimeter;
	return 0;
}

//从客观事物抽象出类的例子