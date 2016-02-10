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

	fclose(input);
	return 0;
}

DataObject::~DataObject() {

}
