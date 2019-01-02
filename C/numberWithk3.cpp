#include <iostream>
using namespace std;

int main() {

	int m, k;

	cin >> m >> k;

	int cntOf3 = 0;

	if (m % 19 == 0)
	{
		while (true) {
			 if (m % 10 == 3)
			 	cntOf3++;
			 m /= 10;
			 if (m <= 0) break;
		}
	}

	if (cntOf3 == k)
	{
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}


// 编程题＃1：含k个3的数
// 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 输入二个正整数m 和 k，其中1 < m < 100000，1 < k <5 ，判断m 能否被19整除，且恰好含有k个3，如果满足条件，则输出YES，否则，输出NO。

// 例如，输入：

// 43833 3

// 满足条件，输出YES

// 如果输入

// 39331 3

// 尽管有3个3，但不能被19整除，也不满足条件，应输出NO

// 输入
// m 和 k 的值，空格间隔

// 输出
// 满足条件时输出 YES，不满足时输出 NO

// 样例输入

// 43833 3

// 样例输出

// YES