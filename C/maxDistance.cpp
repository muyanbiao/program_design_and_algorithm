#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

struct point
{
	double x;
	double y;
};

int main() {
	int count;
	point nodeArr[10000];

	double maxDistance = 0.0;

	cin >> count;

	for (int i = 0; i < count; ++i)
	{
		cin >> nodeArr[i].x >> nodeArr[i].y;
		if (i > 0)
		{
			for (int j = 0; j < i; ++j)
			{
				double xDistance = nodeArr[i].x - nodeArr[j].x;
				double yDistance = nodeArr[i].y - nodeArr[j].y;
				double tmpDistance = sqrt(xDistance * xDistance + yDistance * yDistance);
				if (tmpDistance > maxDistance)
				{
					maxDistance = tmpDistance;
				}
			}
		}
	}

	cout << fixed << setprecision(4) << maxDistance << endl;

	return 0;
}

// 编程题＃3：最远距离

// 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

// 注意： 总时间限制: 1000ms 内存限制: 65536kB
// 描述

// 给定一组点(x,y)，求距离最远的两个点之间的距离。
// 输入

// 第一行是点数n（n大于等于2）

// 接着每一行代表一个点，由两个浮点数x y组成。
// 输出

// 输出一行是最远两点之间的距离。

// 使用cout << fixed << setprecision(4) << dis << endl;输出距离值并精确到小数点后4位。

// fixed和setprecision是在<iomanip>头文件里定义的格式控制操作符，需要#include <iomanip>.
// 样例输入
// 6
// 34.0 23.0
// 28.1 21.6
// 14.7 17.1
// 17.0 27.2
// 34.7 67.1
// 29.3 65.1

// 样例输出
// 53.8516

// 提示

// 注意在内部计算时最好使用double类型，float精准度不能满足本题测试数据要求。