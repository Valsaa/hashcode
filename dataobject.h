#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <iostream>
#include <cstdio>

typedef enum {FREE, USED, UNAV} etat_slot;

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
		etat_slot dispo;
		
		Slot(int row, int slot, etat_slot state);
};

class Server {

	public :
		int capacite;
		int size;
		int pool;
		int slot;
		
		Server(int ca, int si, int po, int sl);
		
		
};

#endif // DATAOBJECT_H
