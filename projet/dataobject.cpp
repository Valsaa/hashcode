#include "dataobject.h"

#include <math.h>
#include <cstdlib>

DataObject::DataObject(void)
{
    _warehouse = new vector<Warehouse*>(NBWAREHOUSE);
    _drone = new vector<Drone*>(NBDRONE);
}

int DataObject::readData(const char *filename)
{

	/*FILE *input = fopen(filename, "r");
	if(input == NULL)
    {
		fprintf(stderr, "Cannot open file \"%s\" in %s:%d.\n", filename, __FILE__, __LINE__);
		return -1;
	}*/

	ifstream fichier(filename);
    if(fichier)
    {
        char caractere;
        while(fichier.get(caractere)) //Tant qu'on n'est pas à la fin, on lit
        {
            cout << caractere << endl;
        }
   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }


	fichier.close();
	return 0;
}

void DataObject::Attrib_Grp_Wh(void) {

	// for each grp
	int min_dist = ceil(sqrt(NBROW*NBROW + NBCOL*NBCOL));
	Warehouse* WH = NULL;
	for(int a=0 ; a <= _group->size() ; a++)
	{
		for(int w=0 ; w<= _warehouse->size() ; w++)
		{
			if( _group->at(a)->calcul_distance_W(_warehouse->at(w)) < min_dist && Check_Grp_Wh(_group->at(a),_warehouse->at(w)) )
			{
				min_dist = _group->at(a)->calcul_distance_W(_warehouse->at(w));
				WH = _warehouse->at(w);
			}
		}
		if(WH != NULL)
		{
			_group->at(a)->_wh = WH;
			for(int t=0 ; t<= NBPRODTYPE ; t++)
			{
				for(int g=0 ; g<= _group->at(a)->_cmd->size() ; g++)
				{
					WH->_nbProduct.at(t) -= _group->at(a)->_cmd->at(g)->listProduct.at(t);
				}
			}
		}
	}
}

bool DataObject::Check_Grp_Wh(Grp* groupe, Warehouse* WH) {
	
	int list[NBPRODTYPE];
	bool check = 1;
	
	for(int i=0 ; i<= NBPRODTYPE ; i++)
	{
		for(int a=0 ; a<= groupe->_cmd->size() ; a++)
		{
			list[i] += groupe->_cmd->at(a)->listProduct.at(i);
		}
	}
	
	for(int i=0 ; i<= NBPRODTYPE ; i++)
	{
		if( !(WH->_nbProduct.at(i) >= list[i]) )
			check = 0;
	}
	return check;	
}

void DataObject::debug(void) {

}

DataObject::~DataObject(void) {

}
