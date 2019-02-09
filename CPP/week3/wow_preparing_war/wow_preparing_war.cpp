#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
using namespace std;

class Warrior {
private:
    char Name[10];
    int Id;
    int Life;
    int Strength;
    int Count;

public:

    Warrior() {
        Id = 0;
        Life = 0;
        Strength = 0;
        Count = 0;
    }

    void setName(char name[]) {
        strcpy(Name, name);
    }
    void setId(int id) {
        this->Id = id;
    }
    void setLife(int life) {
        this->Life = life;
    }
    void setStrength(int strength) {
        this->Strength = strength;
    }
    void addCount() {
        ++Count;
    }

    void getName(char name[]) {
        strcpy(name, this->Name);
    }
    int getId() {
        return this->Id;
    }
    int getLife() {
        // int &rLife = Life;
        return this->Life;
    }
    int getStrength() {
        return this->Strength;
    }
    int getCount() {
        // int &rCount = Count;
        return this->Count;
    }
};

int main() {
    // 循环执行case
    // 在每个case里面，循环创建士兵，每制造一个，减少对应的生命值，直到剩余的生命值无法再生产任何一种士兵位置

    int countN, totalM;

    // 红蓝军的生命值对应index
    int redIndex[5] = {4, 3, 0, 1, 2};
    int blueIndex[5]  = {1, 2, 3, 0, 4};

    // 输入的士兵名称列表，和输入的生命值对应，再输入生命值的过程中同时赋值名称
    char *nameArr[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};

    cin >> countN;
    for (int i = 1; i <= countN; ++i) // case循环
    {
        Warrior warriorsRed[5];
        Warrior warriorsBlue[5];

        // 数据读入
        int lifeArr[5] = {0};
        int minLife = 10000;

        cin >> totalM;

        for (int j = 0; j < 5; ++j)
        {
            cin >> lifeArr[j];

            if (lifeArr[j] < minLife) // 找出最小生命值，用于判断是否还能继续生产士兵
            {
                minLife = lifeArr[j];
            }

            // 给士兵数组初始化生命值和名称
            warriorsRed[redIndex[j]].setLife(lifeArr[j]);
            warriorsBlue[blueIndex[j]].setLife(lifeArr[j]);

            warriorsRed[redIndex[j]].setName(nameArr[j]);
            warriorsBlue[blueIndex[j]].setName(nameArr[j]);
        }

        // 开始生产士兵
        // 剩余的红、蓝总生命值
        int leftRedLife = totalM;
        int leftBlueLife = totalM;

        int currentIndexRed = 0, currentIndexBlue = 0;
        int indexToPrintRed = 0, indexToPrintBlue = 0;

        // 判断是否已经输出过结束语句
        bool isAlreadyCoutRedEnd = false;
        bool isAlreadyCoutBlueEnd = false;

        cout << "Case:" << i << endl;

        // 开始生产士兵
        while (true) {

            if (leftRedLife < minLife && !isAlreadyCoutRedEnd) {
                // 如果还没有输出过结束语句，则输出，否则跳过，不输出
                cout << setfill('0') << setw(3) << indexToPrintRed << " ";
                cout << "red headquarter stops making warriors" << endl;
                isAlreadyCoutRedEnd = true;
            }

            if (leftBlueLife < minLife && !isAlreadyCoutBlueEnd) {
                // 如果还没有输出过结束语句，则输出，否则跳过，不输出
                cout << setfill('0') << setw(3) << indexToPrintBlue << " ";
                cout << "blue headquarter stops making warriors" << endl;
                isAlreadyCoutBlueEnd = true;
            }

            // 循环中止条件 - 无法再进行红和蓝士兵的生产，因为剩余的生命值已经不够了
            if (leftRedLife < minLife && leftBlueLife < minLife) break;

            while (true) {
                if (leftRedLife >= minLife)
                {
                    if (warriorsRed[currentIndexRed % 5].getLife() <= leftRedLife)
                    {
                        // 先生产红军，再生产蓝军

                        leftRedLife -= warriorsRed[currentIndexRed % 5].getLife();

                        cout << setfill('0') << setw(3) << indexToPrintRed << " ";
                        warriorsRed[currentIndexRed % 5].setId(indexToPrintRed+1);
                        warriorsRed[currentIndexRed % 5].setStrength(warriorsRed[currentIndexRed % 5].getLife());
                        warriorsRed[currentIndexRed % 5].addCount();

                        char tmpName[10];
                        warriorsRed[currentIndexRed % 5].getName(tmpName);

                        cout << "red "
                             << tmpName << " "
                             << warriorsRed[currentIndexRed % 5].getId()
                             << " born with strength "
                             << warriorsRed[currentIndexRed % 5].getStrength() <<","
                             << warriorsRed[currentIndexRed % 5].getCount() << " "
                             << tmpName << " "
                             << "in red headquarter" << endl;

                        ++indexToPrintRed;

                        ++currentIndexRed;

                        break;
                    }

                    ++currentIndexRed;

                    if (currentIndexRed > 1000) break;
                } else {
                    break;
                }
            }

            while (true) {
                if (leftBlueLife >= minLife)
                {
                    if (warriorsBlue[currentIndexBlue % 5].getLife() <= leftBlueLife)
                    {

                        leftBlueLife -= warriorsBlue[currentIndexBlue % 5].getLife();

                        cout << setfill('0') << setw(3) << indexToPrintBlue << " ";
                        warriorsBlue[currentIndexBlue % 5].setId(indexToPrintBlue+1);
                        warriorsBlue[currentIndexBlue % 5].setStrength(warriorsBlue[currentIndexBlue % 5].getLife());
                        warriorsBlue[currentIndexBlue % 5].addCount();

                        char tmpName[10];
                        warriorsBlue[currentIndexBlue % 5].getName(tmpName);

                        cout << "blue "
                             << tmpName << " "
                             << warriorsBlue[currentIndexBlue % 5].getId()
                             << " born with strength "
                             << warriorsBlue[currentIndexBlue % 5].getStrength() <<","
                             << warriorsBlue[currentIndexBlue % 5].getCount() << " "
                             << tmpName << " "
                             << "in blue headquarter" << endl;

                        ++indexToPrintBlue;

                        ++currentIndexBlue;

                        break;
                    }

                    ++currentIndexBlue;

                    if (currentIndexBlue > 1000) break;

                } else {
                    break;
                }
            }


        }

    }

    return 0;
}

