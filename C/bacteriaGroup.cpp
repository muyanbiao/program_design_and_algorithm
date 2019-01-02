#include <iostream>
using namespace std;

// 对繁殖率进行冒泡排序
void sortRate(int id[], double rateOfBorn[], int totalCnt) {
	for (int i = 0; i < totalCnt-1; ++i) 
	{	// 有totalCnt个数，只需要进行totalCnt-1此遍历，就可以了，因为当其他的totalCnt-1个数都已经有序之后，剩下的最后一个数一定是有序的？？？
		for (int j = 1; j < totalCnt - i; ++j)
		{	// 从第一个数开始，两两对比，前面的数大于后面的数的时候，交换两个数的位置
			// 一次遍历确定一个数的位置，第一次确定最大的那个数的位置，并且放到了最后面
			if (rateOfBorn[j-1] > rateOfBorn[j])
			{
				int tmpRate = rateOfBorn[j-1];
				rateOfBorn[j-1] = rateOfBorn[j];
				rateOfBorn[j] = tmpRate;

				int tmpid = id[j-1];
				id[j-1] = id[j];
				id[j] = tmpid;
			}
		}
	}
}

int main() {
	// 关键点在于：A、B两个亚种繁殖率差别很大，不同亚种之间的繁殖率之差一定大于同一个亚种之间的繁殖率之差

	int totalCnt;
	cin >> totalCnt;

	int id[totalCnt];
	double rateOfBorn[totalCnt];

	int beforeCnt, afterCnt;

	for (int i = 0; i < totalCnt; ++i)
	{
		cin >> id[i];

		cin >> beforeCnt >> afterCnt;

		rateOfBorn[i] = (double)afterCnt/(double)beforeCnt;
	}

	sortRate(id, rateOfBorn, totalCnt); // 对所有亚种的繁殖率进行排序

	int rateBorderIndex = 0; // 不同亚种之间的边界下标id
	double maxDiff = 0;

	for (int i = 1; i < totalCnt; ++i)
	{
		if ((rateOfBorn[i] - rateOfBorn[i-1]) > maxDiff)
		{
			maxDiff = (rateOfBorn[i] - rateOfBorn[i-1]);
			rateBorderIndex = i;
		}
	}

	cout << totalCnt - rateBorderIndex << endl;
	for (int i = rateBorderIndex; i < totalCnt; ++i)
	{
		cout << id[i] << endl;
	}

	cout << rateBorderIndex << endl;
	for (int i = 0; i < rateBorderIndex; ++i)
	{
		cout << id[i] << endl;
	}

	return 0;
}


// 编程题＃5：细菌实验分组
// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 有一种细菌分为A、B两个亚种，它们的外在特征几乎完全相同，仅仅在繁殖能力上有显著差别，A亚种繁殖能力非常强，B亚种的繁殖能力很弱。在一次为时一个 小时的细菌繁殖实验中，实验员由于疏忽把细菌培养皿搞乱了，请你编写一个程序，根据实验结果，把两个亚种的培养皿重新分成两组。

// 输入
// 输入有多行，第一行为整数n（n≤100），表示有n个培养皿。

// 其余n行，每行有三个整数，分别代表培养皿编号，试验前细菌数量，试验后细菌数量。

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