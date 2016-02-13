#include "dataobject.h"

DataObject::DataObject(void) {}

void DataObject::debug(void) {
	cout << this->nb_rows << " " << this->nb_cols << " " << this->nb_drones << " " << this->nb_turns << " " << this->max_payload << endl;

	cout << this->nb_product_types << endl;
	cout << this->product_types->at(0);
	for(int i = 1 ; i < this->nb_product_types ; i++) {
		cout << " " << this->product_types->at(i);
	}
	cout << endl;

	cout << this->nb_warehouses << endl;
	for(int i = 0 ; i < this->nb_warehouses ; i++) {
		this->warehouses->at(i)->debug();
	}
	
	cout << this->nb_orders << endl;
	for(int i = 0 ; i < this->nb_orders; i++) {
		this->orders->at(i)->debug();
	}
}

bool DataObject::allDronesHaveWarehouse(void) {
	bool haveWarehouse = true;

	for(int i = 0 ; i < this->nb_drones ; i++) {
		if(this->drones->at(i)->warehouse == NULL) {
			haveWarehouse = false;
		}
	}

	return haveWarehouse;
}

bool DataObject::allOrdersTaken(void) {
	bool all_taken = true;

	for(int i = 0 ; i < this->orders->size() ; i++) {
		if(this->orders->at(i)->state == FREE) {
			all_taken = false;
		}
	}

	return all_taken;
}

DataObject::~DataObject(void) {
	delete drones;
	delete product_types;
	delete warehouses;
	delete orders;
}
