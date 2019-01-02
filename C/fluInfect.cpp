#include <iostream>
using namespace std;

// FIXME: 这是错误的地方，不应该这样，二是判断当room == '.',直接return !，否则return原字符串
// 感染一个房间
// char fluOneRoom(char room) {
//     if (room == '#')
//     {
//         return '#';
//     } else {
//         return '!'; // 用！的目的是，不能用刚刚感染的状态，再去感染周围的人，要到第二天才能去感染周围的人
//     }
// }
char fluOneRoom(char room) {
    if (room == '.')
    {
        return '!'; // 用！的目的是，不能用刚刚感染的状态，再去感染周围的人，要到第二天才能去感染周围的人
    } else {
        return room; 
    }
}

// 模拟流感一天的感染情况
void simulateFluInfectOf1Day(char roomArr[1000][1000], int rowNum) {
    for (int i = 0; i < rowNum; ++i)
    {
        for (int j = 0; j < rowNum; ++j)
        {
            char tmpChar = roomArr[i][j];
            if (tmpChar == '@')
            {
                if (i - 1 >= 0)
                {
                    roomArr[i-1][j] = fluOneRoom(roomArr[i-1][j]);
                }

                if (i + 1 < rowNum)
                {
                    roomArr[i+1][j] = fluOneRoom(roomArr[i+1][j]);
                }

                if (j - 1 >= 0)
                {
                    roomArr[i][j-1] = fluOneRoom(roomArr[i][j-1]);
                }

                if (j + 1 < rowNum)
                {
                    roomArr[i][j+1] = fluOneRoom(roomArr[i][j+1]);
                }
            }
        }
    }
}

void syncFluStatus(char roomArr[1000][1000], int rowNum) {
    for (int i = 0; i < rowNum; ++i)
    {
        for (int j = 0; j < rowNum; ++j)
        {
            char tmpChar = roomArr[i][j];
            if (tmpChar == '!')
            {
                roomArr[i][j] = '@';
            }
        }
    }
}

int getTotalFlu(char roomArr[1000][1000], int rowNum) {
    int sumFlu = 0;
    for (int i = 0; i < rowNum; ++i)
    {
        for (int j = 0; j < rowNum; ++j)
        {
            if (roomArr[i][j] == '@')
            {
                sumFlu++;
            }
        }
    }
    return sumFlu;
}

void outputRoom(char rommArr[1000][1000], int rowNum) {
    for (int i = 0; i < rowNum; ++i)
    {
        for (int j = 0; j < rowNum; ++j)
        {
            cout << rommArr[i][j];
        }
        cout << endl;
    }
}

int main() {
    // 输入数据，'.' - 健康；'#' - 空房间；'@' - 已经感染
    // 当前得病的会传染上、下、左、右四个人
    // 构造一个n+2 * n+2的二维数组，这样就不用对边界处的房间进行特殊处理了
    // 最后只要数出来边框内的病人数量就可以了

    int n, m, sumFluOf1Day = 0, sumFluOfMDay = 0;
    cin >> n;

    char roomArr[1000][1000];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> roomArr[i][j];
        }
    }

    cin >> m;

//    outputRoom(roomArr, n);

    // 模拟流感感染过程
    for (int i = 1; i < m; ++i)
    {
        simulateFluInfectOf1Day(roomArr, n);// 先感染周围的人，并特殊标记出来刚刚被感染的人
        syncFluStatus(roomArr, n);// 同步感染状态，用于下次继续进行感染

//        cout << endl;
//        outputRoom(roomArr, n);
    }

    sumFluOfMDay = getTotalFlu(roomArr, n);

    cout << sumFluOfMDay << endl;

    // outputRoom(roomArr, n);

    return 0;
}


// 编程题＃6：流感传染
// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 有一批易感人群住在网格状的宿舍区内，宿舍区为n*n的矩阵，每个格点为一个房间，房间里可能住人，也可能空着。在第一天，有些房间里的人得了流感，以后每天，得流感的人会使其邻居传染上流感，（已经得病的不变），空房间不会传染。请输出第m天得流感的人数。

// 输入
// 第一行一个数字n，n不超过100，表示有n*n的宿舍房间。

// 接下来的n行，每行n个字符，’.’表示第一天该房间住着健康的人，’#’表示该房间空着，’@’表示第一天该房间住着得流感的人。

// 接下来的一行是一个整数m，m不超过100.

// 输出
// 输出第m天，得流感的人数

// 样例输入

// 5
// ....#
// .#.@.
// .#@..
// #....
// .....
// 4

// 样例输出
// 16