#include <iostream>

using namespace std;

int main() {
	// 从100、50、20、10、5、1一次求得需要的张数，每求得一个，就减掉对应的数值，继续求下一个
	int cntOf100 = 0, cntOf50 = 0, cntOf20 = 0, cntOf10 = 0, cntOf5 = 0, cntOf1 = 0;

	int num, leftNum;
	cin >> num;

	leftNum = num;

	cntOf100 = leftNum / 100;
	leftNum -= cntOf100 * 100;

	cntOf50 = leftNum / 50;
	leftNum -= cntOf50 * 50;

	cntOf20 = leftNum / 20;
	leftNum -= cntOf20 * 20;

	cntOf10 = leftNum / 10;
	leftNum -= cntOf10 * 10;

	cntOf5 = leftNum / 5;
	leftNum -= cntOf5 * 5;

	cntOf1 = leftNum;

	cout << cntOf100 << endl 
	<< cntOf50 << endl
	<< cntOf20 << endl
	<< cntOf10 << endl
	<< cntOf5 << endl
	<< cntOf1 << endl;

	return 0;
}

// 编程题＃4：人民币支付
// 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 从键盘输入一指定金额（以元为单位，如345），然后输出支付该金额的各种面额的人民币数量，显示100元，50元，20元，10元，5元，1元各多少张，要求尽量使用大面额的钞票。

// 输入
// 一个小于1000的正整数。

// 输出
// 输出分行，每行显示一个整数，从上到下分别表示100元，50元，20元，10元，5元，1元人民币的张数

// 样例输入

// 735

// 样例输出

// 7
// 0
// 1
// 1
// 1
// 0