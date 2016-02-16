#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

#include "node.h"
#include "warehouse.h"
#include "order.h"
#include "drone.h"

using namespace std;

class Graph {

	public :
		Graph(void);
		Graph(Graph *graph, int id);
		~Graph(void);

		void setData(Graph *graph);
		void debug(void);

		int nb_rows;
		int nb_cols;
		int nb_drones;
		int nb_turns;
		int max_payload;
		int nb_product_types;
		int nb_warehouses;
		int nb_orders;
		int turn_ID;

		vector<int> 		*product_weights;
		vector<Node*> 		*nodes;
		vector<Warehouse*> 	*warehouses;
		vector<Order*> 		*orders;
		vector<Drone*> 		*drones;

};
#endif
