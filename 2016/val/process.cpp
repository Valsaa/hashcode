#include "hashcode.h"

void attributeOrders2Warehouses(DataObject *data);
void computeMinDronesPerWarehouse(DataObject *data);
void attributeWarehouses2Drones(DataObject *data);

int process(DataObject *data, ResultObject *result) {
	cout << "Attribuer les commandes aux entrepots" << endl;
	attributeOrders2Warehouses(data);
	cout << "Calculer le nombre min de drones par entrepot" << endl;
	computeMinDronesPerWarehouse(data);
	cout << "Attribuer les warehouses aux drones" << endl;
	attributeWarehouses2Drones(data);
	cout << "Traiter la demande" << endl;
	for(int i = 0 ; i < data->nb_drones ; i++) {
		data->drones->at(i)->test();
	}
	
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

void computeMinDronesPerWarehouse(DataObject *data) {
	int nb_drones_required = 0;
	for(int i = 0 ; i < data->nb_warehouses ; i++) {
		data->warehouses->at(i)->computeMinDrones(data->max_payload, data->product_types);
		nb_drones_required += data->warehouses->at(i)->min_drones;
	}
	for(int i = 0 ; i < data->nb_warehouses ; i++) {
		data->warehouses->at(i)->min_drones =  ceil((data->warehouses->at(i)->min_drones * data->nb_drones) /(float) nb_drones_required);
	}
}

void attributeWarehouses2Drones(DataObject *data) {
	for(int i = 0 ; i < data->nb_warehouses ; i++) {
		for(int j = 0 ; j < data->nb_drones ; j++) {
			if(data->drones->at(j)->warehouse == NULL && data->warehouses->at(i)->min_drones > 0) {
				data->drones->at(j)->warehouse = data->warehouses->at(i);
				data->warehouses->at(i)->min_drones--;
			}
		}
	}
}
