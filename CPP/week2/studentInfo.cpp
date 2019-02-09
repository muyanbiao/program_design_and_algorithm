#include <iostream>
#include <string.h>
using namespace std;

class Student {

private:
	char sName[100];
	char sId[100];
	unsigned int sAge;
	int sScore[4];

public:

	void setName(char *name) {
		strcpy(sName, name);
	}

	void getName(char *name) {
		strcpy(name, sName);
	}

	void setId(char *id) {
		strcpy(sId, id);
	}

	void getId(char *id) {
	    strcpy(id, sId);
	}

	void setAge(unsigned int age) {
		sAge = age;
	}

	void getAge(unsigned int &age) {
		age = sAge;
	}

	void setScore(int score[]) {
		for (int i = 0; i < 4; ++i)
		{
			sScore[i] = score[i];
		}
	}

	void average(int &average) {
		average = (sScore[0] + sScore[1] + sScore[2] +sScore[3]) / 4;
	}

};

int main() {

	char name[30];
	char id[10];
	unsigned int age;
	int score[4];
	int average;

	char comma;

	cin.getline(name, 30, ',');

	cin >> age >> comma;

	cin.getline(id, 10, ',');

	for (int i = 0; i < 4; ++i)
	{
	    if (i == 3) {
            cin >> score[i];
	    } else {
            cin >> score[i] >> comma;
	    }

	}

	Student studentA;
	studentA.setName(name);
	studentA.setAge(age);
	studentA.setId(id);
	studentA.setScore(score);

	memset(name, '\0', sizeof(name));
	memset(id, '\0', sizeof(id));
	age = 0;
	average = 0;

    studentA.getName(name);
    studentA.getId(id);
    studentA.getAge(age);
    studentA.average(average);

	cout << name << comma
	<< age << comma
	<< id << comma
	<< average << endl;

	return 0;
}

// 简单的学生信息处理程序实现
// 来源: POJ (Coursera声明：在POJ上完成的习题将不会计入Coursera的最后成绩。)

// 注意： 总时间限制: 1000ms 内存限制: 65536kB

// 描述
// 在一个学生信息处理程序中，要求实现一个代表学生的类，并且所有成员变量都应该是私有的。

// （注：评测系统无法自动判断变量是否私有。我们会在结束之后统一对作业进行检查，请同学们严格按照题目要求完成，否则可能会影响作业成绩。）

// 输入
// 姓名，年龄，学号，第一学年平均成绩，第二学年平均成绩，第三学年平均成绩，第四学年平均成绩。

// 其中姓名、学号为字符串，不含空格和逗号；年龄为正整数；成绩为非负整数。

// 各部分内容之间均用单个英文逗号","隔开，无多余空格。

// 输出
// 一行，按顺序输出：姓名，年龄，学号，四年平均成绩（向下取整）。

// 各部分内容之间均用单个英文逗号","隔开，无多余空格。

// 样例输入

// Tom,18,7817,80,80,90,70

// 样例输出

// Tom,18,7817,80
