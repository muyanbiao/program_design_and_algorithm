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

    enum WarriorType {
//        char *nameArr[5] = {"dragon", "ninja", "iceman", "lion", "wolf"};
        WarriorType_1_dragon = 1,
        WarriorType_2_ninja = 2,
        WarriorType_3_iceman = 3,
        WarriorType_4_lion = 4,
        WarriorType_5_wolf = 5,
    };

    enum WeaponType {
        WeaponType_0_sword,
        WeaponType_1_bomb,
        WeaponType_2_arrow
    };

    WarriorType myWarriorType;

    Warrior() {
        Id = 0;
        Life = 0;
        Strength = 0;
        Count = 0;
    }

    Warrior(Warrior &warrior);

//    ~Warrior(){}

    void setWarriorType(int warriorType) {
        this->myWarriorType = (WarriorType)warriorType;
    }

    WarriorType getWarriorType() {
        return this->myWarriorType;
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

    string getWeaponString(WeaponType weaponType) {
        string weaponString;
        switch (weaponType){
            case WeaponType_0_sword:
                weaponString = "sword";
                break;
            case WeaponType_1_bomb:
                weaponString = "bomb";
                break;
            case WeaponType_2_arrow:
                weaponString = "arrow";
                break;
            default:
                break;
        }
        return weaponString;
    }

    void printWarriorInfo(){ }
};

// 复制构造函数
Warrior::Warrior(Warrior &warrior) {
    Id = warrior.getId();
    Life = warrior.getLife();
    Strength = warrior.getStrength();
    Count = warrior.getCount();
    myWarriorType = warrior.myWarriorType;

    char name[10];
    warrior.getName(name);
    setName(name);
}

class Dragon : public Warrior {
private:
    WeaponType weaponType;
    float morale;

public:
    Dragon(Warrior warrior):Warrior(warrior){}

    void setWeaponType(int weaponType) {
        this->weaponType = (WeaponType)weaponType;
    }

    void setMorale(float morale) {
        this->morale = morale;
    }

    void printWarriorInfo() {
        string weaponString = getWeaponString(weaponType);
        cout << "It has a " << weaponString << ",and it's morale is " << setprecision(2) << fixed << morale << endl;
    }
};

class Ninjia : public Warrior {
private:
    WeaponType weaponTypeArr[2];
public:
    Ninjia(Warrior warriar):Warrior(warriar){}

    void setWeaponTypeArr(WeaponType weaponTypeArr[2]) {
        for (int i = 0; i < 2; ++i) {
            this->weaponTypeArr[i] = weaponTypeArr[i];
        }
    }

    void getWeaponTypeArr(WeaponType weaponTypeArr[2]) {
        for (int i = 0; i < 2; ++i) {
            weaponTypeArr[i] = this->weaponTypeArr[i];
        }
    }

    void printWarriorInfo() {
        string weaponString1 = getWeaponString(weaponTypeArr[0]);
        string weaponString2 = getWeaponString(weaponTypeArr[1]);
        cout << "It has a " << weaponString1 << " and a " << weaponString2 << endl;
    }
};

class Iceman : public Warrior {
private:
    WeaponType weaponType;

public:
    Iceman(Warrior warrior):Warrior(warrior){}

    void setWeaponType(int weaponType) {
        this->weaponType = (WeaponType)weaponType;
    }

    void printWarriorInfo() {
        string weaponString = getWeaponString(weaponType);
        cout << "It has a " << weaponString << endl;
    }
};

class Lion : public Warrior {
private:
    int loyalty;

public:
    Lion(Warrior warrior):Warrior(warrior){}

    void setLoyalty(int loyalty) {
        this->loyalty = loyalty;
    }

    void printWarriorInfo() {
        cout << "It's loyalty is " << loyalty << endl;
    }
};

