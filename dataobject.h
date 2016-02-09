#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <iostream>
#include <cstdio>
#include "server.h"
#include "slot.h"

#define NB_POOL			45
#define NB_SERVERS		625
#define NB_SLOTS		1600
#define R				16
#define S				100
#define NB_SLOT_UNAV	80

class DataObject {

	public :
	
		Server list_server[NB_SERVERS];
		Slot list_slots[R][S];
		
		DataObject(void);
		int readData(const char *filename);
		~DataObject(void);
};


#endif // DATAOBJECT_H
