#include <iostream>
using namespace std;

// 检查当前排序是否满足A只答对了一个
bool checkIfAHasOnlyOneRight(int i, int j, int k, int l) {
	if (i == 3 && j != 1 && k != 2 && l != 4)
		return true;
	else if (i != 3 && j == 1 && k != 2 && l != 4)
		return true;
	else if (i != 3 && j != 1 && k == 2 && l != 4)
		return true;
	else if (i != 3 && j != 1 && k != 2 && l == 4)
		return true;
	else
		return false;
}

// 检查当前排序是否满足A只答对了一个
bool checkIfBHasOnlyOneRight(int i, int j, int k, int l) {
	if (i == 2 && j != 4 && k != 3 && l != 1)
		return true;
	else if (i != 2 && j == 4 && k != 3 && l != 1)
		return true;
	else if (i != 2 && j != 4 && k == 3 && l != 1)
		return true;
	else if (i != 2 && j != 4 && k != 3 && l == 1)
		return true;
	else
		return false;
}

// 检查当前排序是否满足A只答对了一个
bool checkIfCHasOnlyOneRight(int i, int j, int k, int l) {
	if (j == 3 && l != 4)
		return true;
	else if (j != 3 && l == 4)
		return true;
	else
		return false;
}

// 检查当前排序是否满足A只答对了一个
bool checkIfDHasOnlyOneRight(int i, int j, int k, int l) {
	if (i == 1 && j != 3 && k != 4 && l != 2)
		return true;
	else if (i != 1 && j == 3 && k != 4 && l != 2)
		return true;
	else if (i != 1 && j != 3 && k == 4 && l != 2)
		return true;
	else if (i != 1 && j != 3 && k != 4 && l == 2)
		return true;
	else
		return false;
}

// 检查排名顺序是否满足题设条件，如果满足，就停止循环，输出排序结果
bool checkIfRangeIsValid(int i, int j, int k, int l) {
	if (checkIfAHasOnlyOneRight(i, j, k, l) && 
		checkIfBHasOnlyOneRight(i, j, k, l) && 
		checkIfCHasOnlyOneRight(i, j, k, l) && 
		checkIfDHasOnlyOneRight(i, j, k, l))
	{
		return true;
	}
	return false;
}

int main() {
	int a[4] = {1, 2, 3, 4};

	// 遍历24中排名方式，依次判断是否满足题设条件
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (j == i)
			{
				continue;
			} else {

				for (int k = 0; k < 4; ++k)
				{
					if (k == i || k == j)
					{
						continue;
					} else {
						for (int l = 0; l < 4; ++l)
						{
							if (l == i || l == j || l == k)
							{
								continue;
							} else {
								if (checkIfRangeIsValid(a[i], a[j], a[k], a[l])) {
									cout << a[i] << endl
									<< a[j] << endl
									<< a[k] << endl
									<< a[l] << endl;
									return 0; // 如果这里只是调用break，就会有2个结果，1、2、3、4和4、3、2、1
											  // 调用return可以结束main函数的执行，只打印一个结果
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}

// 编程题＃2：四大湖
// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 我国有4大淡水湖。

// A说：洞庭湖最大，洪泽湖最小，鄱阳湖第三。

// B说：洪泽湖最大，洞庭湖最小，鄱阳湖第二，太湖第三。

// C说：洪泽湖最小，洞庭湖第三。

// D说：鄱阳湖最大，太湖最小，洪泽湖第二，洞庭湖第三。

// 已知这4个湖的大小均不相等，4个人每人仅答对一个，

// 请编程按照鄱阳湖、洞庭湖、太湖、洪泽湖的顺序给出他们的大小排名。

// 输入
// 无。

// 输出
// 输出为4行，第1行为鄱阳湖的大小名次，从大到小名次分别表示为1、2、3、4；第2、3、4行分别为洞庭湖、太湖、洪泽湖的大小名次。

// 样例输入
// (无)

// 样例输出
// 3(样例输出仅供格式参考，此题只有一个解， 。)