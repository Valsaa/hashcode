#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <iostream>
#include <cstdio>

#define NB_POOL			45
#define NB_SERVERS		625
#define NB_SLOTS		1600
#define R				16
#define S				100
#define NB_SLOT_UNAV	80

typedef enum {FREE, USED, UNAV} etat_slot;

class Slot {

	public :
		int _r;
		int _s;
		int _size;
		etat_slot _dispo;
		
		Slot(int row, int slot, etat_slot state);
		Slot(int row, int slot, int size);
};

class Server {

	public :
		int _capacite;
		int _size;
		int _pool;
		int _r;
		int _s;
		
		Server(int ca, int si, int po);
		
};

class DataObject {

	public :
	
		Server list_server[NB_SERVERS];
		Slot list_slots[R][S]
		
		DataObject(void);
		int readData(const char *filename);
		~DataObject(void);
};


#endif // DATAOBJECT_H
