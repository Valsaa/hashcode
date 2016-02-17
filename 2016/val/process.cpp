#include "dataobject.h"

int DataObject::process(void) {
/*	Graph *next = NULL;
	for(int i = 0 ; i < 1 ; i++) {
		next = new Graph(this->graphs->at(i), i);
		

		this->graphs->push_back(next);
	}*/

	for(int i = 0 ; i < this->graphs->at(0)->drones->size() ; i++) {
		this->graphs->at(0)->drones->at(i)->test();
	}
	return 0;
}
