#include "hashcode.h"

int min1D(const int *tab, int size, int *ind);
int max1D(const int *tab, int size, int *ind);

int process(const DataObject *data, ResultObject *result) {
	
	int tab[15] = {56,  80,  49,   20,  684,
		       32, -54,  15, -894, -654,
		       61,  3, -90,   51,   -3};

	int ind = 0;
	printf("min : %d\t-\t", min1D(tab, 15, &ind));
	printf("ind : %d\n", ind);
	printf("max : %d\t-\t", max1D(tab, 15, &ind));
	printf("ind : %d\n", ind);

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
int min1D(const int *tab, int size, int *ind) {
	int min = *tab;
	for(int i = 1 ; i < size ; i++) {
		if(*(tab+i) < min) {
			min  = *(tab+i);
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
int max1D(const int *tab, int size, int *ind) {
	int max = *tab;
	for(int i = 1 ; i < size ; i++) {
		if(*(tab+i) > max) {
			max  = *(tab+i);
			*ind = i;
		}
	}
	return max;
}
