#include <iostream>
using namespace std;

// 先假设有一个函数，可以递归解决我们放苹果的问题
// m - 苹果数
// n - 盘子数
int putApple(int m, int n) {
	// 分两种情况考虑
	// 苹果数 > 盘子数
	// 盘子数 > 苹果数

	if (m <= 1 || n <= 1)
	{
		return 1;
	} else if (n > m) 
	{	// 盘子数 > 苹果数
		// 无论怎么放，都会空 n-m 个盘子，可以把多余的盘子去掉，直接求解m个盘子的情况
		return putApple(m, m);
	} else {
		// 苹果数 >= 盘子数
		// 再分成两种情况：1. 盘子放不满 2. 盘子能放满
		// 1. 盘子放不满 - 空一个盘子的时候
		// 2. 盘子能放满 - 所有盘子里都至少有一个苹果
		return putApple(m, n-1) + putApple(m-n,n);
	}
}

int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; ++i)
	{
		int m, n;
		cin >> m >> n;
		cout << putApple(m, n) << endl;
	}

	return 0;
}

// 1664:放苹果
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。
// 输入
// 第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。
// 输出
// 对输入的每组数据M和N，用一行输出相应的K。
// 样例输入
// 1
// 7 3
// 样例输出
// 8
// 来源
// lwx@POJ