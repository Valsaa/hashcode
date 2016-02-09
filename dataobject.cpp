#include "dataobject.h"

DataObject::DataObject() {

}

int DataObject::readData(const char *filename) {

	FILE *input = fopen(filename, "r");
	if(input == NULL) {
		fprintf(stderr, "Cannot open file \"%s\" in %s:%d.\n", filename, __FILE__, __LINE__);
		return -1;
	}

	// Traitement du fichier pour récup les données ici
	
	/* Exemple avec la fonction scanf
	int i = 0, row = 0, col = 0;
	fscanf(input, "%d %d\n", &row, &col);
	printf("%d %d\n", row, col);

	char tabChar[col];
	for(i = 0 ; i < row ; i++) {
		fscanf(input, "%s\n", tabChar);
		printf("%s\n", tabChar);
	}*/
	
	//list_slot = NULL;
	
	/*for(int i=0 ; i<= 15 ; i++)
	{
		for(int j=0 ; j<=99 ; j++) {
			list_slot[i] = new Slot(i,j,FREE);
		}
	}
	}*/
	
	
	
	
	
	
	

	fclose(input);
	return 0;
}

DataObject::~DataObject() {

}

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

Server::Server(int ca, int si, int po) {
	_capacite = ca;
	_size = si;
	_pool = po;
	_r = 0;
	_s = 0;
}

