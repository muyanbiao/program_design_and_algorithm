#include <iostream>
using namespace std;

int main() {

	double N, K;

	while(cin >> N >> K) {

		int M = 1;
		double tmpN = N;
		double P = 200.0;

		while(true) {
			if (M > 20)
			{
				cout << "Impossible" << endl;
				break;
			}

			if (tmpN >= P)
			{
				cout << M << endl;
				break;
			} else {
				M++;
                tmpN += N;
				P *= (1.0+K/100.0);
			}
		}
	}

	return 0;
}

// 4022:买房子
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 某程序员开始工作，年薪N万，他希望在中关村公馆买一套60平米的房子，现在价格是200万，假设房子价格以每年百分之K增长，并且该程序员未来年薪不变，且不吃不喝，不用交税，每年所得N万全都积攒起来，问第几年能够买下这套房子？（第一年年薪N万，房价200万）

// 输入
// 一行，包含两个正整数N（10 <= N <= 50）, K（1 <= K <= 20），中间用单个空格隔开。
// 输出
// 如果在第20年或者之前就能买下这套房子，则输出一个整数M，表示最早需要在第M年能买下，否则输出Impossible。
// 样例输入
// 50 10
// 样例输出
// 8