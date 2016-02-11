#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include "Drone.h"

using namespace std;

class Warehouse
{
    public:
        Warehouse(int px, int py, vector<int> nbProduct);
        virtual ~Warehouse();


        int _positionX;
        int _positionY;
        vector<Drone*> *_listDrone;
        vector<int*> *_nbProduct;

    private:
};

#endif // WAREHOUSE_H
