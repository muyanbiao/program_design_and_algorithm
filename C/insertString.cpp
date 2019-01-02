#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int main() {
	char str[15], substr[4];
	char inputString[15];

	while(cin.getline(inputString, 15)) { // 读入整行字符串

		int indexOfInputString = 0, indexOfStr = 0, indexOfSubStr = 0;
		bool isReadingFirstWord = true;

		int maxIndexOfStr = 0;
		char maxCharOfStr = '\0';

		while(inputString[indexOfInputString] != 0) { // 处理数据拆分：根据空格拆成2个字符数组
			if (inputString[indexOfInputString] == ' ')
			{
				isReadingFirstWord = false;
				indexOfInputString++;
			}

			if (isReadingFirstWord)
			{
				str[indexOfStr] = inputString[indexOfInputString++];

				// 在拆分数据的过程中就找到最大字符的下标
				if (str[indexOfStr] > maxCharOfStr)
				{
					maxCharOfStr = str[indexOfStr];
					maxIndexOfStr = indexOfStr;
				}
				
				indexOfStr++;
			} else {
				substr[indexOfSubStr++] = inputString[indexOfInputString++];
			}
		}

		// 从最后一个字符开始，最大字符下标后面的字符向数组后面移动三个位置
		for (int i = indexOfStr - 1 ; i > maxIndexOfStr; --i)
		{
			str[i+3] = str[i];
		}
		indexOfStr += 3;

		// 插入substr中的三个字符到最大字符下标之后
		for (int i = 0; i < 3; ++i)
		{
			str[maxIndexOfStr+1+i] = substr[i];
		}

		str[indexOfStr] = '\0';

		cout << str << endl;
	}

	return 0;
}

// 编程题＃5：字符串插入

// 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

// 注意： 总时间限制: 1000ms 内存限制: 65536kB、
// 描述

// 有两个字符串str和substr，str的字符个数不超过10，substr的字符个数为3。（字符个数不包括字符串结尾处的'\0'。）将substr插入到str中ASCII码最大的那个字符后面，若有多个最大则只考虑第一个。
// 输入

// 输入包括若干行，每一行为一组测试数据，格式为

// str substr
// 输出

// 对于每一组测试数据，输出插入之后的字符串。
// 样例输入
// abcab eee
// 12343 555

// 样例输出
// abceeeab
// 12345553

// 提示

// 这题有多组输入，请参照第二题的提示依次读入和处理每一组数据。

// 如果使用了字符串函数，比如strlen，请包含cstring头文件 #include <cstring>。