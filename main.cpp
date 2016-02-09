#include "hashcode.h"

int main (int argc, char **argv) {

	if(argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))) {
		printf("Usage : ./hashcode.out [input filename] [output filename]\n");
		return -1;
	}
	
	DataObject *data = new DataObject();
	int status = data->readData(argc == 2 ? argv[1] : "dc.in");
	if(status < 0) {
		fprintf(stderr, "readInputFile return %d... expected 0 !\n", status);
		return -2;
	}	

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
	
	
	vector<Server> *serv;
	    serv->push_back( Server(10, 1, 0) );
	    serv->push_back( Server(10, 2, 1) );
	    serv->push_back( Server(10, 2, 1) );
	    serv->push_back( Server(10, 3, 0) );
	    serv->push_back( Server(8, 1, 0) );
	    serv->push_back( Server(6, 2, 0) );
	    serv->push_back( Server(6, 3, 0) );
	    serv->push_back( Server(2, 4, 0) );
	
	    cout << "trie: ";
	    for (vector<Server>::iterator it = serv->begin(); it != serv->end(); ++it)
	    {
	        cout << '=> ' <<  << ' - ' << ;
	    }
	

	return 0;
}

