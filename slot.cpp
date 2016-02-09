#include "slot.h"

Slot::Slot() {}

Slot::Slot(int row, int slot, etat_slot state) {
	_size = 0;
	_r = row;
	_s = slot;
	_dispo = state;
}

Slot::Slot(int row, int slot, int size) {
	_size = size;
	_r = row;
	_s = slot;
}

