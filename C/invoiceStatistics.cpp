#include <iostream>
#include <iomanip>
using namespace std;

struct Invoice
{
	char name;
	float value;
};

int main() {
	// 几个关键点：1. 输入数据的处理 2. 数据的存储结构 3. 分类合并计算 4. 输出结构
	Invoice invoiceArr[3][100];
	int countArr[3];

	float sumById[3] = {0,0,0}; // 根据用户Id汇总
	float sumByName[3] = {0,0,0}; // 根据用户名汇总

	int id;
	int count;
	for (int i = 0; i < 3; ++i) {

		cin >> id;
		cin >> count;

		countArr[id-1] = count;

		for (int j = 0; j < count; ++j)
		{
			cin >> invoiceArr[id-1][j].name >> invoiceArr[id-1][j].value;
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < countArr[i]; ++j)
		{
			sumById[i] += invoiceArr[i][j].value;
			sumByName[invoiceArr[i][j].name - 'A'] += invoiceArr[i][j].value;
			
			// cout << invoiceArr[i][j].name << " " << invoiceArr[i][j].value << " ";
		}
	}
	
	for (int i = 0; i < 3; ++i)
	{
		cout << i + 1 << ' ' << fixed << setprecision(2) << sumById[i] << endl;
	}

	for (int i = 0; i < 3; ++i)
	{
		if (i == 0) {
			cout << "A" << ' ';
		} else if (i == 1) {
			cout << "B" << ' ';
		} else if (i == 2) {
			cout << "C" << ' ';
		}
		cout << fixed << setprecision(2) << sumByName[i] << endl;
	}

	return 0;

}

// 编程题＃3：发票统计
// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 有一个小型的报账系统，它有如下功能：

// （1）统计每个人所报发票的总钱数

// （2）统计每类发票的总钱数

// 将此系统简化为如下：假设发票类别共有A、B、C三种;一共有三个人，ID分别为1、2、3。

// 输入
// 系统输入包含三行，每行第一个数为人员ID（整型，1或2或3），第二个数为发票总张数(张数不超过100)，之后是多个发票类别（字符型，A或B或C）和相应发票金额（单进度浮点型,不超过1000.0）。

// 输出
// 输出包含六行，前三行为每人（按ID由小到大输出）所报发票总钱数（保留两位小数），后三行为每类发票的总钱数（保留两位小数）。

// 样例输入

// 1 5 A 1.0 A 2.0 C 1.0 B 1.0 C 1
// 3 3 B 1 C 2 C 1
// 2 4 B 1 A 1 C 1 A 1

// 样例输出

// 1 6.00
// 2 4.00
// 3 4.00
// A 5.00
// B 3.00
// C 6.00