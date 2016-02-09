#include "dataobject.h"

using namespace std;

DataObject::DataObject() {

}

int DataObject::readData(const char *filename) {

	FILE *input = fopen(filename, "r");
	
	if(input == NULL) {
		fprintf(stderr, "Cannot open file \"%s\" in %s:%d.\n", filename, __FILE__, __LINE__);
		return -1;
	}

	int a, b, c, d, e;
	fscanf(input, "%d %d %d %d %d\n", &a, &b, &c, &d, &e);

	// on créer tout les slots libre
	for(int i=0 ; i<= 15 ; i++)
	{
		for(int j=0 ; j<=99 ; j++) {
			list_slot[i][j]._r = i;
			list_slot[i][j]._r = j;
			list_slot[i][j]._size = 1;
			list_slot[i][j]._dispo = FREE;
		}
	}
	
	// on liste les slot unav
	int row = 0, slo = 0;
	for(int i=1 ; i<=80 ; i++)
	{
		fscanf(input, "%d %d\n",&row ,&slo); 
		list_slot[row][slo]._dispo = UNAV;
	}
	
	// on créer tt les serveurs
	int taille = 0, capa = 0;
	for(int i=81 ; i<=705 ; i++)
	{
		fscanf(input, "%d %d\n",&taille ,&capa);
		list_server[i-81]._id = i-81;
		list_server[i-81]._capacite = capa;
		list_server[i-81]._size = taille;
		list_server[i-81]._pool = 0;
		list_server[i-81]._r = -1;
		list_server[i-81]._s = -1;
	}
	
	
	//printf("-- %f --\n", Calcul_CP() );
	
	

	fclose(input);
	return 0;
}

DataObject::~DataObject() {

}

void DataObject::afficher_list_server(void) {

	for(int a=0 ; a<= (NB_SERVERS-1) ; a++) {	
		list_server[a].affiche();
	}
}

Server DataObject::findServer(int id) {
	return list_server[id];
}

float DataObject::Calcul_CP(void) {

	int CP_total = 0;
	for(int a=0 ; a<=NB_SERVERS-1 ; a++) {
		CP_total += list_server[a]._capacite;
	}
	return CP_total / R;
}
	
	
	
		
