#include "warehouse.h"

Warehouse::Warehouse(void) {}

Warehouse::Warehouse(int x, int y, int warehouse_ID) {
	this->x = x;
	this->y = y;
	this->min_drones = 0;
	this->warehouse_ID = warehouse_ID;
	this->orders = new vector<Order*>();
}

Order* Warehouse::closestFreeOrder(vector<Order*> *orders) {
	Order *closest = NULL; 
	int dist_min = 65535; 
	for(int i = 0 ; i < orders->size() ; i++) {
		if(orders->at(i)->state == FREE && this->isClosest(orders->at(i), dist_min)) {
			closest = orders->at(i);
		}
	}
	return closest;
}

int Warehouse::distance(Order *order) {
	int diffX = this->x - order->x;
	int diffY = this->y - order->y;

	return ceil(sqrt(diffX * diffX + diffY * diffY));
}

bool Warehouse::isClosest(Order *order, int dist_min) {
	return this->distance(order) < dist_min ? true : false;
}

bool Warehouse::canProvideOrder(Order *order) {
	bool canProvide = true;
	vector<int> products(*(this->products));
	for(int i = 0 ; i < order->products->size() ; i++) {
		products.at(order->products->at(i))--;
		if(products.at(order->products->at(i)) < 0) {
			canProvide = false;
		}
	}

	order->buffer->at(this->warehouse_ID) = canProvide;
	return canProvide;
}

void Warehouse::provideOrder(Order *order) {
	for(int i = 0 ; i < order->products->size() ; i++) {
		this->products->at(order->products->at(i))--;
	}
}

void Warehouse::debug(void) {
	cout << this->warehouse_ID << " " << this->x << " " << this->y << endl;
/*	cout << this->products->at(0);
	for(int i = 1 ; i < this->products->size() ; i++) {
		cout << " " << this->products->at(i);
	}	*/

	cout << this->orders->size() << endl;
	for(int i = 0 ; i < this->orders->size() ; i++) {
		this->orders->at(i)->debug();
	}

	cout << endl;
}

void Warehouse::computeMinDrones(int max_payload, vector<int> *weights) {
	int cumulWeight = 0;
	for(int i = 0 ; i < this->orders->size() ; i++) {
		cumulWeight += this->orders->at(i)->getTotalWeight(weights);
		if(cumulWeight > max_payload) {
			cumulWeight -= max_payload;
			this->min_drones++;
		}
	}
}

Warehouse::~Warehouse(void) {
	delete this->products;
	delete this->orders;
}
