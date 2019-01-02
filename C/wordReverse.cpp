#include <iostream>
using namespace std;

int indexOfStr = 0;
char str[501];

// 先读入所有字符串中的负数据，然后对字符数组进行处理
// 遇到空格，就返回真，否则继续递归调用wordReverse()
// 每次调用wordReverse，数组下标指针就向后移动一个，只要没有遇到空格，就继续调用wordReverse()
// 遇到了空格，就通过while循环不停地调用wordReverse()，并输出遇到的空格

// 这道题同时用到了递归来逆序输出读入的字符这一特点 和
// 数组下标不停递增来保证读完整个字符数组
bool wordReverse() {
	char tmpChar = str[indexOfStr++];
	// indexOfStr++;
	if (tmpChar == ' ')
	{
		return true;
	}

	if (tmpChar != ' ' && tmpChar != '\0')
	{
		wordReverse();
		cout << tmpChar;
	}
	return true;
}

int main () {
	
	cin.getline(str, 501);
	while (str[indexOfStr] != '\0') {
		if (wordReverse() == true)
		{
			cout << ' ';
		}
	}

	cout << endl;

	return 0;
}

// 1:单词翻转
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 输入一个句子（一行），将句子中的每一个单词翻转后输出。

// 输入
// 只有一行，为一个字符串，不超过500个字符。单词之间以空格隔开。
// 输出
// 翻转每一个单词后的字符串，单词之间的空格需与原文一致。
// 样例输入
// hello world
// 样例输出
// olleh dlrow