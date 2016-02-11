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
        int calculB();

        Warehouse *_wh;
        vector<Command*> *cmd;

    private:
};

#endif // GRP_H
