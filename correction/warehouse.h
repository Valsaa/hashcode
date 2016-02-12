#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream>
#include <vector>

using namespace std;

class Warehouse {

	public :
		Warehouse(void);
		Warehouse(int x, int y);
		void debug(void);
		~Warehouse(void);

		int x;
		int y;
		vector<int> *products;
};

#endif
