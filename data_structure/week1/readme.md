# 第1章 - 概论
* 问题求解
* 数据结构及抽象数据类型
* 算法的特性及分类
* 算法的效率度量
* 数据结构的选择和评价

---
1. **问题求解**
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
		![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/man_wolf_sheep_greens1.png)  
	- **数据抽象**：图模型
		- 不合理状态：狼羊、人菜、羊菜、人狼、狼羊菜、人
		- 定点表示”原岸状态“ —— 10种（包括”空“）
		- 边：一次合理的渡河操作实现的状态转变  
		![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/man_wolf_sheep_greens2.png)  
	- **数据结构**：
		- 相邻矩阵  
		![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/man_wolf_sheep_greens3.png)
	- **算法抽象**
		- 最短路径  
## 思考：问题求解过程
* 农夫过河问题 —— 最短路径模型
	* 问题抽象？
	* 数据抽象？
	* 算法抽象?
	* 不妨编程序模拟实现

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

---
3. **算法**
* **问题 —— 算法 —— 程序**
	* **问题（problem）** 一个函数
		* 从输入到输出的一种**映射**
	* **算法（algorithm）** 一种方法
		* 对特定问题**求解过程的描述**，是指令的有限序列
	* **程序（program）**
		* 是算法在计算机程序设计语言中的**实现**
* **算法的特性**
	* 通用性
		- 对参数化输入进行问题求解
		- 保证计算结果的正确性
	* 有效性
		- 算法是有限条指令组成的指令序列
		- 即由一系列具体步骤组成
	* 确定性
		- 算法描述中的下一步应执行的步骤必须明确
	* 有穷性
		- 算法的执行必须在有限步内结束
		- 换句话说，算法不能含有死循环
* **皇后问题（四皇后）**  
	![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/alg1.png)
	- 解<x1, x2, x3, x4>（放置列号）
	- 搜索空间：4叉树（排列树）  
	![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/alg2.png)
* **基本算法分类**
	* 穷举法
		- 顺序找K值
	* 回溯、搜索
		- 八皇后、树和遍历
	* 递归分治
		- 二分找K值、快速排序、归并排序
	* 贪心法
		- Huffman编码树、最短路Dijkstra算法、最小生成树Prim算法
	* 动态规划
		- 最短路Floyd算法
* **顺序找K值**  
![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/alg3.png)

    ```
    template <class Type>
    class Item
    {
    private:
    	Type key;							// 关键码域
    										// 其他域
    public:
    	Item(Type value):key(value) {}
    	Type getKey() {return key;}		// 取关键码
    	void setKey(Type k) { key = k;}	// 置关键码
    };
    
    vector<Item<Type> *> dataList;
    template <class Type> int SeqSearch(vector<Item<Type>*> &dataList, int length, Type k) {
    	int i = length;
    	dataList[0]->setKey(k);			// 将第0个元素设置为待检索值，设监视哨
    	while(dataList[i]->getKey != k) i--;
    	return i;							// 返回元素位置
    }
    ```
* **二分法找k值**
对于已排序顺序线性表
	* 数组中间位置的元素值Kmid
		- 如果Kmid = k，那么检所工作就完成了
		- 当Kmid > k时，检索继续在前半部分进行
		- 相反地，若Kmid < k，就可以忽略mid以前的那部分，检索继续在后半部分进行
	* 快速
		- Kmid = k 结束
		- Kmid != k 起码缩小了一半的检索范围
            ```
            template <class Type> int BinSearch(vector<Item<Type>*> &dataList, int length, Type k) {
            	int low = 1, high = length, mid;
            	while (low <= high) {
            		mid = (low + high) / 2;
            		if (k < dataList[mid]->getKey())
            			high = mid - 1;					// 右缩检索区间
            		else 
            			low = mid + 1;					// 左缩检索区间
            		else return mid;					// 成功返回位置
            	}
            	return 0;								// 检索失败，返回0
            }
            ```
	- 二分法检索图示  
	![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/alg4.png)  
检索关键码18	low=1	high = 9		K = 18
        ```
        第一次：mid = 5; array[5] = 35 > 18
        		high = 4; (low = 1)
        第二次：mid = 2; array[2] = 17 < 18
        		low = 3; (high = 4)
        第三次：mid = 3; array[3] = 18 = 18
        		mid = 3; return 3;
        ```
* **思考：算法的时空限制**
> 设计一个算法，将数组A(0…n-1)中的元素循环右移k位，假设原数组序列为a0,a1,…,an-2,an-1;移动后的序列为an-1,an-k+1,…a0,a1,…,an-1-1。要求只用一个元素大小的附加存储，元素移动或交换次数与n线性相关。例如 ~n = 10, k = 3~  

原始数据：`0 1 2 3 4 5 6 7 8 9`  
右移后的：`7 8 9 0 1 2 3 4 5 6`  
![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/alg5.png)

