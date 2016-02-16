#include "dataobject.h"

DataObject::DataObject(void) {
	this->graphs = new vector<Graph*>();
}

void DataObject::debug(void) {
	for(int i = 0 ; i < 1 ; i++) {
		this->graphs->at(i)->debug();
	}
}

int DataObject::readData(const char *filename) {
	FILE *input = fopen(filename, "r");
	if(input == NULL) {
		fprintf(stderr, "Cannot open file \"%s\" in %s:%d.\n", filename, __FILE__, __LINE__);
		return -1;
	}

	Graph *first = new Graph(); 

	// Informations générales
	fscanf(input, "%d %d %d %d %d\n", &first->nb_rows, 
					  &first->nb_cols, 
					  &first->nb_drones, 
					  &first->nb_turns, 
					  &first->max_payload);
	
	// Informations sur les produits
	fscanf(input, "%d\n", &first->nb_product_types);
	vector<int> *products = new vector<int>(first->nb_product_types);
	fscanf(input, "%d", &products->at(0));
	for(int i = 1 ; i < first->nb_product_types ; i++) {
		fscanf(input, " %d", &products->at(i)); 
	}
	first->product_weights = products;
	fscanf(input, "\n");

	// Informations sur les entrepôts
	int x = 0, y = 0;
	fscanf(input, "%d\n", &first->nb_warehouses);
	first->warehouses = new vector<Warehouse*>(first->nb_warehouses);
	for(int i = 0 ; i < first->nb_warehouses ; i++) {
		fscanf(input, "%d %d\n", &x, &y);	
		first->warehouses->at(i) = new Warehouse(x, y, i);

		products = new vector<int>(first->nb_product_types);
		fscanf(input, "%d", &products->at(0));
		for(int j = 1 ; j < first->nb_product_types ; j++) {
			fscanf(input, " %d", &products->at(j));
		}
		fscanf(input, "\n");
		first->warehouses->at(i)->products = products;
	}

	// Informations sur les drônes
	first->drones = new vector<Drone*>(first->nb_drones);
	for(int i = 0 ; i < first->nb_drones ; i++) {
		first->drones->at(i) = new Drone(first->warehouses->at(0)->x, first->warehouses->at(0)->y, i);
	}

	// Informations sur les commandes
	int nb_items = 0;
	fscanf(input, "%d\n", &first->nb_orders); 	
	first->orders = new vector<Order*>(first->nb_orders);
	for(int i = 0 ; i < first->nb_orders ; i++) {
		fscanf(input, "%d %d\n", &x, &y);
		first->orders->at(i) = new Order(x, y, i, first->nb_warehouses);
		
		fscanf(input, "%d\n", &nb_items);
		products = new vector<int>(nb_items);

		fscanf(input, "%d", &products->at(0));
		for(int j = 1 ; j < nb_items ; j++) {
			fscanf(input, " %d", &products->at(j));
		}
		first->orders->at(i)->products = products;
	}

	this->graphs->push_back(first);

	fclose(input);
	return 0;
}

int DataObject::writeResult(const char *filename) {
	FILE *output = fopen(filename, "w");
	if(output == NULL) {
		fprintf(stderr, "Cannot open file %s in %s:%d.\n", filename, __FILE__, __LINE__);
		return -1;
	}

	Graph *end = this->graphs->at(this->graphs->size()-1);
	for(int i = 0 ; i < end->drones->size() ; i++) {
		end->drones->at(i)->writeResult(output);
	}

	fclose(output);
	return 0;
}


DataObject::~DataObject(void) {
	for(int i = 0 ; i < this->graphs->size() ; i++) {
		delete this->graphs->at(i);
	}
	delete graphs;
}
