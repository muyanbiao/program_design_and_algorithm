#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

// 对于大整数的加减乘除，本质是模拟手动加减乘除的运算过程
class BigInt {
private:
    string values; // 用字符串保存数字
    bool isNegative; // 是否为负数，true - 负数，false - 正数，默认为false，即正数，只有为负数时，才需要给它赋值为true

    inline int compare(string s1, string s2) {
        if (s1.size() < s2.size()) {
            return -1;
        } else if (s1.size() > s2.size()) {
            return 1;
        } else {
            return s1.compare(s2);
        }
    }

public:
    BigInt():values("0"), isNegative(false){};
    BigInt(string str) {
        values = str;
        isNegative = false;
    }

    friend ostream& operator<<(ostream &os, const BigInt& bigInt); // 重载流输出运算符
    friend istream&operator>>(istream &is, BigInt &bigInt); // 重载流输入运算符
    BigInt operator+(const BigInt &rBigInt); // 重载+号运算符
    BigInt operator-(const BigInt &rBigInt); // 重载-号运算符
    BigInt operator*(const BigInt &rBigInt); // 重载*号运算符
    BigInt operator/(const BigInt &rBigInt); // 重载/号运算符
};

// 重载流输出运算符
ostream& operator<<(ostream &os, const BigInt &bigInt) {
    if (bigInt.isNegative) { // 如果是负数，要在字符串前面加上负号
        os << '-';
    }
    os << bigInt.values;
    return os;
}

// 重载流输入运算符
istream& operator>>(istream &is, BigInt &bigInt) {
    string str;
    is >> str;
    bigInt.values = str;
    return is;
}

// 重载+号运算符
BigInt BigInt::operator+(const BigInt &rBigInt) {

    BigInt result;
    string str1(values), str2(rBigInt.values);

    // 先处理特殊情况，其中一个数为0的情况
    if (str1 == "0") {
        result.values = str2;
        return result;
    }

    if (str2 == "0") {
        result.values = str1;
        return result;
    }

    // 把短字符串用'0'补齐到和长字符串同样的长度
    int size1 = values.size();
    int size2 = rBigInt.values.size();

    if (size1 < size2) {
        for (int i = 0; i < size2 - size1; ++i) {
            str1 = "0" + str1;
        }
    } else if (size1 > size2) {
        for (int i = 0; i < size1 - size2; ++i) {
            str2 = "0" + str2;
        }
    }

    int currentBit = 0, nextBit = 0; // 分别代表当前位、下一位(进位)，进位默认为0
    string resultStr; // 存放运算结果的字符串
    int size = str1.size(); // 字符串的长度，用str1、str2的长度都可以，因为前面已经把它们的长度补齐了

    // 翻转两个字符串，模拟从低位开始运算
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    for (int j = 0; j < size; ++j) {
        int sumOfCurrentBit = (str1[j]-'0') + (str2[j] - '0') + nextBit;
        currentBit = (sumOfCurrentBit) % 10;
        nextBit = sumOfCurrentBit / 10;
        resultStr = resultStr + char(currentBit+'0');
    }

    if (nextBit == 1) {
        resultStr = resultStr + "1";
    }

    reverse(resultStr.begin(), resultStr.end());

    result.values = resultStr;

    return result;
}

// 重载-号运算符
BigInt BigInt::operator-(const BigInt &rBigInt) {
    // 同样，先处理特殊情况，n1或者n2等于0
    BigInt result;
    string str1(values), str2(rBigInt.values);

    if (str1 == "0") {
        result.values = str2;
        result.isNegative = true;
        return result;
    }

    if (str2 == "0") {
        result.values = str1;
        result.isNegative = false;
        return result;
    }

    // 使用内联函数比较两个字符串的大小，从而决定大数在前、小数在后和正负号
    int compareResult = compare(str1, str2);

    if (compareResult < 0) {
        // 当str1 < str2时，交换两个字符串，并把符号位置为-
        string tmpStr = str1;
        str1 = str2;
        str2 = tmpStr;
        result.isNegative = true;
    } else if (compareResult > 0){
        result.isNegative = false;
    } else {
        result.values = "0";
        return result;
    }

    // 如果num2比较短，补齐0
    int size1 = str1.size();
    int size2 = str2.size();
    if (size1 > size2) {
        for (int i = 0; i < size1 - size2; ++i) {
            str2 = "0" + str2;
        }
    }

    // 翻转num1、num2，模拟从低位开始运算
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    // 用num1 - num2，把减出来的结果存到result.values中就可以了
    int size = str1.size();
    int currentBit, nextBit = 0; // 分别表示当前位，向高位借的一位，
    string resultString; // 存放结果的字符串

    // 模拟手动减法运算
    // 在当前位：
    // 如果被减数>=减数，直接减
    // 如果被减数<减数，向高位借1，当前位+10，
    // 把当前位计算得到的结果逐位存到resultString中
    for (int j = 0; j < size; ++j) {
        int currentBit1 = str1[j] - '0';
        int currentBit2 = str2[j] - '0';

        // 要把向高位借的一位算进来
        if (currentBit1 + nextBit >= currentBit2) {
            currentBit = currentBit1 + nextBit - currentBit2;
            nextBit = 0;
        } else {
            currentBit = currentBit1 + nextBit + 10 - currentBit2;
            nextBit = -1;
        }

        resultString = resultString + char(currentBit + '0');
    }

    reverse(resultString.begin(), resultString.end());
    resultString.erase(0, resultString.find_first_not_of('0')); // 去掉前导0
    result.values = resultString;

    return result;
}

