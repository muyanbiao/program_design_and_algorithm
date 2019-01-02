#include <iostream>
using namespace std;

int main() {

	const int MAX_Line_Length = 80;

	int countOfChar[5] = {0};

	char inputLine[MAX_Line_Length];

	cin.getline(inputLine, MAX_Line_Length);

	for (int i = 0; inputLine[i] != '\0'; ++i)
	{
		if (inputLine[i] == 'a')
		{
			countOfChar[0]++;
		} else if (inputLine[i] == 'e')
		{
			countOfChar[1]++;
		} else if (inputLine[i] == 'i')
		{
			countOfChar[2]++;
		} else if (inputLine[i] == 'o')
		{
			countOfChar[3]++;
		} else if (inputLine[i] == 'u')
		{
			countOfChar[4]++;
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		if (i < 4)
		{
			cout << countOfChar[i] << " ";
		} else {
			cout << countOfChar[i] << endl;
		}
	}

	return 0;
}

// 求字母的个数
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 在一个字符串中找出元音字母a,e,i,o,u出现的次数。
// 输入
// 输入一行字符串（字符串中可能有空格，请用gets(s)方法把一行字符串输入到字符数组s中），字符串长度小于80个字符。
// 输出
// 输出一行，依次输出a,e,i,o,u在输入字符串中出现的次数，整数之间用空格分隔。
// 样例输入
// If so, you already have a Google Account. You can sign in on the right.
// 样例输出
// 5 4 3 7 3
// 提示
// 注意，只统计小写元音字母a,e,i,o,u出现的次数。