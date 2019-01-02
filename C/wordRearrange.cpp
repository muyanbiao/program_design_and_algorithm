#include <iostream>
using namespace std;

int main() {

    int wordsCnt;

    char str[1000];
    char *strPointer = str; // 字符数组的指针，只想字符数组的第一个元素
    int currentCharCnt = 0; // 当前行的字符数

    cin >> wordsCnt;
    cin.ignore();
    cin.getline(str, 1000);

    // FIXME: 我这种做法有个问题，就是每一行后面可能会有多个空格

    // 用指针来解决问题，指针从第0个元素开始不停向后遍历，
    // 当字符数量达到80之后，判断当前字符是否为空格
    // 是空格，用换行符代替
    // 不是空格，指针向前移动，直到遇到空格，替换为换行符
    // 指针继续向后遍历，直到遇到'\0'为止
    while (*strPointer != '\0') {
        currentCharCnt++;

        if (currentCharCnt > 80)
        {
            if (*strPointer == ' ')
            {
                *strPointer = '\n';
                currentCharCnt = 0;
            } else {
                while(true) {
                    strPointer--;
                    if (*strPointer == ' ')
                    {
                        *strPointer = '\n';
                        currentCharCnt = 0;
                        break;
                    }
                }
            }
        }

        strPointer++;
    }

    cout << str << endl;

    return 0;
}

// 编程题＃3：文字排版

// 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 给一段英文短文，单词之间以空格分隔（每个单词包括其前后紧邻的标点符号）。请将短文重新排版，要求如下：

// 每行不超过80个字符；每个单词居于同一行上；在同一行的单词之间以一个空格分隔；行首和行尾都没有空格。

// 输入
// 第一行是一个整数n，表示英文短文中单词的数目. 其后是n个以空格分隔的英文单词（单词包括其前后紧邻的标点符号，且每个单词长度都不大于40个字母）。

// 输出
// 排版后的多行文本，每行文本字符数最多80个字符，单词之间以一个空格分隔，每行文本首尾都没有空格。

// 样例输入


// 84
// 84
// One sweltering day, I was scooping ice cream into cones and told my four children they could "buy" a cone from me for a hug. Almost immediately, the kids lined up to make their purchases. The three youngest each gave me a quick hug, grabbed their cones and raced back outside. But when my teenage son at the end of the line finally got his turn to "buy" his ice cream, he gave me two hugs. "Keep the changes," he said with a smile.

// 样例输出

// 84
// One sweltering day, I was scooping ice cream into cones and told my four
// children they could "buy" a cone from me for a hug. Almost immediately, the kids
// lined up to make their purchases. The three youngest each gave me a quick hug,
// grabbed their cones and raced back outside. But when my teenage son at the end
// of the line finally got his turn to "buy" his ice cream, he gave me two hugs.
// "Keep the changes," he said with a smile.
