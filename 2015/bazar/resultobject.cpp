#include "resultobject.h"

ResultObject::ResultObject() {

}

int ResultObject::writeResult(DataObject *data, vector<Server> *serv, const char *filename)
{
	FILE *output = fopen(filename, "w");
	if(output == NULL) {
		fprintf(stderr, "Cannot open file %s in %s:%d.\n", filename, __FILE__, __LINE__);
		return -1;
	}
	
	for(int i = 0 ; i < NB_SERVERS ; i++) {
		Server s = data->findServer(i);
		if(s._r != -1 && s._s != -1) {
			fprintf(output, "%d %d %d\n", s._r, s._s, s._pool);
		}
		else {
			fprintf(output, "x\n");
		}
	}

	fclose(output);
	return 0;
}

ResultObject::~ResultObject() {

}
