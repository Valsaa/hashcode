#include "resultobject.h"

ResultObject::ResultObject() {

}

int ResultObject::writeResult(const char *filename)
{
	FILE *output = fopen(filename, "w");
	if(output == NULL) {
		fprintf(stderr, "Cannot open file %s in %s:%d.\n", filename, __FILE__, __LINE__);
		return -1;
	}

	//peut etre creer une fonction convertResult2String() (ou un toString() de ResultObject)
	
	// A REMPLACER
	char text[] = "azertyuiop\n";
	for(int i = 0 ; i < 10 ; i++) {
		fputs(text, output);
	}
	// A REMPLACER

	fclose(output);
	return 0;
}

ResultObject::~ResultObject() {

}
