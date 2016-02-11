#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <iostream>
#include <cstdio>
#include <vector>
#include <list>

// constantes busy_day :
#define NBROW		400
#define NBCOL		600
#define NBDRONE		30
#define	DEADLINE	112993
#define MAXLOAD		200
#define NBPRODTYPE	400
#define NBWAREHOUSE	10
#define NBORDER		1250

/* constantes M_o_a_W :
#define NBROW		400
#define NBCOL		600
#define NBDRONE		30
#define	DEADLINE	112993
#define MAXLOAD		200
*/
/* constantes Red :
#define NBROW		400
#define NBCOL		600
#define NBDRONE		30
#define	DEADLINE	112993
#define MAXLOAD		200
*/

using namespace std;

class DataObject {

	public :
		DataObject(void);
		void debug(void);
		int readData(const char *filename);
		~DataObject(void);
};

#endif // DATAOBJECT_H
