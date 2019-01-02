#include <iostream>
using namespace std;

int main() {
	// 
	int number;
	while(cin >> number) {
		bool three_divide = number % 3 == 0;
		bool five_divide = number % 5 == 0;
		bool seven_divide = number % 7 == 0;

		if (three_divide)
		{
			cout << "3";
			if (!five_divide && !seven_divide)
			{
				cout << endl;
			} else {
				cout << " ";
			}
		}

		if (five_divide)
		{
			cout << "5";
			if (!seven_divide)
			{
				cout << endl;
			} else {
				cout << " ";
			}
		}

		if (seven_divide)
		{
			cout << "7" << endl;
		}
	}

	return 0;
}


// 总时间限制:
//     1000ms
// 内存限制:
//     65536kB

// 描述
//     输入一个整数，判断它能否被3，5，7整除，并输出以下信息：
//     1、能同时被3，5，7整除（直接输出3 5 7，每个数中间一个空格）；
//     2、能被其中两个数整除（输出两个数，小的在前，大的在后。例如：3 5或者 3 7或者5 7,中间用空格分隔）
//     3、能被其中一个数整除（输出这个除数）
//     4、不能被任何数整除；（输出小写字符'n',不包括单引号)
// 输入
//     一个数字
// 输出
//     一行数字,从小到大排列,包含3,5,7中为该输入的除数的数字,数字中间用空格隔开
// 样例输入

//     0
//     5
//     15
//     105

// 样例输出

//     3 5 7
//     5
//     3 5
//     3 5 7

// 提示
//     因为有多组测试数据,程序通过下面方式读入n

//     int n;
//     while(cin>>n)
//     {
//     //你的代码
//     }

//     good luck:) 