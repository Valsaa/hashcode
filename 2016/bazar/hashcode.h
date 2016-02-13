#ifndef HASHCODE_H
#define HASHCODE_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

#include "dataobject.h"
#include "resultobject.h"

int process(const DataObject *data, ResultObject *result);

void groupOrder(DataObject *data);
void trierGroupWare(DataObject *data);

#endif // HASHCODE_H
