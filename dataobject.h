#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <iostream>
#include <cstdio>

class DataObject {

	public :
		DataObject(void);
		int readData(const char *filename);
		~DataObject(void);
};

class Slot {

	public :
		int r;
		int s;
		enum {free, used, unav} dispo;
		
};

class Server {

	public :
		int capacite;
		int size;
		int pool;
		
}

#endif // DATAOBJECT_H
