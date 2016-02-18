#include "dataobject.h"

int DataObject::process(void) {
/*	Graph *next = NULL;
	for(int i = 0 ; i < 1 ; i++) {
		next = new Graph(this->graphs->at(i), i);
		

		this->graphs->push_back(next);
	}*/

	cout << this->graphs->at(0)->warehouses->at(0)->products->at(216) << endl;
	Graph *graph = this->graphs->at(0);
	for(int i = 0 ; i < graph->drones->size() ; i++) {
		int ind = graph->drones->at(i)->computeBestPath(graph->nodes);
		Node *node = graph->nodes->at(ind);
		if(node->type == ORDER && graph->warehouses->at(0)->canProvide((Order*) node, graph->max_payload, graph->product_weights)) {
			Order *order = (Order*) node;
			for(int j = 0 ; j < order->products->size() ; j++) {
				graph->drones->at(i)->load(0, order->products->at(j), 1);
			}
			for(int j = 0 ; j < order->products->size() ; j++) {
				graph->drones->at(i)->deliver(order->order_ID, order->products->at(j), 1);
			}
			//cout << i << " - can provide" << endl;
		}
		//cout << (node->type == WAREHOUSE ? "WAREHOUSE " : "ORDER ") << node->x << " " << node->y << endl;
		graph->nodes->erase(graph->nodes->begin() + ind);
	}
	return 0;
}
