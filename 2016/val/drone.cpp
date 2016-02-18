#include "drone.h"

Drone::Drone(void) {
	this->x = 0;
	this->y = 0;
	this->drone_ID = 0;
	this->nb_wait_turns = 0;
	this->commands = new vector<string>();
}

Drone::Drone(Drone *drone) {
	this->x = drone->x;
	this->y = drone->y;
	this->drone_ID = drone->drone_ID;
	this->nb_wait_turns = this->nb_wait_turns > 0 ? drone->nb_wait_turns-1 : 0;
	this->commands = new vector<string>(drone->commands->size());
	for(int i = 0 ; i < drone->commands->size() ; i++) {
		this->commands->at(i) = drone->commands->at(i);
	}
}

Drone::Drone(int x, int y, int drone_ID) {
	this->x = x;
	this->y = y;
	this->drone_ID = drone_ID;
	this->nb_wait_turns = 0;
	this->commands = new vector<string>();
}

void Drone::debug(void) {
	cout << this->drone_ID << " " << this->x << " " << this->y << endl;
}

void Drone::load(int warehouse_ID, int product_type_ID, int nb_items) {
	ostringstream oss;
	oss << this->drone_ID << " L " << warehouse_ID << " " << product_type_ID << " " << nb_items << endl;
	this->commands->push_back(oss.str());
}

void Drone::unload(int order_ID, int product_type_ID, int nb_items) {
	ostringstream oss;
	oss << this->drone_ID << " U " << order_ID << " " << product_type_ID << " " << nb_items << endl;
	this->commands->push_back(oss.str());
}

void Drone::deliver(int order_ID, int product_type_ID, int nb_items) {
	ostringstream oss;
	oss << this->drone_ID << " D " << order_ID << " " << product_type_ID << " " << nb_items << endl;
	this->commands->push_back(oss.str());
}

void Drone::wait(int nb_turns) {
	ostringstream oss;
	oss << this->drone_ID << " W " << nb_turns << endl;
	this->commands->push_back(oss.str());
}

void Drone::writeResult(ofstream *output) {
	for(int i = 0 ; i < this->commands->size() ; i++) {
		*output << this->commands->at(i);
	}
}

int Drone::computeBestPath(vector<Node*> *nodes) {
	int dist_min = this->distance(nodes->at(0));
	int dist = 0;
	int ind = 0;
	for(int i = 1 ; i < nodes->size() ; i++) {
		dist = this->distance(nodes->at(i));
		if(dist < dist_min) {
			dist_min = dist;
			ind = i;
		}
	}
	return ind;	
}

int Drone::distance(Node *node) {
	int diffX = this->x - node->x;
	int diffY = this->y - node->y;
	return ceil(sqrt(diffX*diffX + diffY*diffY));
}

void Drone::test(void) {
	this->load(0, 1, 2);
	this->unload(8, 541, 22);
	this->unload(2, 13, 94);
	this->load(7, 11, 25);
	this->wait(25);
}

Drone::~Drone(void) {}
