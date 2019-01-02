#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double notation() {

	// char tmpChar;
	char str[10];
	// int charCnt = 0;
	// while (true) {
	// 	tmpChar = getchar();

	// 	if (tmpChar == ' ' || tmpChar == '\0' || tmpChar == '\n')
	// 	{
	// 		str[charCnt] = '\0';
	// 		break;
	// 	}

	// 	str[charCnt++] = tmpChar;
	// }

	// cout << str << endl;

	cin >> str; // cin可以直接读入字符数组，并且遇到空格就结束

	switch(str[0]) {
		case '+':
			return notation() + notation();
		case '-':
			return notation() - notation();
		case '*':
			return notation() * notation();
		case '/':
			return notation() / notation();
		default:
			return atof(str);
	}
}

int main() {
	// 先解决数据输入问题
	// char inputLine[100];
	// cin.getline(inputLine, 100);

	cout << fixed << setprecision(6) << notation() << endl;;

	return 0;
}

// 2694:逆波兰表达式
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 逆波兰表达式是一种把运算符前置的算术表达式，例如普通的表达式2 + 3的逆波兰表示法为+ 2 3。逆波兰表达式的优点是运算符之间不必有优先级关系，也不必用括号改变运算次序，例如(2 + 3) * 4的逆波兰表示法为* + 2 3 4。本题求解逆波兰表达式的值，其中运算符包括+ - * /四个。
// 输入
// 输入为一行，其中运算符和运算数之间都用空格分隔，运算数是浮点数。
// 输出
// 输出为一行，表达式的值。
// 可直接用printf("%f\n", v)输出表达式的值v。
// 样例输入
// * + 11.0 12.0 + 24.0 35.0
// 样例输出
// 1357.000000
// 提示
// 可使用atof(str)把字符串转换为一个double类型的浮点数。atof定义在math.h中。
// 此题可使用函数递归调用的方法求解。
// 来源
// 计算概论05
