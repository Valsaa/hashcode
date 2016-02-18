#include "graph.h"

Graph::Graph(void) {
	this->nb_rows 		= 0;
	this->nb_cols 		= 0;
	this->nb_drones 	= 0;
	this->nb_turns 		= 0;
	this->max_payload 	= 0;
	this->nb_product_types 	= 0;
	this->nb_warehouses 	= 0;
	this->nb_orders 	= 0;
	this->turn_ID 		= 0;

	this->product_weights   = new vector<int>();
	this->nodes 		= new vector<Node*>();
	this->warehouses 	= new vector<Warehouse*>();
	this->orders 		= new vector<Order*>();
	this->drones 		= new vector<Drone*>();
}

Graph::Graph(Graph *graph, int id) {
	this->nb_rows 		= graph->nb_rows;
	this->nb_cols 		= graph->nb_cols;
	this->nb_drones 	= graph->nb_drones;
	this->nb_turns 		= graph->nb_turns;
	this->max_payload 	= graph->max_payload;
	this->nb_product_types 	= graph->nb_product_types;
	this->nb_warehouses 	= graph->nb_warehouses;
	this->nb_orders 	= graph->nb_orders;
	this->turn_ID 		= id; 

	this->product_weights = new vector<int>(graph->product_weights->size());
	for(int i = 0 ; i < graph->product_weights->size() ; i++) {
		this->product_weights->at(i) = graph->product_weights->at(i);
	}

	this->nodes = new vector<Node*>(graph->nodes->size());
	for(int i = 0 ; i < graph->nodes->size() ; i++) {
		this->nodes->at(i) = new Node(graph->nodes->at(i));
	}

	this->warehouses = new vector<Warehouse*>(graph->warehouses->size());
	for(int i = 0 ; i < graph->warehouses->size() ; i++) {
		this->warehouses->at(i) = new Warehouse(graph->warehouses->at(i));
	}

	this->drones = new vector<Drone*>(graph->drones->size());
	for(int i = 0 ; i < graph->drones->size() ; i++) {
		this->drones->at(i) = new Drone(graph->drones->at(i));
	}

	this->orders = new vector<Order*>(graph->orders->size());
	for(int i = 0 ; i < graph->orders->size() ; i++) {
		this->orders->at(i) = new Order(graph->orders->at(i));
	}
}

void Graph::debug(void) {
	cout << this->nb_rows << " " << this->nb_cols << " " << this->nb_drones << " " << this->nb_turns << " " << this->max_payload << endl;

	cout << this->nb_product_types << endl;
	cout << this->product_weights->at(0);
	for(int i = 1 ; i < this->nb_product_types ; i++) {
		cout << " " << this->product_weights->at(i);
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

Graph::~Graph(void) {
	delete this->product_weights;

	for(int i = 0 ; i < this->nodes->size() ; i++) {
		if(this->nodes->at(i) != NULL) 
			delete this->nodes->at(i);
	}
	delete this->nodes;

	for(int i = 0 ; i < this->warehouses->size() ; i++) {
		if(this->warehouses->at(i) != NULL)
			delete this->warehouses->at(i);
	}
	delete this->warehouses;

	for(int i = 0 ; i < this->orders->size() ; i++){
		if(this->orders->at(i) != NULL)
			delete this->orders->at(i);
	}
	delete this->orders;

	for(int i = 0 ; i < this->drones->size() ; i++) {
		if(this->drones->at(i) != NULL)
			delete this->drones->at(i);
	}
	delete this->drones;
}

