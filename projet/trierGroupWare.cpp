#include "hashcode.h"

void trierGroupWare(DataObject *data) {
    bool tab_en_ordre = false;
    long taille = data->_group->size()-1;
    while(!tab_en_ordre)
    {
        tab_en_ordre = true;
        for(long i=0 ; i<taille; ++i)
        {
            if(data->_group->at(i)->calcul_distance_W(data->_group->at(i)->_wh) < data->_group->at(i+1)->calcul_distance_W(data->_group->at(i+1)->_wh))
            {
                swap(data->_group->at(i),data->_group->at(i+1));
                tab_en_ordre = false;
            }
        }
        taille--;
    }

}

