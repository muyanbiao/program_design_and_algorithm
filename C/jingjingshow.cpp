#include <iostream>
using namespace std;
int main() {
	int weekday;
	cin >> weekday;
	
	if (weekday >= 1 && weekday <= 7)
	{
		if (weekday == 1 || weekday == 3 || weekday == 5)
		{
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	} else {
		cout << "NO" << endl;
	}

	return 0;
}