void printWarriorInfo(Warrior warrior, int leftLife) {
    Warrior::WarriorType warriorType = warrior.getWarriorType();
    if (warriorType == Warrior::WarriorType_1_dragon) {
        Dragon warriorDragon(warrior);
        warriorDragon.setWeaponType(warrior.getId() % 3);
        float morale = (float)leftLife / (float)warriorDragon.getLife();
        warriorDragon.setMorale(morale);
        warriorDragon.printWarriorInfo(); // 打印武器和属性信息
    } else if (warriorType == Warrior::WarriorType_2_ninja) {
        Ninjia warriorNinjia(warrior);
        Warrior::WeaponType weaponTypeArr[2] = {(Warrior::WeaponType)(warrior.getId() % 3), (Warrior::WeaponType)((warrior.getId()+1) % 3)};
        warriorNinjia.setWeaponTypeArr(weaponTypeArr);
        warriorNinjia.printWarriorInfo(); // 打印武器信息
    } else if (warriorType == Warrior::WarriorType_3_iceman) {
        Iceman warriorIceman(warrior);
        warriorIceman.setWeaponType(warrior.getId() % 3);
        warriorIceman.printWarriorInfo(); // 打印武器和属性信息
    } else if (warriorType == Warrior::WarriorType_4_lion) {
        Lion warriorLion(warrior);
        warriorLion.setLoyalty(leftLife);
        warriorLion.printWarriorInfo(); // 打印武器和属性信息
    }
}

