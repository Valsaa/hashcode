#include "hashcode.h"

int writeResultFile(const char *filename, const ResultStruct *result) {

	if(0) {
		printf("%s", (char*) result->pointer); // A SUPPRIMER
	}

	FILE *output = fopen(filename, "w");
	if(output == NULL) {
		fprintf(stderr, "Cannot open file %s in %s:%d.\n", filename, __FILE__, __LINE__);
		return -1;
	}

	fclose(output);
	return 0;
}
