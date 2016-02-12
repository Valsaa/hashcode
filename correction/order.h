#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <vector>

using namespace std;

class Order {

	public :
		Order(void);
		Order(int x, int y);
		void debug(void);
		~Order(void);

		int x;
		int y;
		vector<int> *products;

};

#endif // ORDER_H
