#include <iostream>
using namespace std;

int main() {
	int k, tmp;

	int countOfOne = 0, countOfFive = 0, countOfTen = 0;

	cin >> k;

	for (int i = 0; i < k; ++i)
	{
		cin >> tmp;

		if (tmp == 1)
		{
			countOfOne++;
		} else if (tmp == 5)
		{
			countOfFive++;
		} else if (tmp == 10)
		{
			countOfTen++;
		}
	}

	cout << countOfOne << endl;

	cout << countOfFive << endl;

	cout << countOfTen << endl;

	return 0;

}