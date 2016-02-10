#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class DataObject {

	public :
		DataObject(void);
		int readData(const char *filename);
		~DataObject(void);
};

#endif // DATAOBJECT_H
