#include "dataobject.h"

int DataObject::readData(const char *filename) {
	FILE *input = fopen(filename, "r");
	if(input == NULL) {
		fprintf(stderr, "Cannot open file \"%s\" in %s:%d.\n", filename, __FILE__, __LINE__);
		return -1;
	}

	// Informations générales
	fscanf(input, "%d %d %d %d %d\n", &this->nb_rows, &this->nb_cols, &this->nb_drones, &this->nb_turns, &this->max_payload);
	
	// Informations sur les produits
	fscanf(input, "%d\n", &this->nb_product_types);
	vector<int> *products = new vector<int>(this->nb_product_types);
	fscanf(input, "%d", &products->at(0));
	for(int i = 1 ; i < this->nb_product_types ; i++) {
		fscanf(input, " %d", &products->at(i)); 
	}
	this->product_types = products;
	fscanf(input, "\n");

	// Informations sur les entrepôts
	int x = 0, y = 0;
	fscanf(input, "%d\n", &this->nb_warehouses);
	this->warehouses = new vector<Warehouse*>(this->nb_warehouses);
	for(int i = 0 ; i < this->nb_warehouses ; i++) {
		fscanf(input, "%d %d\n", &x, &y);	
		this->warehouses->at(i) = new Warehouse(x, y, i);

		products = new vector<int>(this->nb_product_types);
		fscanf(input, "%d", &products->at(0));
		for(int j = 1 ; j < this->nb_product_types ; j++) {
			fscanf(input, " %d", &products->at(j));
		}
		fscanf(input, "\n");
		this->warehouses->at(i)->products = products;
	}

	// Informations sur les drônes
	this->drones = new vector<Drone*>(this->nb_drones);
	for(int i = 0 ; i < this->nb_drones ; i++) {
		this->drones->at(i) = new Drone(this->warehouses->at(0)->x, this->warehouses->at(0)->y, i);
	}

	// Informations sur les commandes
	int nb_items = 0;
	fscanf(input, "%d\n", &this->nb_orders); 	
	this->orders = new vector<Order*>(this->nb_orders);
	for(int i = 0 ; i < this->nb_orders ; i++) {
		fscanf(input, "%d %d\n", &x, &y);
		this->orders->at(i) = new Order(x, y, i, this->nb_warehouses);
		
		fscanf(input, "%d\n", &nb_items);
		products = new vector<int>(nb_items);

		fscanf(input, "%d", &products->at(0));
		for(int j = 1 ; j < nb_items ; j++) {
			fscanf(input, " %d", &products->at(j));
		}
		this->orders->at(i)->products = products;
	}

	fclose(input);
	return 0;
}
