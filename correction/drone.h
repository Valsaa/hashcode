#ifndef DRONE_H
#define DRONE_H

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

typedef enum {L, U, D, W} _Action;

class Drone {

    public:
        Drone(void);
	Drone(int x, int y, int drone_ID);
	void debug(void);
	void test(void);
	void load(FILE *output, int warehouse_ID, int product_type_ID, int nb_items);
	void unload(FILE *output, int order_ID, int product_type_ID, int nb_items);
	void deliver(FILE *output, int order_ID, int product_type_ID, int nb_items);
	void wait(FILE *output, int nb_turns);
	int computeTurnsRequired(int x, int y);
	int computeTurnsRequired(int w);
	int distance(int x, int y);
        ~Drone(void);

	int drone_ID;
	int x;
	int y;

};

#endif // DRONE_H
