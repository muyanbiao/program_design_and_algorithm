#include <iostream>
#include <iomanip>
using namespace std;

int main() {

	int n;
	int tmpIn;
	double cntOf18 = 0, cntOf19To35 = 0, cntOf35To60 = 0, cntOf60More = 0;
	cin >> n;
	int tmpN = n;
	while (tmpN--) {
		cin >> tmpIn;

		if (tmpIn <= 18) {
		 	++cntOf18;
		 } else if (tmpIn <= 35) {
		 	++cntOf19To35;
		 } else if (tmpIn <= 60) {
		 	++cntOf35To60;
		 } else {
		 	++cntOf60More;
		 }
	}

	double ratioOf18 = cntOf18 / n * 100;
	double ratioOf19To35 = cntOf19To35 / n * 100;
	double ratioOf36To60 = cntOf35To60 / n * 100;
	double ratioOf60More = cntOf60More / n * 100;

	cout << "1-18: " << fixed << setprecision(2) << ratioOf18 << "%" << endl;
	cout << "19-35: " << fixed << setprecision(2) << ratioOf19To35 << "%" << endl;
	cout << "36-60: " << fixed << setprecision(2) << ratioOf36To60 << "%" << endl;
	cout << "60-: " << fixed << setprecision(2) << ratioOf60More << "%" << endl;

	return 0;
}

// 编程题＃1：年龄与疾病
// 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 某医院想统计一下某项疾病的获得与否与年龄是否有关，需要对以前的诊断记录进行整理。

// 输入
// 共2行，第一行为过往病人的数目n（0 < n <= 100)，第二行为每个病人患病时的年龄。

// 输出
// 每个年龄段（分四段：18以下，19-35，36-60，大于60注意看样例输出的格式）的患病人数占总患病人数的比例，以百分比的形式输出，精确到小数点后两位（double）。关于c++的格式化的输入输出，请参考：http://www.cplusplus.com/reference/iomanip。也可以在网上搜索一下，资料很多的。

// 样例输入

// 10
// 1 11 21 31 41 51 61 71 81 91

// 样例输出

// 1-18: 20.00%
// 19-35: 20.00%
// 36-60: 20.00%
// 60-: 40.00%