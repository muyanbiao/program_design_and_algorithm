#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

char inputStr[101];
int inputStrCnt = 0;

void bracketsPair() {
	int indexOfLeftBrackets = inputStrCnt-1;

	// 先找到最后一个左括号
	while(true) {
		if (inputStr[indexOfLeftBrackets] == '(' || indexOfLeftBrackets < 0)
		{
			break;
		} else {
			indexOfLeftBrackets--;
		}
	}

	// 把左括号的位置的内容置1，假设它没有与之匹配的右括号
	inputStr[indexOfLeftBrackets] = '1';

	// 然后开始找他的对应的右括号，如果找到，就把它们都置成0
	if (indexOfLeftBrackets>=0) // 只有左括号的下标在合法范围内是，才有必要扫描寻找后面的右括号
	{
		int indexOfRightBrackets = indexOfLeftBrackets+1;
		for (indexOfRightBrackets = indexOfLeftBrackets+1; indexOfRightBrackets < inputStrCnt; ++indexOfRightBrackets)
		{
			if (inputStr[indexOfRightBrackets] == ')')
			{ // 找到与之对应的右括号，把左右括号都置为0
				inputStr[indexOfLeftBrackets] = inputStr[indexOfRightBrackets] = '0';
				break;
			}
		}
	}

	// 如果还没处理所有的左括号，则递归调用括号配对方法，直到在字符串中找不到左括号位置
	if (indexOfLeftBrackets > 0)
	{
		bracketsPair();
	}
}

int main() {

    memset(inputStr, '\0', 101); // 用之前，先清空

	while(cin.getline(inputStr, 101)) { // 循环读入数据，直到文件末尾

		cout << inputStr << endl;

//		while(inputStr[inputStrCnt] != '\0') inputStrCnt++;

        inputStrCnt = strlen(inputStr);

		// 把括号之外的所有字符都置 0
		for (int i = 0; i < inputStrCnt; ++i)
		{
			if (inputStr[i] != '(' && inputStr[i] != ')')
			{
				inputStr[i] = '0';
			}
		}

		bracketsPair();


		for (int i = 0; i < inputStrCnt; ++i)
		{
			if (inputStr[i] == '1')
			{
                cout << '$';
			} else if (inputStr[i] == ')')
			{
				// 这里非常坑，只能输出'?'的字符，不能输出双引号的"?"
                cout << '?';
			} else {
                cout << ' ';
			}
			// 而且也不能把'?'赋值给inputStr，再cout<<inpustStr，这样也会报错
		}

		cout << endl;

		// 在读入下一行字符数组之前，先清空当前数据
		memset(inputStr, '\0', 101);
		inputStrCnt = 0;
	}

	return 0;
}



// 编程题＃4：扩号匹配问题
// 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 在某个字符串（长度不超过100）中有左括号、右括号和大小写字母；规定（与常见的算数式子一样）任何一个左括号都从内到外与在它右边且距离最近的右括号匹配。写一个程序，找到无法匹配的左括号和右括号，输出原来字符串，并在下一行标出不能匹配的括号。不能匹配的左括号用"$"标注,不能匹配的右括号用"?"标注.

// 输入
// 输入包括多组数据，每组数据一行，包含一个字符串，只包含左右括号和大小写字母，字符串长度不超过100

// 注意：cin.getline(str,100)最多只能输入99个字符！

// 输出
// 对每组输出数据，!!!输出两行，第一行包含原始输入字符!!!，第二行由"$","?"和空格组成，"$"和"?"表示与之对应的左括号和右括号不能匹配。

// 样例输入

// ((ABCD(x)
// )(rttyy())sss)(

// 样例输出
// ((ABCD(x)
// $$
// )(rttyy())sss)(
// ?            ?$