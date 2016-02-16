#include "drone.h"

Drone::Drone(void) {}

Drone::Drone(int x, int y, int drone_ID) {
	this->x = x;
	this->y = y;
	this->drone_ID = drone_ID;
	this->warehouse = NULL;
}

void Drone::debug(void) {
	cout << this->drone_ID << " " << this->x << " " << this->y << endl;
}

void Drone::load(FILE *output, int warehouse_ID, int product_type_ID, int nb_items) {
	fprintf(output, "%d L %d %d %d\n", this->drone_ID,  warehouse_ID, product_type_ID, nb_items);
}

void Drone::unload(FILE *output, int order_ID, int product_type_ID, int nb_items) {
	fprintf(output, "%d U %d %d %d\n", this->drone_ID,  order_ID, product_type_ID, nb_items);
}

void Drone::deliver(FILE *output, int order_ID, int product_type_ID, int nb_items) {
	fprintf(output, "%d D %d %d %d\n", this->drone_ID,  order_ID, product_type_ID, nb_items);
}

void Drone::wait(FILE *output, int nb_turns) {
	fprintf(output, "%d W %d\n", this->drone_ID, nb_turns);
}

int Drone::computeTurnsRequired(int x, int y) {
	return this->distance(x, y) + 1;
}

int Drone::computeTurnsRequired(int w) {
	return w;
}

int Drone::distance(int x, int y) {
	int diffX = this->x - x;
	int diffY = this->y - y;
	return ceil(sqrt(diffX * diffX + diffY * diffY));
}

void Drone::test(void) {
	this->load(stdout, 0, 1, 2);
	this->unload(stdout, 8, 541, 22);
	this->unload(stdout, 2, 13, 94);
	this->load(stdout, 7, 11, 25);
	this->wait(stdout, 25);
}

Drone::~Drone(void) {}