int main() {
    // 循环执行case
    // 在每个case里面，循环创建士兵，每制造一个，减少对应的生命值，直到剩余的生命值无法再生产任何一种士兵位置

    int countN, totalM;

    // 红蓝军的生命值对应index
    int redIndex[5] = {4, 3, 0, 1, 2};
    int blueIndex[5]  = {1, 2, 3, 0, 4};

    Warrior::WarriorType warriorTypeArr[5] = {
            Warrior::WarriorType_1_dragon,
            Warrior::WarriorType_2_ninja,
            Warrior::WarriorType_3_iceman,
            Warrior::WarriorType_4_lion,
            Warrior::WarriorType_5_wolf,
    };

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
            Warrior warriorRed = warriorsRed[redIndex[j]];
            Warrior warriorBlue = warriorsBlue[blueIndex[j]];

            warriorRed.setLife(lifeArr[j]);
            warriorBlue.setLife(lifeArr[j]);

            warriorRed.setName(nameArr[j]);
            warriorBlue.setName(nameArr[j]);

            // 设置战士种类
            warriorRed.setWarriorType(warriorTypeArr[j]);
            warriorBlue.setWarriorType(warriorTypeArr[j]);

            warriorsRed[redIndex[j]] = warriorRed;
            warriorsBlue[blueIndex[j]] = warriorBlue;
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

//        cout << "minLife:" << minLife << endl;

        int skipBLuePrintCount = 0; // 这是用来计数的，当skipBLuePrintCount=1时，表示第一次发现蓝军停止生产、红军继续生产
        // 开始生产士兵
        while (true) {

            while (true) {
                if (leftRedLife >= minLife)
                {
                    int indexRed = currentIndexRed % 5;
                    Warrior warriorRed = warriorsRed[indexRed];
                    if (warriorRed.getLife() <= leftRedLife)
                    {
                        // 先生产红军，再生产蓝军
                        leftRedLife -= warriorRed.getLife();

                        int warriorId = indexToPrintRed+1;
                        cout << setfill('0') << setw(3) << indexToPrintRed << " ";
                        warriorRed.setId(warriorId);
                        warriorRed.setStrength(warriorRed.getLife());
                        warriorRed.addCount();
                        warriorsRed[indexRed] = warriorRed;


                        char tmpName[10];
                        warriorRed.getName(tmpName);

                        cout << "red "
                             << tmpName << " "
                             << warriorRed.getId()
                             << " born with strength "
                             << warriorRed.getStrength() <<","
                             << warriorRed.getCount() << " "
                             << tmpName << " "
                             << "in red headquarter" << endl;

                        // 根据warriorType设置对应的武器类型和属性值

                        printWarriorInfo(warriorRed, leftRedLife);

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
                    int indexBlue = currentIndexBlue % 5;
                    Warrior warriorBlue = warriorsBlue[indexBlue];
                    if (warriorBlue.getLife() <= leftBlueLife)
                    {
                        leftBlueLife -= warriorBlue.getLife();
                        cout << setfill('0') << setw(3) << indexToPrintBlue << " ";
                        warriorBlue.setId(indexToPrintBlue+1);
                        warriorBlue.setStrength(warriorBlue.getLife());
                        warriorBlue.addCount();
                        warriorsBlue[indexBlue] = warriorBlue;

                        char tmpName[10];
                        warriorBlue.getName(tmpName);

                        cout << "blue "
                             << tmpName << " "
                             << warriorBlue.getId()
                             << " born with strength "
                             << warriorBlue.getStrength() <<","
                             << warriorBlue.getCount() << " "
                             << tmpName << " "
                             << "in blue headquarter" << endl;

                        printWarriorInfo(warriorBlue, leftBlueLife);

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

//            cout << "leftRedLife:" << leftRedLife << "  leftBlueLife:" << leftBlueLife << endl << endl;

            bool isBlueReachEndFirst = false; // 蓝军先停止生产士兵，并且红军还没停止生产士兵
            if (leftRedLife >= minLife && leftBlueLife < minLife) {
                isBlueReachEndFirst = true;
                ++skipBLuePrintCount;
            }

            if (leftRedLife < minLife && !isAlreadyCoutRedEnd) {
                // 如果还没有输出过结束语句，则输出，否则跳过，不输出
                cout << setfill('0') << setw(3) << indexToPrintRed << " ";
                cout << "red headquarter stops making warriors" << endl;
                isAlreadyCoutRedEnd = true;
            }

            if (leftBlueLife < minLife && !isAlreadyCoutBlueEnd) {

                // 如果还没有输出过结束语句，则输出，否则跳过，不输出
                if (!isBlueReachEndFirst || skipBLuePrintCount > 1) {
                    cout << setfill('0') << setw(3) << indexToPrintBlue << " ";
                    cout << "blue headquarter stops making warriors" << endl;
                    isAlreadyCoutBlueEnd = true;
                }
            }

            if (leftRedLife >= minLife && leftBlueLife < minLife) {// 确保下次会输出蓝军停止生产的消息
                ++skipBLuePrintCount;
            }

            // 循环中止条件 - 无法再进行红和蓝士兵的生产，因为剩余的生命值已经不够了
            if (leftRedLife < minLife && leftBlueLife < minLife) break;
        }

    }

    return 0;
}

/*
编程题＃2： 魔兽世界之二：装备
        来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

注意： 总时间限制: 1000ms 内存限制: 65536kB

描述
        魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。

红司令部，City 1，City 2，……，City n，蓝司令部

        两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值这两种属性。

有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。

双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。

不同的武士有不同的特点。

dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。

ninjia可以拥有两件武器。编号为n的ninjia降生时即获得编号为 n%3 和 (n+1)%3的武器。

iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。

lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。

wolf没特点。

请注意，在以后的题目里，武士的士气，生命值，忠诚度在其生存期间都可能发生变化，都有作用，武士手中的武器随着使用攻击力也会发生变化。

武士在刚降生的时候有一个生命值。

在每个整点，双方的司令部中各有一个武士降生。

红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序循环制造武士。

蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序循环制造武士。

制造武士需要生命元。

制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。

给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。

一共有两种事件，其对应的输出样例如下：

1) 武士降生

        输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter

表示在 4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5,降生后蓝魔司令部里共有2个lion武士。(为简单起见，不考虑单词的复数形式)注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。

如果造出的是dragon，那么还要输出一行，例：

It has a arrow,and it's morale is 23.34

表示该dragon降生时得到了arrow,其士气是23.34（为简单起见，本题中arrow前面的冠词用a,不用an，士气精确到小数点后面2位，四舍五入）

如果造出的是ninjia，那么还要输出一行，例：

It has a bomb and a arrow

表示该ninjia降生时得到了bomb和arrow。

如果造出的是iceman，那么还要输出一行，例：

It has a sword

表示该iceman降生时得到了sword。

如果造出的是lion，那么还要输出一行，例：

It's loyalty is 24

表示该lion降生时的忠诚度是24。

2) 司令部停止制造武士

        输出样例： 010 red headquarter stops making warriors

        表示在 10点整，红方司令部停止制造武士

        输出事件时：

首先按时间顺序输出；

同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
        第一行是一个整数,代表测试数据组数。

每组测试数据共两行。

第一行，一个整数M。其含义为： 每个司令部一开始都有M个生命元( 1 <= M <= 10000)

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000

        输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。

对每组测试数据，首先输出“Case:n" n是测试数据的编号，从1开始

接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。

样例输入
1
20
3 4 5 6 7

样例输出
 Case:1
000 red iceman 1 born with strength 5,1 iceman in red headquarter
It has a bomb
000 blue lion 1 born with strength 6,1 lion in blue headquarter
It's loyalty is 14
001 red lion 2 born with strength 6,1 lion in red headquarter
It's loyalty is 9
001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
It has a arrow,and it's morale is 3.67
002 red wolf 3 born with strength 7,1 wolf in red headquarter
002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
It has a sword and a bomb
003 red headquarter stops making warriors
003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
It has a bomb
004 blue headquarter stops making warriors

*/