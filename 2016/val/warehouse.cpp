#include "warehouse.h"

Warehouse::Warehouse(void) {
	this->x = 0;
	this->y = 0;
	this->warehouse_ID = 0;
	this->type = WAREHOUSE;
	this->products = new vector<int>();
}

Warehouse::Warehouse(Warehouse *warehouse) {
	this->x = warehouse->x;
	this->y = warehouse->y;
	this->warehouse_ID = warehouse->warehouse_ID;
	this->type = WAREHOUSE;
	this->products = new vector<int>(warehouse->products->size());
	for(int i = 0 ; i < warehouse->products->size() ; i++) {
		this->products->at(i) = warehouse->products->at(i);
	}	
}

Warehouse::Warehouse(int x, int y, int warehouse_ID) {
	this->x = x;
	this->y = y;
	this->warehouse_ID = warehouse_ID;
	this->type = WAREHOUSE;
	this->products = new vector<int>();
}

bool Warehouse::canProvide(const Order *order, int max_payload, const vector<int> *weights) {
	bool boolean = true;

	vector<int> *products = new vector<int>(this->products->size());
	for(int i = 0 ; i < products->size() ; i++) {
		products->at(i) = this->products->at(i);
	}

	for(int i = 0 ; i < order->products->size() ; i++) {
		products->at(order->products->at(i))--;
		max_payload -= weights->at(order->products->at(i));
		if(products->at(order->products->at(i)) < 0 && max_payload < 0) {
			boolean = false;
		}
	}

	return boolean;
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
	//delete this->products;
}
