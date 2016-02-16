#include "dataobject.h"

int DataObject::process(void) {
	Graph *next = NULL;
	for(int i = 0 ; i < 1 ; i++) {
		next = new Graph(this->graphs->at(i), i);
		

		this->graphs->push_back(next);
	}
	return 0;
}
