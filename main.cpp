#include "hashcode.h"

void triServer(vector<Server> *serv);
void distrib_serveur(DataObject *data, vector<Server> *serv);
void distrib_pool(DataObject *data, vector<Server> *serv);

int main (int argc, char **argv) {

	if(argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))) {
		printf("Usage : ./hashcode.out [input filename] [output filename]\n");
		return -1;
	}
	
	DataObject *data = new DataObject();
	int status = data->readData(argc == 2 ? argv[1] : "dc.in");
	if(status < 0) {
		fprintf(stderr, "readInputFile return %d... expected 0 !\n", status);
		return -2;
	}	

	ResultObject *result = new ResultObject();
	triServer(data->list_server);
	distrib_serveur(data, data->list_server);
	data->afficher_list_server();
	distrib_pool(data, data->list_server);
	result->writeResult(data, data->list_server, argc == 3 ? argv[2] : "output.txt");
	if(status < 0) {
		fprintf(stderr, "writeResultFile return %d... expected 0 !\n", status);
		return -4;
	}	

	delete data;
	delete result;
	
	return 0;
}


void triServer(vector<Server> *serv)
{
    // Trie la capacité
    bool tab_en_ordre = false;
    long taille = serv->size()-1;
    while(!tab_en_ordre)
    {
        tab_en_ordre = true;
        for(long i=0 ; i<taille; ++i)
        {
            if(serv->at(i)._capacite < serv->at(i+1)._capacite)
            {
                swap(serv->at(i),serv->at(i+1));
                tab_en_ordre = false;
            }
        }
        taille--;
    }

    // Trie la taille
    tab_en_ordre = false;
    taille = serv->size()-1;
    while(!tab_en_ordre)
    {
        tab_en_ordre = true;
        for(long i=0 ; i<taille; ++i)
        {
            if(serv->at(i)._capacite == serv->at(i+1)._capacite && serv->at(i)._size > serv->at(i+1)._size)
            {
                swap(serv->at(i),serv->at(i+1));
                tab_en_ordre = false;
            }
        }
        taille--;
    }
}

