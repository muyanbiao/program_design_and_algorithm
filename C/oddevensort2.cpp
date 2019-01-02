#import <iostream>
using namespace std;

int main() {
	// 输入10个数
	// 对这10个数进行冒泡排序
	// 冒泡排序的规则，不再只是比较大小，还要依据是否奇偶数来决定是否交换顺序
	// 左边是偶数，右边是奇数，交换顺序
	// 同是奇数，同是偶数，这时才比较大小

	int a[10];
	for (int i = 0; i < 10; ++i)
	{
		cin >> a[i];
	}

	for (int i = 0; i < 10-1; ++i)
	{
		for (int j = 1; j < 10 - i; ++j)
		{
			bool leftIsEven = a[j-1] % 2 == 0;
			bool rightIsEven = a[j] % 2 == 0;
			if ((leftIsEven && !rightIsEven) || (leftIsEven == rightIsEven && a[j-1] > a[j]))
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