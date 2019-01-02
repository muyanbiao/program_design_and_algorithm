#include <iostream>
using namespace std;

struct Point
{
	int x;
	int y;
	bool isAnMaxPoint;
};

// 根据X冒泡排序
void sortPointArrByX(Point arr[], int cnt) {
	for (int i = 0; i < cnt - 1; ++i)
	{
		for (int j = 1; j < cnt - i; ++j)
		{
			if (arr[j-1].x > arr[j].x)
			{
				Point tmpPoint = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = tmpPoint;
			}
		}
	}
}

int main() {

	// 结构体来表示点
	Point points[100];

	int pointCnt;

	cin >> pointCnt;

	for (int i = 0; i < pointCnt; ++i)
	{
		cin >> points[i].x >> points[i].y;
		points[i].isAnMaxPoint = false;
	}

	for (int i = 0; i < pointCnt; ++i)
	{
		// 假设第i个点是极大点，然后和其他所有点对比，只要找到一个比i大的点，就说明i不是极大点
		bool iIsAnMaxPoint = true;

		for (int j = 0; j < pointCnt; ++j)
		{
			// 计算当前点 i 其他所有点之间的距离
			if (i == j)
			{
				continue;
			} else {
				if (points[j].x >= points[i].x && points[j].y >= points[i].y)
				{
					iIsAnMaxPoint = false;
					break;
				}
			}
		}

		points[i].isAnMaxPoint = iIsAnMaxPoint;
	}

	sortPointArrByX(points, pointCnt);

	int lastMaxPointIndex = 0;
	// 找到排序之后的最后一个极大点
	for (int i = 0; i < pointCnt; ++i)
	{
		if (points[i].isAnMaxPoint)
		{
			lastMaxPointIndex = i;
		}
	}

	for (int i = 0; i < pointCnt; ++i)
	{
		if (points[i].isAnMaxPoint)
		{
			if (i != lastMaxPointIndex) {
				cout << "(" << points[i].x << "," << points[i].y << ")" << ",";
			} else {
				cout << "(" << points[i].x << "," << points[i].y << ")" << endl;
			}
		}
	}

	return 0;
}

// 编程题＃4：寻找平面上的极大点
// 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 在一个平面上，如果有两个点(x,y),(a,b),如果说(x,y)支配了(a,b)，这是指x>=a,y>=b;

// 用图形来看就是(a,b)坐落在以(x,y)为右上角的一个无限的区域内。

// 给定n个点的集合，一定存在若干个点，它们不会被集合中的任何一点所支配，这些点叫做极大值点。

// 编程找出所有的极大点，按照x坐标由小到大，输出极大点的坐标。

// 本题规定：n不超过100，并且不考虑点的坐标为负数的情况。

// 输入
// 输入包括两行，第一行是正整数n，表示是点数，第二行包含n个点的坐标，坐标值都是整数，坐标范围从0到100，输入数据中不存在坐标相同的点。

// 输出
// 按x轴坐标最小到大的顺序输出所有极大点。

// 输出格式为:(x1,y1),(x2,y2),...(xk,yk)

// 注意：输出的每个点之间有","分隔,最后一个点之后没有",",少输出和多输出都会被判错

// 样例输入

// 5
// 1 2 2 2 3 1 2 3 1 4

// 样例输出
// (1,4),(2,3),(3,1)