---
4. 算法的效率度量
	1. 算法的渐进分析
		* **f(n) = n2 + 100n + log10n + 1000**
		* 数据规模n逐步增大时，f(n)的增长趋势
		* 当n增大到一定值后，计算公式中影响最大的就是n的幂次最高的项
			- 其他的常数项和低幂次项都可以忽略
	2. 算法渐进分析：**大O表示法**
		* 函数f，g定义域为自然数，值域为非负实数集
		* **定义**：如果存在正数c和n0，使得对任意的*n>=n0*，都有*f(n) < cg(n)*
		* 称f(n)在集合O(g(n))中，简称f(n)是O(g(n))的，或f(n) = O(g(n))
		* 大O表示法：表达函数增长率上限
			- 一个函数的增长率上限可能不止一个
		* 当上下限相同时则可用Θ表示法
		* f(n) = O(g(n))，当且仅当
			- 存在两个参数c > 0, n0 > 0，对于所有的n ≥ n0，都有f(n) ≤ cg(n)
		* iff  ∃ c, n0 > 0 s.t. ∀ n ≥ n0 : 0 ≤ f(n) ≤ cg(n)  
        ![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/algMeasure1.png)
	3. 大Ο表示法的**单位时间**
		* 简单布尔或算数运算
		* 简单I/O
			- 指函数的输入/输出
				- 例如：从数组读数据等操作
			- 不包括键盘文件等I/O
		- 函数返回
	4. 大Ο表示法的**运算法则**
		* **加法规则**：f1(n) + f2(n) = O(max(f1(n), f2(n)))
			- 顺序结构：if结构，switch结构
		* **乘法规则**：f1(n)*f2(n) = O(f1(n)*f2(n))
			- for, while, do-while语句  
		![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/algMeasure2.png)
	5. 算法渐进分析：**大Ω表示法**
		* **定义：**如果存在正数c和n0，使得对所有的n ≥ n0，都有*f(n) ≥ cg(n)*，则称f(n)在集合Ω(g(n))中，或简称f(n)是Ω(g(n))的，或f(n) = Ω(g(n))
		* 大O表示法和大Ω表示法的唯一区别在于不等式的方向而已
		* 采用大Ω表示法时，最好找出在函数增长率的所有下限中**最”紧”**（即最大）的下限
		* f(n) = Ω(g(n))
			- iff  ∃ c, n0 > 0 s.t. ∀ n ≥ n0 : 0 ≤ cg(n) ≤ f(n) 
		* 与大O表示法的唯一区别在于不等式的方向  
		![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/algMeasure3.png)
	6. 算法渐进分析：**大Θ表示法**
		* 当上下限相同时则使用大Θ表示法
		* 定义如下：
			* 如果一个函数既在集合O(g(n))中又在集合Ω(g(n))中，则称其为Θ(g(n))
		* 也即，当上下限相同时则可用大Θ表示法
		* 存在正常数c1,c2，以及正整数n0，使得对于任意n>n0，有以下两不等式同时成立：
			- c1g(n) ≤ f(n) ≤ c2g(n)
		* **f(n) = Θ(g(n))** 
			- iff  ∃ c1, c2, n0 > 0 s.t. c1g(n) ≤ f(n) ≤ c2g(n), ∀ n ≥ n0  
		![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/algMeasure4.png)
	7. **增长率函数曲线**  
	![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/algMeasure5.png)
	8. **问题空间 VS 时间开销**  
	![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/algMeasure6.png)
	9. **顺序找K值**
		* 顺序从一个规模为n的一位数组中找出一个给定的K值
		* 最佳情况
			- 数组中第一个元素就是K
			- 只要检查一个元素
		* 最差情况
			- K是数组的最后一个元素
			- 检查数组中的所有n个元素
		* 如果等概率分布
			- K值出现在n个位置上概率都是1/n
			- 则平均代价为O(n)  
			![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/algMeasure7.png)
		* 如果概率不等
			- 出现在第1个位置的概率为1/2
			- 第2个位置上的概率为1/4
			- 出现在其他位置的概率都是  
			![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/algMeasure8.png)
			- 平均代价为O(n)  
			![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/algMeasure9.png)
	10. **二分法找K值**
	**对于已排序顺序线性表**  
		* 数组中间的元素值Kmid
			- 如果Kmid = k，那么检所工作就完成了
			- 当Kmid > k时，检索继续在前半部分进行
			- 相反地，若Kmid < k，就可以忽略mid以前的那部分，检索继续在后半部分进行
		* 快速
			- Kmid = k结束
			- Kmid ≠ k起码缩小一半的检索范围
		- 二分法检索性能分析
			- 最大检索长度为  
			![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/algMeasure10.png)
			- 失败的检索长度为  
			![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/algMeasure11.png)或 ![image](https://github.com/muyanbiao/program_design_and_algorithm/blob/master/data_structure/week1/Resources/algMeasure12.png)
			- 平均检索代价为O(logn)
			- 在算法复杂性分析中
				- logn是以2为底的对数
				- 以其他数值为底，算法量级不变
	11. **时间/空间权衡**
		* **数据结构**
			- 一定的空间来存储它的每一个数据项
			- 一定的时间来执行单个基本操作
		* **代价和效益**
			- 空间和时间的限制
			- 软件工程
		* 增大空间开销可能改善算法的时间开销
		* 可以节省空间，往往需要增大运算时间
	12. **数据结构和算法的选择**
		* 仔细分析所要解决的问题
			- 特别是求解问题所涉及的数据类型和数据间逻辑关系 —— 问题抽象、数据抽象
			- 数据结构的初步设计往往先于算法设计
		* 注意数据结构的可扩展性
			- 考虑当输入数据的规模发生改变时，数据结构能否适应求解问题的演变和扩展

    * **思考：数据结构和算法的选择**
    	* 问题求解的目标
    	* 数据结构和算法的选择过程
