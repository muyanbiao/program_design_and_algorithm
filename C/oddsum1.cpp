#include <iostream>
using namespace std;

int main(){
	// a = 1 3 5 7 9 ... 2n-1
	// n = (a+1)/2
	// b = 2 4 6 8 10 ... 2n
	// n = b / 2
	// Sa = n2

	int m, n;
	cin >> m >> n;

	int indexOfm = 0, indexOfn = 0;

	int sumOfm = 0, sumOfn = 0;

	int valueBetweenMAndN = 0;

	if (m % 2 == 0)
	{
		indexOfm = m / 2;
	} else {
		indexOfm = (m + 1) / 2;
	}

	sumOfm = indexOfm * indexOfm;

	if (n % 2 == 0) {
		indexOfn = n / 2;
	} else {
		indexOfn = (n + 1) / 2;
	}

	sumOfn = indexOfn * indexOfn;

	valueBetweenMAndN = sumOfn - sumOfm;

	if (m % 2 != 0)
	{
		valueBetweenMAndN += m;
	}

	if (m == n)
	{
		valueBetweenMAndN = 0;
	}

	cout << valueBetweenMAndN << endl;

	return 0;
}