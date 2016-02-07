#include "hashcode.h"

int main (int argc, char **argv) {

	if(argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))) {
		printf("Usage : ./hashcode.out [input filename] [output filename]\n");
		return -1;
	}
	
	DataStruct data;
	int status = readInputFile(argc == 2 ? argv[1] : "input.txt", &data);
	if(status < 0) {
		fprintf(stderr, "readInputFile return %d... expected 0 !\n", status);
		return -2;
	}	

	ResultStruct result;
	process(&data, &result);
	if(status < 0) {
		fprintf(stderr, "process return %d... expected 0 !\n", status);
		return -3;
	}	

	writeResultFile(argc == 3 ? argv[2] : "output.txt", &result);
	if(status < 0) {
		fprintf(stderr, "writeResultFile return %d... expected 0 !\n", status);
		return -4;
	}	

	return 0;
}

