#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream>
#include <vector>
#include "node.h"
#include "order.h"

using namespace std;

class Warehouse : public Node {

	public :
		Warehouse(void);
		Warehouse(Warehouse *warehouse);
		Warehouse(int x, int y, int warehouse_ID);
		bool canProvide(const Order *order, int max_payload, const vector<int> *weights);
		~Warehouse(void);

		void debug(void);

		int x;
		int y;
		int warehouse_ID;
		vector<int> *products;
};

#endif
