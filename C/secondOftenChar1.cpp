#include <iostream>
using namespace std;

const int MAX_CNT = 5000;

// 转换成小写函数
char toLower(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return ch;
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 'a';
    return 0;
}

int main()
{
    char str[MAX_CNT] = {};
    unsigned int cntArr[26] = {};
    unsigned int orderArr[26] = {};
    int indexOfStr = 0;
    int seq = 0;
    unsigned int max1 = 0;
    unsigned int max2 = 0;

    cin.getline(str, MAX_CNT);
    while (str[indexOfStr]) {
        if(char ch = toLower(str[indexOfStr])) {
            int i = ch - 'a';
            cntArr[i]++;
            if (cntArr[i] > max1) {
                max1 = cntArr[i];
            }
            if (orderArr[i] == 0) {
                orderArr[i] = ++seq;
            }
        }
        indexOfStr++;
    }

    for (int i = 0; i < 26; i++) {
        if (cntArr[i] > max2 && cntArr[i] < max1) {
            max2 = cntArr[i];
        }
    }

    indexOfStr = -1;
    for (int i = 0; i < 26; i++) {
        if (cntArr[i] == max2) {
            if (indexOfStr < 0 || orderArr[indexOfStr] > orderArr[i])
                indexOfStr = i;
        }
    }
    if (indexOfStr >= 0) {
        char c1 = indexOfStr + 'A';
        char c2 = indexOfStr + 'a';
        cout << c1 << '+' << c2 << ':' << max2 << endl;
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
