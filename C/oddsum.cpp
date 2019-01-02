#include <iostream>
using namespace std;

int main(){
	int m, n;
	cin >> m;
	cin >> n;

	int sum = 0;

	for (int i = m; i <= n; i++) {
		if (i % 2 != 0)
		{
			sum += i;
		}
	}

	cout << sum << endl;

	return 0;
}