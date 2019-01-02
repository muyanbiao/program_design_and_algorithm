#import <iostream>
using namespace std;
int main(){
	int count;
	cin >> count;
	
	int arr[count];
	
	for (int i = 0; i < count; i++) {
		cin >> arr[i]; 
	}

	for (int j = 0; j < count - 1; j++) {
		for (int k = 1; k < count - j; k++) {
			if (arr[k-1] > arr[k]) {
				int tmp = arr[k-1];
				arr[k-1] = arr[k];
				arr[k] = tmp;
			}
		}
	}
	
	for (int i = 0; i < count; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}
