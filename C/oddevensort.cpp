#import <iostream>
using namespace std;
int main(){
	int arr[10];
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 1; j < 10-i; j++) {
			if (arr[j - 1] > arr[j]) {
				int tmp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = tmp;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		if (arr[i] % 2 != 0)
			cout << arr[i] << " ";
	}

	for (int i = 0; i < 10; i++) {
		if (arr[i] % 2 == 0)
			cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}
