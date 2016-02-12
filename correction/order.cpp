#include "order.h"

Order::Order(void) {}

Order::Order(int x, int y) {
	this->x = x;
	this->y = y;
}

void Order::debug(void) {
	cout << this->x << " " << this->y << endl;
	cout << this->products->size() << endl;
	cout << this->products->at(0);
	for(int i = 1 ; i < this->products->size() ; i++) {
		cout << " " << this->products->at(i);
	}
	cout << endl;
}

Order::~Order(void) {
	delete this->products;
}