// 重载*号运算符
BigInt BigInt::operator*(const BigInt &rBigInt) {
    //同样的思路，模拟手动计算乘法的过程

    BigInt result;
    string str1(values), str2(rBigInt.values);

    // 先处理特殊情况，被乘数、乘数中任何一个为0，结果都为0
    if (str1 == "0" || str2 == "0") {
        result.values = "0";
        return result;
    }

    int size1 = str1.size();
    int size2 = str2.size();

    // 把比较长的数放在前面
    if (size1 < size2) {
        string tmpStr = str1;
        str1 = str2;
        str2 = tmpStr;

        int tmpSize = size1;
        size1 = size2;
        size2 = tmpSize;
    }

    // 翻转字符串，模拟从低位到高位的运算
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    BigInt tmpResult;
    for (int i = 0; i < size2; ++i) {
        // 第一层循环缓存str2的每一位和str1相乘的结果
        int currentBit2 = str2[i] - '0';

        string tmpStr;
        int currentBit, nextBit = 0;
        if (currentBit2 != 0) { // 当乘数的当前位不是0的时候，才进行逐位乘法运算，否则直接+0就可以了
            // 循环相乘、进位
            for (int j = 0; j < size1; ++j) {
                // 第二层循环计算str1每一位和str2当前位相乘的结果
                int currentBit1 = str1[j] - '0';
                currentBit = currentBit2 * currentBit1 + nextBit;

                // 相乘之后的结果逆序存储
                tmpStr = tmpStr + char((currentBit % 10) + '0');
                nextBit = currentBit / 10;
            }

            // 最后一个进位如果大于0，继续进位
            if (nextBit > 0) {
                tmpStr =  tmpStr + char(nextBit + '0');
            }

            // 高位相乘之后的结果要在低位补0
            for (int k = 0; k < i; ++k) {
                tmpStr = "0" + tmpStr;
            }

            // 字符串翻转 成 正常相乘之后的结果
            reverse(tmpStr.begin(), tmpStr.end());

            // 把相乘之后的结果封装到BigInt对象中，利用已经重载的+符号进行大整数的加法运算
            tmpResult.values = tmpStr;

            // 和已经做完乘法的位累计相加
            result = result + tmpResult;
        }
    }

    return result;
}

// 重载/号运算符
BigInt BigInt::operator/(const BigInt &rBigInt) {
    // 除法的解题思路就是：试商，从最大的数开始试，直到找到合适的商

    // 先处理特殊情况
    BigInt result;
    string str1(values), str2(rBigInt.values); // str1 - 被除数，str2 - 除数

    // 被除数为0，结果为0
    if (str1 == "0") {
        result.values = "0";
        return result;
    }

    // 除数为0，非法操作
    if (str2 == "0") {
        result.values = "error";
        return result;
    }

    string quotient; // 两数相处之后得到的商
    // 对比被除数、除数的大小
    int compareResult = compare(str1, str2);
    if (compareResult < 0) { // 被除数 < 除数，结果为0
        result.values = "0";
        return result;
    } else if (compareResult == 0) { // 被除数 == 除数，结果为1
        result.values = "1";
        return result;
    } else { // 被除数 > 除数，就要进行试商运算来求结果了

        int size1 = str1.size();
        int size2 = str2.size();

        string tmpDividend; // 临时被除数，每次做试商运算的被除数

        // 如果被除数的长度大于1，则先把除数str1的size2-1之前的位放到临时被除数tmpDividend中
        if (size2 > 1) tmpDividend.append(str1, 0, size2 - 1);

        for (int i = size2 - 1; i < size1; ++i) {
            tmpDividend = tmpDividend + str1[i]; // 把str1的第size2-1位放到被除数中，此时我们取到了和str2长度一样的临时被除数

            // 从9-0，从大到小开始试商
            for (char j = '9'; j >= '0'; --j) {
                // 利用已经重载的 * 和 - 运算符进行试商运算
                BigInt tmpProduct = (BigInt)str2 * (BigInt)string(1, j); // 被除数和9-0的乘积
                BigInt tmpDifference = (BigInt)tmpDividend - tmpProduct; // 用临时被除数 - 临时乘积

                if (!tmpDifference.isNegative) { // 当遇到第一个差值为正数时，就找到了商值
                    tmpDividend = tmpDifference.values; // 把新的差值赋值给临时被除数，循环进行后续的除法运算
                    quotient = quotient + j;
                    break;
                }
            }
        }

        quotient.erase(0, quotient.find_first_not_of('0')); // 利用erase函数，输出所有的前导0，find_first_not_of函数会从头开始找到第一个不是0的字符
        result.values = quotient;
        return result;
    }
}

int main() {
    BigInt n1, n2;
    char op;
    cin >> n1;
    cin >> op;
    cin >> n2;

    switch (op) {
        case '+':
            cout << n1 + n2 << endl;
            break;
        case '-':
            cout << n1 - n2 << endl;
            break;
        case '*':
            cout << n1 * n2 << endl;
            break;
        case '/':
            cout << n1 / n2 << endl;
            break;
        default:
            break;
    }

    return 0;
}