#ifndef RESULTOBJECT_H
#define RESULTOBJECT_H

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <list>

using namespace std;

class ResultObject {

	public :
		ResultObject(void);
		int writeResult(const char *filename);
		~ResultObject(void);

		vector<string> *text;

};

#endif // RESULTOBJECT_H
