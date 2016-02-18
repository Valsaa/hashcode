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
	ifstream input(filename);

	Graph *first = new Graph(); 

	// Informations générales
	input >> first->nb_rows >> first->nb_cols >> first->nb_drones >> first->nb_turns >> first->max_payload;
	
	// Informations sur les produits
	input >> first->nb_product_types;
	vector<int> *products = new vector<int>(first->nb_product_types);
	input >> products->at(0);
	for(int i = 1 ; i < first->nb_product_types ; i++) {
		input >> products->at(i); 
	}
	first->product_weights = products;

	// Informations sur les entrepôts
	int x = 0, y = 0;
	input >> first->nb_warehouses;
	first->warehouses = new vector<Warehouse*>(first->nb_warehouses);
	for(int i = 0 ; i < first->nb_warehouses ; i++) {
		input >> x >> y;	
		//cout << x << " " << y << endl;
		first->warehouses->at(i) = new Warehouse(x, y, i);

		products = new vector<int>(first->nb_product_types);
		input >> products->at(0);
		for(int j = 1 ; j < first->nb_product_types ; j++) {
			input >> products->at(j);
		}
		first->warehouses->at(i)->products = products;
		first->nodes->push_back(first->warehouses->at(i)); 
	}

	// Informations sur les drônes
	first->drones = new vector<Drone*>(first->nb_drones);
	for(int i = 0 ; i < first->nb_drones ; i++) {
		first->drones->at(i) = new Drone(first->warehouses->at(0)->x, first->warehouses->at(0)->y, i);
	}

	// Informations sur les commandes
	int nb_items = 0;
	input >> first->nb_orders; 	
	first->orders = new vector<Order*>(first->nb_orders);
	for(int i = 0 ; i < first->nb_orders ; i++) {
		input >> x >> y;
		first->orders->at(i) = new Order(x, y, i, first->nb_warehouses);
		
		input >> nb_items;
		products = new vector<int>(nb_items);

		input >> products->at(0);
		for(int j = 1 ; j < nb_items ; j++) {
			input >> products->at(j);
		}
		first->orders->at(i)->products = products;
		first->nodes->push_back(first->orders->at(i));
	}

	this->graphs->push_back(first);

	input.close();
	return 0;
}

int DataObject::writeResult(const char *filename) {
	ofstream output(filename);

	Graph *end = this->graphs->at(this->graphs->size()-1);
	for(int i = 0 ; i < end->drones->size() ; i++) {
		end->drones->at(i)->writeResult(&output);
	}

	output.close();
	return 0;
}


DataObject::~DataObject(void) {
	for(int i = 0 ; i < this->graphs->size() ; i++) {
		delete this->graphs->at(i);
	}
	delete graphs;
}
