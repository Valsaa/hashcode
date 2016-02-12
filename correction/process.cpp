#include "hashcode.h"

void attributeOrders2Warehouses(DataObject *data);

int process(DataObject *data, ResultObject *result) {
	attributeOrders2Warehouses(data);
	



	for(int i = 0 ; i < data->nb_warehouses ; i++) {
		data->warehouses->at(i)->debug();
	}
	

/*	for(int i = 0 ; i < data->nb_drones ; i++) {
		data->drones->at(i)->debug();
	}*/
	return 0;
}

void attributeOrders2Warehouses(DataObject *data) {
	while(data->allOrdersTaken() == false) {
		for(int i = 0 ; i < data->nb_warehouses ; i++) {
			Order *closest = data->warehouses->at(i)->closestFreeOrder(data->orders);
			if(closest != NULL && data->warehouses->at(i)->canProvideOrder(closest)) {
				data->warehouses->at(i)->orders->push_back(closest);
				data->warehouses->at(i)->provideOrder(closest);
				closest->state = TAKEN;
			}
		}

		for(int i = 0 ; i < data->nb_orders ; i++) {
			if(data->orders->at(i)->isRejected()) {
				data->orders->at(i)->state = TAKEN;
			}
		}
	}
}
