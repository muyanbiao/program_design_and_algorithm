#include <iostream>
using namespace std;

int main() {
	// 先输入数据：编号、试验前细菌数量、试验后细菌数量
	// 处理数据，保存编号、繁殖率（根据试验前、后的细菌数量计算得出，然后直接保存）
	// 根据繁殖率大小，同时对编号和繁殖率排序
	// 根据关键条件：由于亚种之间的繁殖率差异远远大于亚种内部的繁殖率差值，所以亚种之间繁殖率的差值一定大于亚种内部的繁殖率差值
	// 只要找到差值最大的那两个繁殖率的下标，就能区分开两个亚种

	int n;

	int id[100];

	double beforeCnt, afterCnt, rate[100];

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> id[i] >> beforeCnt >> afterCnt;
		rate[i] = afterCnt / beforeCnt;
	}

	// 先把繁殖率从小到大排序
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 1; j < n - i; ++j)
		{
			if (rate[j-1] > rate[j])
			{

				int tmpId = id[j-1];
				id[j-1] = id[j];
				id[j] = tmpId;

				int tmpRate = rate[j-1];
				rate[j-1] = rate[j];
				rate[j] = tmpRate;
			}
		}
	}

	// 顺次两两相减，找到差值最大的两个亚种，获取繁殖能力大的的那个下标和对应的繁殖率
	double maxDiff = 0;
	int maxDiffIndex = 0;

	for (int i = 1; i < n; ++i)
	{
		double tmpRateDiff = rate[i] - rate[i-1]; 
		if (tmpRateDiff > maxDiff)
		{
			maxDiff = tmpRateDiff;
			maxDiffIndex = i;
		}
	}

	// cout << "id:";

	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << id[i] << " ";
	// }

	// cout << endl << "rate: ";

	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << rate[i] << " ";
	// }

	// cout << endl;

	// 输出A亚种（繁殖能力强）数量和培养皿编号列表
	cout << n - maxDiffIndex << endl;
	for (int i = maxDiffIndex; i < n; ++i)
	{
		cout << id[i] << endl;
	}

	// 输出B亚种（繁殖能力弱）数量和培养皿编号列表
	cout << maxDiffIndex << endl;
	for (int i = 0; i < maxDiffIndex; ++i)
	{
		cout << id[i] << endl;
	}

	return 0;
}


// ＃1：细菌实验分组
// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 有一种细菌分为A、B两个亚种，它们的外在特征几乎完全相同，仅仅在繁殖能力上有显著差别，A亚种繁殖能力非常强，B亚种的繁殖能力很弱。在一次为时一个小时的细菌繁殖实验中，实验员由于疏忽把细菌培养皿搞乱了，请你编写一个程序，根据实验结果，把两个亚种的培养皿重新分成两组。

// 细菌繁殖能力（繁殖率）的量化标准为一个小时内细菌数量增长的比例（繁殖率 = 一小时后细菌数量 / 原本细菌数量）。

// 两个亚种繁殖能力差异很大，这意味着对于任意两个同种细菌培养皿的繁殖率的测量值之间的差异要小于任意两个异种细菌培养皿繁殖率的测量值之间的差异。即：


// 输入
// 输入有多行，第一行为整数n（n≤100），表示有n个培养皿。

// 其余n行，每行有三个整数，分别代表培养皿编号，试验前细菌数量，试验后细菌数量。假设试验没有误差。

// 输出
// 输出有多行：

// 第一行输出A亚种培养皿的数量，其后每行输出A亚种培养皿的编号，按繁殖率升序排列。

// 然后一行输出B亚种培养皿的数量，其后每行输出B亚种培养皿的编号，也按繁殖率升序排列。

// 样例输入

// 5
// 1 10 3456
// 2 10 5644
// 3 10 4566
// 4 20 234
// 5 20 232

// 样例输出

// 3
// 1
// 3
// 2
// 2
// 5
// 4

// 提示
// 亚种内部，细菌繁殖能力差异远远小于亚种之间细菌繁殖能力的差异。

// 也就是说，亚种间任何两组细菌的繁殖率之差都比亚种内部两组细菌的繁殖率之差大。