#ifndef RESULTOBJECT_H
#define RESULTOBJECT_H

#include <iostream>
#include <cstdio>
#include <vector>
#include "dataobject.h"

using namespace std;

class ResultObject {

	public :
		char _text[NB_SERVERS][100];

		ResultObject(void);
		int writeResult(DataObject *, vector<Server> *, const char *);
		~ResultObject(void);

};

#endif // RESULTOBJECT_H
