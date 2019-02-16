#include <iostream>
using namespace std;

int main() {
	double f;
	int n;
	freopen("t.txt", "r", stdin);		// cin被改为从t.txt中读取数据
	cin >> f >> n;
	cout << "f = " << f << ", n = " << n << endl;
	return 0;
}