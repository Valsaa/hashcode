#include "hashcode.h"

int process(const DataStruct *data, ResultStruct *result) {
	
	result->pointer = data->pointer; // A SUPPRIMER

	// Traitement des données ici
	return 0;
}

/* Calcul le minimum d'un tableau d'entier 
 * param : 
 * 	- le tableau d'entier
 * 	- la taille du tableau
 * renvoit :
 * 	- le minimum du tableau
 */
int min(const int *tab, int size, int *ind) {
	int min = tab[0];
	for(int i = 1 ; i < size ; i++) {
		if(tab[i] < min) {
			min  = tab[i];
			*ind = i;
		}
	}
	return min;
}

/* Calcul le maximum d'un tableau d'entier 
 * param : 
 * 	- le tableau d'entier
 * 	- la taille du tableau
 * renvoit :
 * 	- le maximum du tableau
 */
int max(const int *tab, int size) {
	int max = tab[0];
	for(int i = 1 ; i < size ; i++) {
		if(tab[i] > max) {
			max = tab[i];
		}
	}
	return max;
}

int max2D(const int **tab, int nbrows, int nbcolumns) {
	int ind = 0;
	int max = max(tab[][nbcolumns/2], nbrows, &ind);
	
	int status = isPeak(tab, nbrows, nbcolumns, ind, nbcolumns/2);
	switch(status) {
		case -1 : return max2D(tab, nbrows, nbcolumns/2);
			break;

		case 0 : return max;
			break;

		case 1 : return max2D(tab[][nbcolumns/2], nbrows, nbcolumns/2);
			break;

		default :
			fprint(stderr, "Status error at %s:%d : status %d unknown.\n", __FILE__, __LINE__, status);
			break;
	}
}

int isPeak(const int **tab, int nbrows, int nbcolumns, int x, int y){
	return 0;
}
