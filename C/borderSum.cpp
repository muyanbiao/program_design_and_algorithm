#include <iostream>
using namespace std;

int main() {

	int cases;
	cin >> cases;

	while(cases--) {
		int m, n;

		int arr[100][100];

		cin >> m >> n;

		// 普通解法
		// 先求第0行+第m-1行的和
		// 再求第0列+第n-1列的和
		// 减去四个角的和（各自被加了2次）
		int sumOfBorder = 0;

		// 数据读入
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> arr[i][j];
				if (i == 0 || i == m-1 || j == 0 || j == n-1)
				{
					sumOfBorder += arr[i][j];
				}
			}
		}

		// FIXME: 很奇怪，如果用这种遍历边界的方法提交到poj，就会WA，
		// 如果用上面那种遍历过程中判断是否边界的情况就会AC
		// for (int j = 0; j < n; ++j)
		// {
		// 	sumOfBorder += arr[0][j] + arr[m-1][j];
		// }

		// for (int i = 0; i < m; ++i)
		// {
		// 	sumOfBorder += arr[i][0] + arr[i][n-1];
		// }
		
		cout << sumOfBorder << endl;
	}

	return 0;
}

// 编程题＃1：计算矩阵边缘元素之和
// 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 输入一个整数矩阵，计算位于矩阵边缘的元素之和。所谓矩阵边缘的元素，就是第一行和最后一行的元素以及第一列和最后一列的元素。

// 输入
// 第一行为整数k，表示有k组数据。

// 每组数据有多行组成，表示一个矩阵：

// 第一行分别为矩阵的行数m和列数n（m < 100，n < 100），两者之间以空格分隔。

// 接下来输入的m行数据中，每行包含n个整数，整数之间以空格作为间隔。

// 输出

// 输出对应矩阵的边缘元素和，一个一行。

// 样例输入

// 2
// 4 4
// 1 1 1 1
// 0 0 0 0
// 1 0 1 0
// 0 0 0 0
// 3 3
// 3 4 1
// 3 7 1
// 2 0 1

// 样例输出

// 5
// 15
