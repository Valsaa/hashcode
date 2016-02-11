#ifndef DATAOBJECT_H
#define DATAOBJECT_H

#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <list>
#include "Drone.h"
#include "Warehouse.h"
#include "Grp.h"
#include "Command.h"
#include "Grp.h"

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
		void Attrib_Grp_Wh(void);
		bool Check_Grp_Wh(Grp* groupe, Warehouse* WH);

		vector<Warehouse*> *_warehouse;
		vector<Drone*> *_drone;
		vector<Command*> *_listCmd;
		vector<Grp*> *_group;
};

#endif // DATAOBJECT_H
