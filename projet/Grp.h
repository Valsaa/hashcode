#ifndef GRP_H
#define GRP_H

#include <iostream>
#include <cstdio>
#include <vector>
#include <list>

using namespace std;

class Grp
{
    public:
        Grp();
        virtual ~Grp();
        int calcul_distance_W(Warehouse* WH);

        Warehouse *_wh;
        vector<Command*> *cmd;

    private:
};

#endif // GRP_H
