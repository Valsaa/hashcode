#ifndef DRONE_H
#define DRONE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include "node.h"
#include "warehouse.h"

using namespace std;

class Drone {

    public:
        Drone(void);
	Drone(Drone *drone);
	Drone(int x, int y, int drone_ID);
        ~Drone(void);

	void debug(void);
	void test(void);
	void writeResult(ofstream *output);
	int computeBestPath(vector<Node*> *nodes);
	int distance(Node *node);
	void load(int warehouse_ID, int product_type_ID, int nb_items);
	void unload(int order_ID, int product_type_ID, int nb_items);
	void deliver(int order_ID, int product_type_ID, int nb_items);
	void wait(int nb_turns);

	int drone_ID;
	int x;
	int y;
	int nb_wait_turns;
	vector<string> *commands;

};

#endif // DRONE_H
