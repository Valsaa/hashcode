#ifndef DRONE_H
#define DRONE_H

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

class Drone {

    public:
        Drone(void);
	Drone(int drone_ID);
	void debug(void);
	void test(void);
	void load(FILE *output, int warehouse_ID, int product_type_ID, int nb_items);
	void unload(FILE *output, int order_ID, int product_type_ID, int nb_items);
	void wait(FILE *output, int nb_turns);
        ~Drone(void);

	int drone_ID;

};

#endif // DRONE_H
