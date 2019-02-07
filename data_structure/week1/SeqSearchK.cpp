template <class Type>
class Item
{
private:
	Type key;					// 关键码域
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
	return i;						// 返回元素位置
}
