#include "hashcode.h"

void distrib_pool(DataObject *data, vector<Server> *serv) {
	for(int id_pool = 0 ; id_pool < NB_POOL ; id_pool++) {
		int coef = (int) data->Calcul_CP();
		bool boolean = false;
		while(coef >= 0 && boolean == false) {
			for(int i = 0 ; i < R ; i++) {
				vector<Server*> list_serv = data->getServerAtRow(i);
				for(int j = 0 ; j < list_serv.size() ; j++) {
					if(list_serv.at(j)->_pool != -1) {
						boolean = true;
					}

					if(list_serv.at(j)->_pool == -1 && coef >= 0) {
						boolean = false;
						for(int k = 0 ; k < serv->size() ; k++) {
							if(list_serv.at(j)->_id == serv->at(k)._id) {
								serv->at(k)._pool = id_pool;
								coef -= serv->at(k)._capacite;
							}
						}	
					}
				}
			}
		}
	}
}
