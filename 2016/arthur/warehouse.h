#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream>
#include <vector>
#include <cmath>
#include "order.h"

using namespace std;

class Warehouse {

	public :
		Warehouse(void);
		Warehouse(int x, int y, int warehouse_ID);
		Order* closestFreeOrder(vector<Order*> *orders);
		int distance(Order *order);
		bool isClosest(Order *order, int dist_min);
		bool canProvideOrder(Order *order);
		void provideOrder(Order *order);
		void computeMinDrones(int max_payload, vector<int> *weights);
		void debug(void);
		~Warehouse(void);

		int x;
		int y;
		int warehouse_ID;
		int min_drones;
		vector<int> *products;
		vector<Order*> *orders;
};

#endif