// 编程题＃4：魔兽世界之一：备战
// 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。

// 红司令部，City 1，City 2，……，City n，蓝司令部

// 两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。

// 双方的武士编号都是从1开始计算。红方制造出来的第n个武士，编号就是n。同样，蓝方制造出来的第n个武士，编号也是n。

// 武士在刚降生的时候有一个生命值。

// 在每个整点，双方的司令部中各有一个武士降生。

// 红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。

// 蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。

// 制造武士需要生命元。

// 制造一个初始生命值为m的武士，司令部中的生命元就要减少m个。

// 如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。

// 给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。

// 一共有两种事件，其对应的输出样例如下：

// 1) 武士降生

// 输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter

// 表示在4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5，降生后蓝魔司令部里共有2个lion武士。（为简单起见，不考虑单词的复数形式）注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。

// 2) 司令部停止制造武士

// 输出样例： 010 red headquarter stops making warriors

// 表示在10点整，红方司令部停止制造武士

// 输出事件时：

// 首先按时间顺序输出；

// 同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

// 输入
// 第一行是一个整数，代表测试数据组数。

// 每组测试数据共两行。

// 第一行：一个整数M。其含义为， 每个司令部一开始都有M个生命元( 1 <= M <= 10000)。

// 第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000。

// 输出
// 对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。

// 对每组测试数据，首先输出"Case:n" n是测试数据的编号，从1开始 。

// 接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。

// 样例输入

// 1
// 20
// 3 4 5 6 7

// 样例输出

// Case:1
// 000 red iceman 1 born with strength 5,1 iceman in red headquarter
// 000 blue lion 1 born with strength 6,1 lion in blue headquarter
// 001 red lion 2 born with strength 6,1 lion in red headquarter
// 001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
// 002 red wolf 3 born with strength 7,1 wolf in red headquarter
// 002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
// 003 red headquarter stops making warriors
// 003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
// 004 blue headquarter stops making warriors
