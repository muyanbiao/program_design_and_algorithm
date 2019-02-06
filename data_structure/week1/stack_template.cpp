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