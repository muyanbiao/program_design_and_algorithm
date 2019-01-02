#include <iostream>
using namespace std;

void baseConversion(long long number) {
	if (number / 2 == 0)
	{
		cout << number;
	} else {
		baseConversion(number/2);
		cout << number % 2;
	}
}

int main() {
	// 使用递归的方法解决问题
	// 假设有一个递归函数，可以求解某个数的
	long long number;

	while (cin >> number) {
		baseConversion(number);
		cout << endl;
	}

	return 0;
}

// 3249:进制转换
// 总时间限制:
//     1000ms
// 内存限制:
//     65536kB

// 描述
//     将一个长度最多为30位数字的十进制非负整数转换为二进制数输出。
// 输入
//     多组数据，每行为一个长度不超过30位的十进制非负整数。
//     （注意是10进制数字的个数可能有30个，而非30bits的整数）
// 输出
//     每行输出对应的二进制数。
// 样例输入

//     0
//     1
//     3
//     8

// 样例输出

//     0
//     1
//     11	
//     1000

