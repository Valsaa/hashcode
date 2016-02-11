#include "dataobject.h"

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

void DataObject::debug(void) {

}

DataObject::~DataObject(void) {

}
