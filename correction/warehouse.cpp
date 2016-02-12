#include "warehouse.h"

Warehouse::Warehouse(void) {}

Warehouse::Warehouse(int x, int y) {
	this->x = x;
	this->y = y;
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
