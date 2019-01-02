#include <iostream>
using namespace std;

int main() {

    int maxLen = 0;
    char s[500];

    cin.getline(s, 500);

    int tmpLen = 0;
    int index = 0;
    int maxIndex = 0; // 最长单词的最后一个字符后面的字符的下标

    while(true) { // 遍历字符串，找出最长的字符串长度

        if (s[index] != ' ' && s[index] != '.')
        {
            tmpLen++;
        } else {
            if (tmpLen > maxLen)
            {
                maxLen = tmpLen;
                maxIndex = index;
            }

            tmpLen = 0;
        }

        if (s[index] == '.') break;

        index++;
    }

    for (int i = maxIndex - maxLen; i < maxIndex; ++i) {
        cout << s[i];
    }

    cout << endl;

    return 0;
}

// 最长单词2
// 总时间限制: 1000ms 内存限制: 65536kB
// 描述
// 一个以'.'结尾的简单英文句子，单词之间用空格分隔，没有缩写形式和其它特殊形式，求句子中的最长单词。

// 输入
// 一个以'.'结尾的简单英文句子（长度不超过500），单词之间用空格分隔，没有缩写形式和其它特殊形式。
// 输出
// 该句子中最长的单词。如果多于一个，则输出第一个
// 样例输入
// I am a student of Peking University.
// 样例输出
// University