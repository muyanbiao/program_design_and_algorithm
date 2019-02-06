# 第1章 - 概论
* 问题求解
* 数据结构及抽象数据类型
* 算法的特性及分类
* 算法的效率度量
* 数据结构的选择和评价

---
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

---
---

 2. **什么是数据结构？**
	* 结构：实体+关系
	* 数据结构：
		* **按照逻辑关系**组织起来的一批数据
		* 按一定的**存储方法**把它存储在计算机中
		* 在这些数据上定义了一个**运算**集合
		![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/da1.png)
		1. 数据结构的**逻辑组织**
			* 线性结构
				* 线性表（表、栈、队列、串等）
				![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/da2.png)
			* 非线性结构
				* 树（二叉树、Huffman树、二叉检索树等）
				![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/da3.png)
				* 图（有向图、无向图等）				
				![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/da4.png)
			* 图 ⊇ 树 ⊇ 二叉树 ⊇ 线性表
		2. 数据的**存储结构**
			* ++逻辑结构到物理空间的**映射**++  
		   **计算机主存储器**
			* **非负整数**地址编码，**相邻单元**的集合
				* 基本单位是字节
				* 访问不同地址所需的时间基本相同（即随机访问）
				![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/da5.png)
			* 对逻辑结构（K, r）, 其中r∈R
				* 对节点集K建立一个从K到存储器M的单元的映射：K —> M，对于每一个节点 j∈K 都对应一个**唯一**的**连续存储**区域 c∈M
				![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/da6.png)
			* 关系元组（j1,j2）∈ r（其中j1,j2 ∈ K 是结点）
				* 顺序：存储单元的顺序地址
				![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/da7.png)
				* 链接：指针的地址指向关系
				![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/da8.png)
			* 四类：**顺序、链接、索引、散列**
		3. **抽象数据类型**
			* 简称**ADT**（Abstract Data Type）
				- 定义了一组运算的数学模型
				- 与物理存储结构无关
				- 使软件系统建立在数据之上（面向对象）
				![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/da1.png)
			* **模块化**的思想的发展
				- 隐藏运算实现的细节和内存数据结构
				- 软件复用
			- **ADT不关心存储细节**
				- 例，C++版本括号匹配算法
                    ```
                    // C++版本括号匹配算法
                    void BracketMatch(char *str) {
                    	Stack<char> S; int i; char ch;
                    	// 栈可以使顺序或链式的，都一样引用
                    	for (i = 0; str[i] != '\0'; ++i)
                    	{
                    		switch(str[i]) {
                    			case '(':case '[':case '{':
                    				S.Push(str[i]); 
                    				break;
                    			case ')':case ']':case '}':
                    				if (S.IsEmpty()) {
                    					cout << "右括号多余!";
                    					return;
                    				} else {
                    					ch = S.GetTop();
                    					if (Match(ch, str[i]))
                    						ch = S.Pop();
                    					else {
                    						cout << "括号不匹配！"；
                    						return;
                    					}
                    				}/*else*/
                    		}/*switch*/
                    	}/*for*/
                    	if (S.IsEmpty())
                    		cout << "括号匹配！";
                    	else cout << "左括号多余";
                    }
                    ```
				* C 的顺序栈括号匹配算法 (与链式略不同)
                    ```
                    void BracketMatch(char *str) {
                    	SeqStack S; int i; char ch;
                    	InitStack(&S);
                    	for (i = 0; str[i] != '\0'; i++) {
                    		swich(str[i]) {
                    			case '(':case '[':case '{':
                    				Push(&S, str[i]); break;
                    			case ')':case ']':case '}':
                    				if (IsEmpty(&S)) {
                    					printf("\n右括号多余！");
                    					return;
                    				} else {
                    					GetTop(&S, &ch);
                    					if (Match(ch, str[i]))
                    						Pop(&S, &ch);
                    					else {
                    						printf("\n括号不匹配！");
                    						return;
                    					}
                    				}/*else*/
                    		}/*switch*/
                    	}/*for*/
                    	if (IsEmpty(&S))
                    		printf("\n括号匹配！");
                    	else printf("\n左括号多余");
                    }
                    ```
				* C 的链式栈括号匹配算法 (与顺序栈不同)
                    ```
                    void BracketMatch(char *str) {
                    	LinkStack S; int i; char ch;
                    	InitStack(/*&*/S);
                    	for (i = 0; str[i] != '\0'; i++) {
                    		swich(str[i]) {
                    			case '(':case '[':case '{':
                    				Push(/*&*/S, str[i]); break;
                    			case ')':case ']':case '}':
                    				if (IsEmpty(/*&*/S)) {
                    					printf("\n右括号多余！");
                    					return;
                    				} else {
                    					GetTop(/*&*/S, &ch);
                    					if (Match(ch, str[i]))
                    						Pop(/*&*/S, &ch);
                    					else {
                    						printf("\n括号不匹配！");
                    						return;
                    					}
                    				}/*else*/
                    		}/*switch*/
                    	}/*for*/
                    	if (IsEmpty(/*&*/S))
                    		printf("\n括号匹配！");
                    	else printf("\n左括号多余");
                    }
                    ```
			* 抽象数据结构二元组
				* **<数据对象D，数据操作P>**
			* 先定义逻辑结构，再定义运算
				* **逻辑结构**：数据对象及其关系
				* **运算**：数据操作
			* 例：栈的抽象数据类型ADT
				* 逻辑结构：线性表
				* 操作特点：**限制访问端口**
					- 只允许在一端进行插入删除操作
					- 入栈（push）、出栈（pop）、取栈顶（top）、判栈空（isEmpty）
                        ```
                        template <class T>				// 栈的元素类型为T
                        class Stack {
                        pulic:							// 栈的运算集
                        	void clear();				// 变为空栈
                        	bool push(const T item); 	// item 入栈，成功返回真，否则假
                        	bool pop(T &item);			// 弹栈顶，成功返回真，否则返回假
                        	bool top(T &item);			// 读栈顶但不弹出，成功真，否则假
                        	bool isEmpty();				// 若栈已空，返回真
                        	bool isFull();				// 若栈已满，返回真
                        };				
                        ```

**思考：关于抽象数据类型ADT**
* 怎么体现逻辑结构？
* 抽象数据类型等价于类定义？
* 不用模板来定义可以描述ADT吗？
