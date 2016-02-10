#ifndef RESULTOBJECT_H
#define RESULTOBJECT_H

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class ResultObject {

	public :
		ResultObject(void);
		int writeResult(const char *filename);
		~ResultObject(void);

};

#endif // RESULTOBJECT_H
