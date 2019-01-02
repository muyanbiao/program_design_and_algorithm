#include <iostream>
using namespace std;

int main() {
	int max = 0;

	for (max = 1; max < 5; ++max)
	{
		bool A = max == 2;
		bool B = max == 4;
		bool C = max != 3;
		bool D = max != 4;

		if (A + B + C + D == 1)
		{
			cout << max << endl;
			break;
		}
	}

	if (max == 2)
	{
		cout << "A" << endl;
	} else if (max == 4) {
		cout << "B" << endl;
	} else if (max != 3) {
		cout << "C" << endl;
	} else {
		cout << "D" << endl;
	}

	return 0;
}