#include <iostream>
using namespace std;

class CCar; // 提前声明CCar类，以便后面CDriver类使用
class CDriver {
public:
	void ModifyCar(CCar *pCar); // 改装汽车
};

class CCar {
private:
	int price;
	friend int MostExpensiveCar(CCar cars[], int total);
	friend void CDriver::ModifyCar(CCar *pCar);
};

void CDriver::ModifyCar(CCar *pCar) {
	pCar->price += 1000; // 汽车改装后价值增加
}

int MostExpensiveCar(CCar cars[], int total) {
	int tmpMax = -1;
	for (int i = 0; i < total; ++i)
		if (cars[i].price > tmpMax)
			tmpMax = cars[i].price;
	return tmpMax;
}

int main() {
	return 0;
}

// 友元