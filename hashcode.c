#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct _datastruct {
	// Déclarer les variables de données ici
} DataStruct;

typedef struct _resultstruct {
	// Déclarer les variables résultats ici
} ResultStruct;

int readInputFile(const char *filename, DataStruct *data);
int process(const DataStruct *data, ResultStruct *result);
int writeResultFile(const char *filename, const ResultStruct *result);

int main (int argc, char **argv) {

	DataStruct data;
	ResultStruct result;
	
	// Changer le nom du fichier au besoin
	int status = readInputFile("input.in", &data);
	if(status < 0) {
		fprintf(stderr, "readInputFile return %d... expected 0 !", status);
	}	

	process(&data, &result);
	if(status < 0) {
		fprintf(stderr, "process return %d... expected 0 !", status);
	}	

	writeResultFile("output.out", &result);
	if(status < 0) {
		fprintf(stderr, "writeResultFile return %d... expected 0 !", status);
	}	

	return 0;
}

int readInputFile(const char *filename, DataStruct *data) {

	FILE *input = fopen(filename, "r");
	if(input == NULL) {
		fprintf(stderr, "Cannot open file %s in %s:%d.\n", filename, __FILE__, __LINE__);
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

int process(const DataStruct *data, ResultStruct *result) {
	// Traitement des données ici
	return 0;
}

int writeResultFile(const char *filename, const ResultStruct *result) {

	FILE *output = fopen(filename, "w");
	if(output == NULL) {
		fprintf(stderr, "Cannot open file %s in %s:%d.\n", filename, __FILE__, __LINE__);
		return -1;
	}

	fclose(output);
	return 0;
}
