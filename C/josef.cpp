#include <iostream>

using namespace std;

int main() {
    // 1. 输入 n 和 m
    // 构造数组 arr[n]
    // 从数组第一个元素开始数，一直数到第m个元素，记住此时的数组下标，删除这个元素
    // 注意，在数的时候，可能会遇到还没数到m，就已经到达数组最后一个元素了，这时接着从第一个元素开始数
    // 也可以不移动数组元素，把数到的元素值置位0，在后续数到为0的元素是，就不算在内
    int n, m;

    while (true) {

        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        int arr[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = i + 1;
        }

        int tmpN = n;

        int indexToDelete = 0;

        while (true) {

            if (tmpN <= 1) break; // 剩余1个元素的时候，退出循环

            int tmpM = m;
            while (true) {
                if (tmpM == 0) break;

                // 如果判断元素为0，直接把index+1，跳过当前元素的判断
                if (arr[indexToDelete] == 0) {
                    if (indexToDelete == n - 1) { // 已经是最后一个元素了，从第0元素重新开始数
                        indexToDelete = 0;
                    } else { // 不是最后一个元素，并且不是第一次开始计算时，继续往后数
                        ++indexToDelete;
                    }

                    continue;
                }

                --tmpM; // 有效判断减一次

                // 有效向前走一步
                if (indexToDelete == n - 1) { // 已经是最后一个元素了，从第0元素重新开始数
                    indexToDelete = 0;
                } else { // 不是最后一个元素，并且不是第一次开始计算时，继续往后数
                    ++indexToDelete;
                }

            }

            // 数完m个数之后，获取到了要退出的猴子，把数组元素置位0，同时--n
            int finalIndexToDelete;
            if (indexToDelete == 0) {
                finalIndexToDelete = n - 1;
            } else {
                finalIndexToDelete = indexToDelete - 1;
            }

            arr[finalIndexToDelete] = 0;
            --tmpN;
        }

        for (int i = 0; i < n; ++i) {
//            cout << arr[i] << " ";

            if (arr[i] > 0) {
                cout << arr[i] << endl;
                break;
            }
        }

//        cout << endl;

    }

    return 0;
}

// 抄写题＃1: 约瑟夫问题

// 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 约瑟夫问题：有ｎ只猴子，按顺时针方向围成一圈选大王（编号从１到ｎ），从第１号开始报数，一直数到ｍ，数到ｍ的猴子退出圈外，剩下的猴子再接着从1开始报数。就这样，直到圈内只剩下一只猴子时，这个猴子就是猴王，编程求输入ｎ，ｍ后，输出最后猴王的编号。

// 输入
// 每行是用空格分开的两个整数，第一个是 n, 第二个是 m ( 0 < m,n <=300)。最后一行是：

// 0 0

// 输出
// 对于每行输入数据（最后一行除外)，输出数据也是一行，即最后猴王的编号

// 样例输入

// 6 2
// 12 4
// 8 3
// 0 0

// 样例输出

// 5
// 1
// 7
