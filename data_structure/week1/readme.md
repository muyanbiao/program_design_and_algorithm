# 第1章 - 概论
* 问题求解
* 数据结构及抽象数据类型
* 算法的特性及分类
* 算法的效率度量
* 数据结构的选择和评价

1. 问题求解
	* 编写计算机程序的目的？
		- 解决实际的应用问题
	- **问题抽象**
		- 分析和抽象任务需求，建立问题模型
	- **数据抽象**
		- 确定恰当的数据结构表示数学模型
	- **算法抽象**
		- 在数据模型的基础上设计合适的算法
	- 数据结构+算法，进行程序设计
		- 模拟和解决实际问题  
		![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/data_structure_defination.png)
	* **问题描述**：人狼羊菜乘船过河
		- 只有人能撑船
		- 船只有两个位置（包括人）
		- 狼羊、羊菜不能在没有人时共处
	- **数据抽象**：图模型
		- 不合理状态：狼羊、人菜、羊菜、人狼、狼羊菜、人
		- 定点表示”原岸状态“ —— 10种（包括”空“）
		- 边：一次合理的渡河操作实现的状态转变
	- 数据结构：
		- 相邻矩阵
	- 算法抽象
		- 最短路径
![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/man_wolf_sheep_greens1.png)

![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/man_wolf_sheep_greens2.png)

![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/man_wolf_sheep_greens3.png)

## 思考：问题求解过程
* 农夫过河问题 —— 最短路径模型
	* 问题抽象？
	* 数据抽象？
	* 算法抽象?
	* 不妨编程序模拟实现
