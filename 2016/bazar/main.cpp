#include "hashcode.h"

int main (int argc, char **argv) {

	if(argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))) {
		printf("Usage : ./hashcode.out [input filename] [output filename]\n");
		return -1;
	}

	DataObject *data = new DataObject();
	int status = data->readData(argc == 2 ? argv[1] : "busy_day.in");
	if(status < 0)
    {
		fprintf(stderr, "readInputFile return %d... expected 0 !\n", status);
		return -2;
	}

	groupOrder(data);
	data->Attrib_Grp_Wh();
	trierGroupWare(data);
	ResultObject *result = new ResultObject();
	process(data, result);
	if(status < 0) {
		fprintf(stderr, "process return %d... expected 0 !\n", status);
		return -3;
	}

	result->writeResult(argc == 3 ? argv[2] : "output.txt");
	if(status < 0) {
		fprintf(stderr, "writeResultFile return %d... expected 0 !\n", status);
		return -4;
	}

	delete data;
	delete result;

	return 0;
}

