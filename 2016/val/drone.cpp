#include "drone.h"

Drone::Drone(void) {
	this->x = 0;
	this->y = 0;
	this->drone_ID = 0;
	this->commands = new vector<string>();
}

Drone::Drone(Drone *drone) {
	this->x = drone->x;
	this->y = drone->y;
	this->drone_ID = drone->drone_ID;
	this->commands = new vector<string>(drone->commands->size());
	for(int i = 0 ; i < drone->commands->size() ; i++) {
		this->commands->at(i) = drone->commands->at(i);
	}
}

Drone::Drone(int x, int y, int drone_ID) {
	this->x = x;
	this->y = y;
	this->drone_ID = drone_ID;
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

void Drone::test(void) {
	this->load(0, 1, 2);
	this->unload(8, 541, 22);
	this->unload(2, 13, 94);
	this->load(7, 11, 25);
	this->wait(25);
}

Drone::~Drone(void) {}
