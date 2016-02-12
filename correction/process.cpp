#include "hashcode.h"

int process(const DataObject *data, ResultObject *result) {
	for(int i = 0 ; i < data->nb_warehouses ; i++) {
		Order *closest = data->warehouses->at(i)->closestOrder(data->orders);
		closest->debug();
	}
	for(int i = 0 ; i < data->nb_drones ; i++) {
//		data->drones->at(i)->test();
	}
	return 0;
}

