#include "order.h"

Order::Order(void) {}

Order::Order(int x, int y, int order_ID, int nb_warehouse) {
	this->x = x;
	this->y = y;
	this->order_ID = order_ID;
	this->state = FREE;
	this->buffer = new vector<bool>(nb_warehouse);
	for(int i = 0 ; i < this->buffer->size() ; i++) {
		this->buffer->at(i) = true;
	}
}

bool Order::isRejected(void) {
	bool rejected = true;

	for(int i = 0 ; i < this->buffer->size() ; i++) {
		if(this->buffer->at(i) == true) {
			rejected = false;
		}
	}

	return rejected;
}

int Order::getTotalWeight(vector<int> *weights) {
	int totalWeight = 0;
	for(int i = 0 ; i < this->products->size() ; i++) {
		totalWeight += weights->at(this->products->at(i));
	}
	return totalWeight;
}

void Order::debug(void) {
	cout << this->x << " " << this->y << endl;
	cout << this->products->size() << endl;
	cout << this->products->at(0);
	for(int i = 1 ; i < this->products->size() ; i++) {
		cout << " " << this->products->at(i);
	}
	cout << endl;
	cout << (this->state == FREE ? "FREE" : "TAKEN") << endl;
}

Order::~Order(void) {
	delete this->products;
}
