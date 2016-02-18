#include "order.h"

Order::Order(void) {
	this->x = 0;
	this->y = 0;
	this->order_ID = 0;
	this->type = ORDER;
	this->products = new vector<int>();
}

Order::Order(Order *order) {
	this->x = order->x;
	this->y = order->y;
	this->order_ID = order->order_ID;
	this->type = ORDER;
	this->products = new vector<int>(order->products->size());
	for(int i = 0 ; i < order->products->size() ; i++) {
		this->products->at(i) = order->products->at(i);
	}
}

Order::Order(int x, int y, int order_ID, int nb_warehouse) {
	this->x = x;
	this->y = y;
	this->order_ID = order_ID;
	this->type = ORDER;
	this->products = new vector<int>();
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
