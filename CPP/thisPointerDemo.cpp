#include <iostream>
using namespace std;

class A {
	int i;
public:
	void Hello() { cout << "hello" << endl; }
};

int main() {
	A *p = NULL;
	p->Hello();
	return 0;
}


// this指针