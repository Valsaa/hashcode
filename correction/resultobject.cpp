#include "resultobject.h"

ResultObject::ResultObject() {

}

int ResultObject::writeResult(const char *filename) {
	FILE *output = fopen(filename, "w");
	if(output == NULL) {
		fprintf(stderr, "Cannot open file %s in %s:%d.\n", filename, __FILE__, __LINE__);
		return -1;
	}

	fclose(output);
	return 0;
}

ResultObject::~ResultObject() {

}
