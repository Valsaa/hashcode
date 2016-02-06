#ifndef HASHCODE_H
#define HASHCODE_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>

typedef struct _datastruct {
	// Déclarer les variables de données ici
	void *pointer;
} DataStruct;

typedef struct _resultstruct {
	// Déclarer les variables résultats ici
	void *pointer;
} ResultStruct;

int readInputFile(const char *filename, DataStruct *data);
int process(const DataStruct *data, ResultStruct *result);
int writeResultFile(const char *filename, const ResultStruct *result);

#endif // HASHCODE_H
