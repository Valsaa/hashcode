#ifndef GRP_H
#define GRP_H

#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include "Warehouse.h"
#include "Command.h"

using namespace std;

class Grp
{
    public:
        Grp();
        virtual ~Grp();
        int calculB();

        Warehouse *_wh;
        vector<Command*> *_cmd;
        vector<Drone*> *_listDrone;

    private:
};

#endif // GRP_H
