
// 奇偶排序
#import <iostream>
using namespace std;
int main() {
	// 输入10个数
	int a[10];
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}
	// 先把全部奇数放到左边，偶数全部放到右边
	int l = 0, r = 9;
	while (l <= r) {
		bool leftIsOdd = a[l] % 2 == 1;
		bool rightIsEven = a[r] % 2 == 0;
		if (leftIsOdd)
		{
			l++;
		} else if (rightIsEven)
		{
			r--;
		} else if (!leftIsOdd && !rightIsEven)
		{
			int tmp = a[l];
			a[l] = a[r];
			a[r] = tmp;
		}
	}

	int start = 0, end = l;
	// 分别对技术和偶数进行冒号排序
	for (int i = 0; i < end-1; i++) {
		for (int j = 1; j < start + end - i; j++) {
			if (a[j-1] > a[j])
			{
				int tmp = a[j-1];
				a[j-1] = a[j];
				a[j] = tmp;
			}
		}
	}

	start = l, end = 10;
	for (int i = l; i < end - 1; i++) {
		for (int j = start + 1; j < start + end - i; j++) {
			if (a[j-1] > a[j])
			{
				int tmp = a[j-1];
				a[j-1] = a[j];
				a[j] = tmp;
			}
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		cout << a[i] << " ";
	}

	cout << endl;

	return 0;
}