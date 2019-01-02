#include <iostream>
using namespace std;

int main() {
	// 输入的过程中，先判断奇偶，在判断大小

	int tmpIn;
	int maxOdd = 0;
	int minEven = 100;

	for (int i = 0; i < 6; ++i)
	{
		cin >> tmpIn;
		if (tmpIn % 2 == 0)
		{
			if (tmpIn < minEven) {
				minEven = tmpIn;
			}
		} else {
			if (tmpIn > maxOdd)
			{
				maxOdd = tmpIn;
			}
		}
	}

	cout << abs(maxOdd - minEven) << endl;

	return 0;
}

