#include "hashcode.h"
#include <vector>

using namespace std;

Slot maxSlot(DataObject *data);

void distrib_serveur(DataObject *data, vector<Server> *serv) {
	for(int i = 0 ; i < serv->size() ; i++) {
		Slot max_available = maxSlot(data);
		//cout << max_available._r << " " << max_available._s << " " << max_available._size << endl;
		if(max_available._size >= serv->at(i)._size) {
			serv->at(i)._r = max_available._r; 
			serv->at(i)._s = max_available._s; 
			for(int j = 0 ; j < serv->at(i)._size ; j++) {
				data->list_slot[max_available._r][max_available._s+j]._dispo = USED;
			}
		}

	}
}

Slot maxSlot(DataObject *data) {
	Slot max_available(0, 0, 0);
	Slot next(0, 0, 0);
	
	for(int i = 0 ; i < R ; i++) {	
		next._r = i;
		next._size = 0;
		for(int j = 0 ; j < S ; j++) {
			next._s = j;
			switch(data->list_slot[i][j]._dispo) {
				case FREE :
					next._size++;
					break;

				case UNAV :
				case USED :
					if(next._size > max_available._size) {
						next._s -= next._size;
						max_available = next;
					}
					next._size = 0;
					break;
			}
		}
	}
	return max_available;
}
