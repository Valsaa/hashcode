#include "dataobject.h"

DataObject::DataObject(void)
{
    _warehouse = new vector<Warehouse*>(NBWAREHOUSE);
    _drone = new vector<Drone*>(NBDRONE);
}

int DataObject::readData(const char *filename)
{

	FILE *input = fopen(filename, "r");
	if(input == NULL)
    {
		fprintf(stderr, "Cannot open file \"%s\" in %s:%d.\n", filename, __FILE__, __LINE__);
		return -1;
	}




	fclose(input);
	return 0;
}

void DataObject::debug(void) {

}

DataObject::~DataObject(void) {

}
