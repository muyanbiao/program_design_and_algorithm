#include <iostream>
using namespace std;

int main() {

	// 读入数据
	// if 逐个判断
	int a, b, c;
	char tmpChar;

	cin >> a >> tmpChar >> b >> tmpChar >> c;

	// cout << "a = " << a << "b = " << b << "c = " << c << endl;

	char operatorToFind = '0';
	if (a + b == c)
	{
		operatorToFind = '+';
	} else if (a - b == c) {
		operatorToFind = '-';
	} else if (a * b == c) {
		operatorToFind = '*';
	} else if (b != 0 && a / b == c) {
		operatorToFind = '/';
	} else if (a % b == c) {
		operatorToFind = '%';
	}

	if (operatorToFind == '0')
	{
		cout << "error" << endl;
	} else {
		cout << operatorToFind << endl;
	}

	return 0;
}

// 编程题＃3：运算符判定
// 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 两个整数 a 和 b 运算后得到结果 c。表示为：a ? b = c，其中，？可能是加法 +，减法 -，乘法 *，整除 / 或 取余 %。请根据输入的 a,b,c 的值，确定运算符。如果某种运算成立，则输出相应的运算符，如果任何运算都不成立，则输出 error.

// 例如：

// 输入：

// 3,4,5

// 输出：

// error

// 若输入：

// 3,4,3

// 则输出：

// %

// 输入
// a b和 c 的值在意行内输入，以逗号间隔

// 输出
// 五个运算符之一或 error

// 样例输入

// 6,7,13

// 样例输出
// +