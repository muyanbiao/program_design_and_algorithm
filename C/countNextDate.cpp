#include <iostream>
#include <iomanip>
using namespace std;

// 判断是否为闰年
bool isLeapYear(int year) {
	if (year % 100 == 0)
	{
		if (year % 400 == 0)
		{
			return true;
		}
	} else {
		if (year % 4 == 0)
		{
			return true;
		}
	}
	return false;
}

// 根据是否闰年获取每月的天数
void getDaysOfMonthByYear(int year, int arr[]) {
	const int arrCnt = 12;
	int leapDaysOfMonthByYear[arrCnt] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int normalDaysOfMonthByYear[arrCnt] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (isLeapYear(year)) {
		for (int i = 0; i < arrCnt; ++i)
		{
			arr[i] = leapDaysOfMonthByYear[i];
		}
	} else {
		for (int i = 0; i < arrCnt; ++i)
		{
			arr[i] = normalDaysOfMonthByYear[i];
		}
	}
}

int main() {
	// 关键是：从日到月到年的进位问题，超过当月的总天数，天数置1，月数加1，超过12个月，月数置1，年数加1
	// 第二个关键点是：闰年和非闰年不同月数的天数，其实也就是2月的天数

	// 输入数据，三个数字+2个字符
	int year, month, day;
	char dash;
	cin >> year >> dash >> month >> dash >> day;

	int daysOfMonthByYear[12];

	getDaysOfMonthByYear(year, daysOfMonthByYear);

	day += 1; // 计算天

	// 计算月
	if (day > daysOfMonthByYear[month-1]) { 
		month += 1;
		day = 1;
	}

	// 计算年
	if (month > 12)
	{
		year += 1;
		month = 1;
	}

	cout << year << dash 
	<< setfill('0') << setw(2) << month << dash 
	<< setfill('0') << setw(2) << day << endl;

	return 0;
}

// 编程题＃4：Tomorrow never knows？
// 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 甲壳虫的《A day in the life》和《Tomorrow never knows》脍炙人口，如果告诉你a day in the life,真的会是tomorrow never knows?相信学了计概之后这个不会是难题，现在就来实现吧。

// 读入一个格式为yyyy-mm-dd的日期（即年－月－日），输出这个日期下一天的日期。可以假定输入的日期不早于1600-01-01，也不晚于2999-12-30。

// 输入
// 输入仅一行，格式为yyyy-mm-dd的日期。

// 输出
// 输出也仅一行，格式为yyyy-mm-dd的日期

// 样例输入

// 2010-07-05

// 样例输出
// 2010-07-06