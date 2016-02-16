#include "resultobject.h"

ResultObject::ResultObject() {
	this->text = new vector<string>();
}

int ResultObject::writeResult(const char *filename) {
	FILE *output = fopen(filename, "w");
	if(output == NULL) {
		fprintf(stderr, "Cannot open file %s in %s:%d.\n", filename, __FILE__, __LINE__);
		return -1;
	}

	for(int i = 0 ; i < this->text->size() ; i++) {
		fprintf(output, "%s\n", this->text->at(i).c_str());
	}

	fclose(output);
	return 0;

}
	
ResultObject::~ResultObject() {
	 delete this->text;
}
