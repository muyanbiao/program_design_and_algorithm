#include <iostream>
#include <math.h>
using namespace std;

int main() {
	// 1升 = 1000毫升 = 1000立方厘米
	// 喝水的桶数 = 喝水总量/每桶的容量
	// 关键是要对除得的结果进行向上取整，保证大象可以喝够20L

	int h, r;

	cin >> h >> r;

	double totalVolume = 20 * 1000;
	double itemVolume = 3.14159 * r * r * h;

	double itemCnt = totalVolume / itemVolume;

	cout << ceil(itemCnt) << endl;

	return 0;

}

// 编程题＃2：大象喝水

// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 一只大象口渴了，要喝20升水才能解渴，但现在只有一个深h厘米，底面半径为r厘米的小圆桶(h和r都是整数)。问大象至少要喝多少桶水才会解渴。

// 输入
// 输入有一行：包行两个整数，以一个空格分开，分别表示小圆桶的深h和底面半径r，单位都是厘米。

// 输出
// 输出一行，包含一个整数，表示大象至少要喝水的桶数。

// 样例输入

// 第一组
// 23 11
// 第二组
// 1 1

// 样例输出

// 第一组
// 3
// 第二组
// 6367

// 提示
// 如果一个圆桶的深为h厘米，底面半径为r厘米，那么它最多能装Pi * r * r * h立方厘米的水。(设Pi=3.14159)

// 1升 = 1000毫升

// 1毫升 = 1 立方厘米