#include "warehouse.h"

Warehouse::Warehouse(void) {}

Warehouse::Warehouse(int x, int y) {
	this->x = x;
	this->y = y;
}

Order* Warehouse::closestOrder(vector<Order*> *orders) {
	Order *closest = orders->at(0);
	int dist_min = this->distance(closest);
	for(int i = 0 ; i < orders->size() ; i++) {
		if(this->isClosest(orders->at(i), dist_min)) {
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

void Warehouse::debug(void) {
	cout << this->x << " " << this->y << endl;
	cout << this->products->at(0);
	for(int i = 1 ; i < this->products->size() ; i++) {
		cout << " " << this->products->at(i);
	}	
	cout << endl;
}

Warehouse::~Warehouse(void) {
	delete this->products;
}
