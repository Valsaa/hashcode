#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <iostream>
#include <fstream>
#include "graph.h"

using namespace std;

class DataObject {

	public :
		DataObject(void);
		~DataObject(void);

		void debug(void);
		int process(void);
		int readData(const char *filename);
		int writeResult(const char *filename);

		int nb_turns;
		vector<Graph*> *graphs;
};

#endif // DATAOBJECT_H
