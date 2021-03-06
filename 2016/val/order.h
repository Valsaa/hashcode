#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <vector>
#include "node.h"

using namespace std;

class Order : public Node {

	public :
		Order(void);
		Order(Order *order);
		Order(int x, int y, int order_ID, int nb_warehouse);
		~Order(void);
		
		void debug(void);

		int order_ID;
		vector<int> *products;

};

#endif // ORDER_H
