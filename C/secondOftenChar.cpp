#include <iostream>

using namespace std;

char toLower(char c) {
	if (c >= 'a' && c <= 'z')
	{
		return c;
	} else if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 'a';
	}
	return c;
}

char toUpper(char c) {
	if (c >= 'a' && c <= 'z')
	{
		return c - 'a' + 'A';
	} else if (c >= 'A' && c <= 'Z') {
		return c;
	}
	return c;
}

int main() {

	// 先把所有字母变成小写
	// 把字符a-z - a作为数组下标，统计各自的数量，并在统计的过程中记录出现次数最多的字母
	// 现在的关键是如何处理出现次数一样时的情况，怎么记录谁是第一次出现的
	// 一种方法是统计完所有数量之后，逐个字符遍历过去，找到出现次数第二多的字母
	char str[5001] = {};
	int indexOfStr = 0;
	int cntArr[26] = {0};
	char tmpChar;
	int maxCnt = 0;
	int secondMaxCnt = 0;

	// 数据的读入
	cin.getline(str, 5001);
	while(str[indexOfStr] != '\0') {

		tmpChar = toLower(str[indexOfStr]);
		str[indexOfStr] = tmpChar;

		if (tmpChar >= 'a' && tmpChar <= 'z')
		{
			// 记录所有字符出现的次数和出现次数最多的字符次数
			cntArr[tmpChar - 'a']++;
			if (cntArr[tmpChar - 'a'] > maxCnt)
			{
				maxCnt = cntArr[tmpChar - 'a'];
			}
		}
		indexOfStr++;
	}

	// 找出出现次数第二多的字母的次数
	for (int i = 0; i < 26; ++i)
	{
		if (cntArr[i] > secondMaxCnt && cntArr[i] < maxCnt)
		{
			secondMaxCnt = cntArr[i];
		}
	}

	// cout << str << endl;

	// 遍历字符数组，找出出现次数第二多的第一个字母
	for (int i = 0; i < indexOfStr; ++i)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			// FXIME:这里有一个很大的漏洞，出现次数第二多的字母的次数不一定是maxCnt-1，可能是maxCnt-2、maxCnt-3等等。。。
			// if (cntArr[str[i] - 'a'] == maxCnt - 1)
			// { // 找到第一个满足条件：出现次数第二多的字母，停止遍历，输出找到的字母
			// 	char capsChar = toUpper(str[i]);
			// 	cout << capsChar << '+' << str[i] << ':' << maxCnt - 1 << endl;
			// 	break;
			// }

			if (cntArr[str[i] - 'a'] == secondMaxCnt)
			{ // 找到第一个满足条件：出现次数第二多的字母，停止遍历，输出找到的字母
				char capsChar = toUpper(str[i]);
				cout << capsChar << '+' << str[i] << ':' << secondMaxCnt << endl;
				break;
			}
		}
	}

	return 0;
}

// 编程题＃2：字符串中次数第2多的字母
// 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 输入一串长度不超过500个符号的字符串，输出在串中出现第2多的英语字母(大小写字母认为相同)和次数（如果串中有其它符号，则忽略不考虑）。如果有多个字母的次数都是第2多，则按串中字母出现的顺序输出第1个。

// 例 ab&dcAab&c9defgb

// 这里，a 和 b都出现3次，c和d都出现2次，e、f 和 g 各出现1次，其中的符号&和9均忽略不考虑。因此，出现第2多的应该是 c 和 d，但是 d 开始出现的位置在 c 的前面，因此，输出为

// D+d:2

// (假定在字符串中，次数第2多的字母总存在)

// 输入
// 一个字符串

// 输出
// 大写字母+小写字母:个数

// 样例输入

// ab&dcAab&c9defgb

// 样例输出
// D+d:2
