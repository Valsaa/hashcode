#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <iostream>
#include <cstdio>
#include "drone.h"
#include "warehouse.h"
#include "order.h"

using namespace std;

class DataObject {

	public :
		DataObject(void);
		void debug(void);
		int readData(const char *filename);
		~DataObject(void);

		int nb_rows;
		int nb_cols;
		int nb_drones;
		int nb_turns;
		int max_payload;
		int nb_product_types;
		int nb_warehouses;
		int nb_orders;

		vector<Drone*> 		*drones;
		vector<int> 		*product_types;
		vector<Warehouse*> 	*warehouses;
		vector<Order*>		*orders;
};

#endif // DATAOBJECT_H
