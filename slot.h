#ifndef SLOT_H
#define SLOT_H

#include <iostream>
#include <cstdio>

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

#endif // SLOT_H
