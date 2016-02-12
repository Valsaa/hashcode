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
		Warehouse(int x, int y);
		Order* closestOrder(vector<Order*> *orders);
		int distance(Order *order);
		bool isClosest(Order *order, int dist_min);
		void debug(void);
		~Warehouse(void);

		int x;
		int y;
		vector<int> *products;
};

#endif
