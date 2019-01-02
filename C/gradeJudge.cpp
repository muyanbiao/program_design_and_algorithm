#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	if (n < 60)
	{
		cout << 7 << endl;
	} else if (n < 70) {
		cout << 6 << endl;
	} else if (n < 80) {
		cout << 5 << endl;
	} else if (n < 85) {
		cout << 4 << endl;
	} else if (n < 90) {
		cout << 3 << endl;
	} else if (n < 95) {
		cout << 2 << endl;
	} else if (n <= 100) {
		cout << 1 << endl;
	}

	return 0;
}

// 编程题＃2：成绩判断
// 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

// 注意： 总时间限制: 1000ms 内存限制: 6000kB

// 描述
// 输入一个0--100的分数，判断分数代表什么等级。

// 95<=分数<=100, 输出1

// 90<=分数<95,输出2

// 85<=分数<90,输出3

// 80<=分数<85,输出4

// 70<=分数<80,输出5

// 60<=分数<70输出6

// 分数 < 60;输出7.

// 输入
// n

// 输出
// m

// 样例输入

// 87

// 样例输出

// 3