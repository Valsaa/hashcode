#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <vector>

using namespace std;

typedef enum {FREE, TAKEN} State;

class Order {

	public :
		Order(void);
		Order(int x, int y, int order_ID, int nb_warehouse);
		bool isRejected(void);
		int getTotalWeight(vector<int> *weights);
		void debug(void);
		~Order(void);

		int x;
		int y;
		int order_ID;
		State state;
		vector<int> *products;
		vector<bool> *buffer;

};

#endif // ORDER_H
